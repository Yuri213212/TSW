/***
TSW remake v1.0
Copyright (C) 2019 Yuri213212
Site:https://github.com/Yuri213212/TSW
Email: yuri213212@vip.qq.com
License: CC BY-NC-SA 4.0
https://creativecommons.org/licenses/by-nc-sa/4.0/
***/

#define UNICODE
#define _UNICODE

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#ifdef LANG_EN
#include "lang_en/tsw_ui.h"
#include "lang_en/tsw_about.h"
#endif
#ifdef LANG_CH
#include "lang_ch/tsw_ui.h"
#include "lang_ch/tsw_about.h"
#endif
#include "wavelist.h"
#include "imagelist.h"
#include "icon.h"
#include "iconlist.h"
#include "cell.h"
#include "panel.h"
#include "map.ph"//need preprocess
#include "stair.h"

#define tbuflen 1024
#define clwidth 640
#define clheight 404
#define xoffset 144
#define yoffset 16

enum menuEnum{
	MENU_New=40000,
	MENU_Load,
	MENU_Save,
	MENU_Help,
#ifdef DEBUG
	MENU_Life,
	MENU_Attack,
	MENU_Defend,
	MENU_Gold,
	MENU_Key,
	MENU_Item,
#endif
};

wchar_t wbuf[tbuflen],fbuf[tbuflen],dbuf[tbuflen],statusbuf[tbuflen],dialogbuf[tbuflen];
HDC hdc,hdcMem;

#include "status.h"
#include "note.h"
#include "util.h"
#include "story.h"
#include "reaction.h"

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam){
	const RECT rectBg={0,0,clwidth,clheight};
#ifdef DEBUG
	static int colordata[16];
	static CHOOSECOLORW choosecolor={};
#endif
	static OPENFILENAMEW openfilename={};
	static TEXTMETRICW textmetric;
	static HBITMAP hBitmap;
	static HPEN hPenGray;
	static HBRUSH hBrushBg,hBrushGreen,hBrushGray,hBrushBrown;
	static HFONT hFont;
	static HRGN hRgn[16];
	static RECT rect;
	static int mx,my,lastrgn=-1;
	int i,j,temp,temp2;
	FILE *fp;

	switch (message){
	case WM_CREATE:
#ifdef DEBUG
		choosecolor.lStructSize=sizeof(CHOOSECOLOR);
		choosecolor.hwndOwner=hwnd;
		choosecolor.lpCustColors=(COLORREF *)colordata;
		choosecolor.Flags=CC_RGBINIT|CC_ANYCOLOR|CC_FULLOPEN|CC_PREVENTFULLOPEN;
#endif
		openfilename.lStructSize=sizeof(OPENFILENAMEW);
		openfilename.hwndOwner=hwnd;
		openfilename.lpstrFilter=L"SAV Files (*.sav)\0*.sav\0\0";
		openfilename.nFilterIndex=1;
		openfilename.lpstrFile=fbuf;
		openfilename.nMaxFile=tbuflen;
		openfilename.lpstrDefExt=L"sav";
		for (i=0;i<16;++i){
			hRgn[i]=CreateRectRgnIndirect(&item[i].rect);
		}
		hPenGray=CreatePen(PS_SOLID,1,RGB(160,160,160));
		hBrushGreen=CreateSolidBrush(RGB(0,255,0));
		hBrushGray=CreateSolidBrush(RGB(102,102,102));
		hBrushBrown=CreateSolidBrush(RGB(119,68,34));
		hdc=GetDC(NULL);
		hdcMem=CreateCompatibleDC(hdc);
		hBitmap=CreateCompatibleBitmap(hdc,clwidth,clheight);
		ReleaseDC(NULL,hdc);
		SelectObject(hdcMem,hBitmap);
		for (j=0;j<12;++j){
			for(i=0;i<4;++i){
				ico_draw(ico[ICO_Background],hdcMem,i*32,j*32);
			}
			for(i=16;i<20;++i){
				ico_draw(ico[ICO_Background],hdcMem,i*32,j*32);
			}
			ico_draw(ico[ICO_Wall],hdcMem,4*32,j*32);
			ico_draw(ico[ICO_Wall],hdcMem,15*32,j*32);
		}
		for(i=5;i<15;++i){
			ico_draw(ico[ICO_Wall],hdcMem,i*32,0*32);
			ico_draw(ico[ICO_Wall],hdcMem,i*32,11*32);
		}
		SelectObject(hdcMem,GetStockObject(NULL_PEN));
		SelectObject(hdcMem,hBrushBrown);
		Rectangle(hdcMem,xoffset-2,yoffset-2,11*32+xoffset+3,11*32+yoffset+3);
		for (j=0;j<11;++j){
			for(i=0;i<11;++i){
				ico_draw(ico[ICO_Road],hdcMem,i*32+xoffset,j*32+yoffset);
			}
		}
		SelectObject(hdcMem,hBrushGray);
		Rectangle(hdcMem,14,222,115,371);
		Rectangle(hdcMem,526,14,627,51);
		Rectangle(hdcMem,526,62,627,99);
		Rectangle(hdcMem,526,110,627,195);
		Rectangle(hdcMem,526,206,627,371);
		SelectObject(hdcMem,hPenGray);
		Rectangle(hdcMem,0,12*32,clwidth,clheight);
		Rectangle(hdcMem,16,16,112,36);
		Rectangle(hdcMem,16,48,112,68);
		Rectangle(hdcMem,36,80,112,100);
		Rectangle(hdcMem,36,112,112,132);
		Rectangle(hdcMem,36,144,112,164);
		Rectangle(hdcMem,36,176,112,196);
		ico_draw(ico[ICO_Life],hdcMem,16,80);
		ico_draw(ico[ICO_Attack],hdcMem,16,112);
		ico_draw(ico[ICO_Defend],hdcMem,16,144);
		ico_draw(ico[ICO_Gold],hdcMem,16,176);
		Rectangle(hdcMem,16,256,112,276);
		Rectangle(hdcMem,36,279,112,299);
		Rectangle(hdcMem,36,302,112,322);
		Rectangle(hdcMem,36,325,112,345);
		Rectangle(hdcMem,36,348,112,368);
		ico_draw(ico[ICO_LifeP],hdcMem,16,279);
		ico_draw(ico[ICO_AttackP],hdcMem,16,302);
		ico_draw(ico[ICO_DefendP],hdcMem,16,325);
		ico_draw(ico[ICO_GoldP],hdcMem,16,348);
		Rectangle(hdcMem,526,30,592,50);
		Rectangle(hdcMem,526,78,592,98);
		Rectangle(hdcMem,544,117,624,137);
		Rectangle(hdcMem,544,142,624,162);
		Rectangle(hdcMem,544,167,624,187);
		ico_draw(ico[ICO_RedKeyT],hdcMem,532,119);
		ico_draw(ico[ICO_BlueKeyT],hdcMem,532,144);
		ico_draw(ico[ICO_YellowKeyT],hdcMem,532,169);
		SelectObject(hdcMem,GetStockObject(SYSTEM_FIXED_FONT));
		GetTextMetricsW(hdcMem,&textmetric);
		hFont=NULL;
		if (textmetric.tmHeight!=16||textmetric.tmAveCharWidth!=8){
			//create 8*16 font when FixedSys is not 8*16
			//FixedSys in Japanese locale is 8*18
			hFont=CreateFontW(-16,-8,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,FIXED_PITCH,NULL);
			SelectObject(hdcMem,hFont);
		}
		SetBkMode(hdcMem,TRANSPARENT);
		SetTextColor(hdcMem,RGB(255,136,136));
		rect.left=526;
		rect.top=14;
		rect.right=592;
		rect.bottom=30;
		DrawTextW(hdcMem,szUI_Weapon,wcslen(szUI_Weapon),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		SetTextColor(hdcMem,RGB(204,204,255));
		rect.left=526;
		rect.top=62;
		rect.right=592;
		rect.bottom=79;
		DrawTextW(hdcMem,szUI_Armor,wcslen(szUI_Armor),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		hBrushBg=CreatePatternBrush(hBitmap);
		target=CT_Null;
		swprintf(statusbuf,szStatus_Intro);
		dialogY=-1;
		story=ST_Intro;
		autosave=0;
		SendMessage(hwnd,WM_APP,0,0);
		return 0;
	case WM_APP:
		if (autosave){
			st_save(autosave);
			autosave=0;
		}
		FillRect(hdcMem,&rectBg,hBrushBg);
		SetTextColor(hdcMem,RGB(255,255,255));
		rect.left=2;
		rect.top=386;
		rect.right=638;
		rect.bottom=402;
		DrawTextW(hdcMem,statusbuf,wcslen(statusbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_LEFT|DT_VCENTER);
		switch (story){
		case ST_Intro:
			drawImage(IM_Opening,hdcMem,0,0);
			rect.left=0;
			rect.top=0;
			rect.right=640;
			rect.bottom=384;
			DrawTextW(hdcMem,szScreen_Intro,wcslen(szScreen_Intro),&rect,DT_NOPREFIX|DT_TOP|DT_LEFT);
			DrawTextW(hdcMem,szScreen_PressEnter,wcslen(szScreen_PressEnter),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_BOTTOM);
			break;
		case ST_Title:
			SetTextColor(hdcMem,RGB(0,0,0));
			for (j=0;j<12;++j){
				for(i=0;i<20;++i){
					ico_draw(ico[ICO_Background],hdcMem,i*32,j*32);
				}
			}
			drawImage(IM_Logo,hdcMem,137,150);
			rect.left=0;
			rect.top=0;
			rect.right=640;
			rect.bottom=144;
			DrawTextW(hdcMem,szScreen_TitleU,wcslen(szScreen_TitleU),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=240;
			//rect.right=640;
			rect.bottom=384;
			DrawTextW(hdcMem,szScreen_TitleD,wcslen(szScreen_TitleD),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			break;
		case ST_Coma0:
			drawImage(IM_Coma,hdcMem,0,0);
			break;
		case ST_Coma1:
			drawImage(IM_Coma,hdcMem,0,0);
			rect.left=0;
			rect.top=136;
			rect.right=640;
			rect.bottom=152;
			DrawTextW(hdcMem,szScreen_Coma1,wcslen(szScreen_Coma1),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			break;
		case ST_Coma2:
			drawImage(IM_Coma,hdcMem,0,0);
			rect.left=0;
			rect.top=136;
			rect.right=640;
			rect.bottom=152;
			DrawTextW(hdcMem,szScreen_Coma1,wcslen(szScreen_Coma1),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=168;
			//rect.right=640;
			rect.bottom=184;
			DrawTextW(hdcMem,szScreen_Coma2,wcslen(szScreen_Coma2),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			break;
		case ST_Coma3:
			drawImage(IM_Coma,hdcMem,0,0);
			rect.left=0;
			rect.top=136;
			rect.right=640;
			rect.bottom=152;
			DrawTextW(hdcMem,szScreen_Coma1,wcslen(szScreen_Coma1),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=168;
			//rect.right=640;
			rect.bottom=184;
			DrawTextW(hdcMem,szScreen_Coma2,wcslen(szScreen_Coma2),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=200;
			//rect.right=640;
			rect.bottom=216;
			DrawTextW(hdcMem,szScreen_Coma3,wcslen(szScreen_Coma3),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			break;
		case ST_Coma4:
			drawImage(IM_Coma,hdcMem,0,0);
			rect.left=0;
			rect.top=136;
			rect.right=640;
			rect.bottom=152;
			DrawTextW(hdcMem,szScreen_Coma1,wcslen(szScreen_Coma1),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=168;
			//rect.right=640;
			rect.bottom=184;
			DrawTextW(hdcMem,szScreen_Coma2,wcslen(szScreen_Coma2),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=200;
			//rect.right=640;
			rect.bottom=216;
			DrawTextW(hdcMem,szScreen_Coma3,wcslen(szScreen_Coma3),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=0;
			rect.top=232;
			//rect.right=640;
			rect.bottom=248;
			DrawTextW(hdcMem,szScreen_Coma4,wcslen(szScreen_Coma4),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			break;
		case ST_Finale0:
			SelectObject(hdcMem,GetStockObject(NULL_PEN));
			SelectObject(hdcMem,GetStockObject(WHITE_BRUSH));
			Rectangle(hdcMem,0,0,641,385);
			break;
		case ST_Finale1:
			SelectObject(hdcMem,GetStockObject(NULL_PEN));
			SelectObject(hdcMem,GetStockObject(WHITE_BRUSH));
			Rectangle(hdcMem,0,0,641,385);
			SetTextColor(hdcMem,RGB(0,0,0));
			rect.left=0;
			rect.top=80;
			rect.right=640;
			rect.bottom=112;
			DrawTextW(hdcMem,szScreen_Finale1,wcslen(szScreen_Finale1),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			break;
		case ST_Finale2:
			SelectObject(hdcMem,GetStockObject(NULL_PEN));
			SelectObject(hdcMem,GetStockObject(WHITE_BRUSH));
			Rectangle(hdcMem,0,0,641,385);
			SetTextColor(hdcMem,RGB(0,0,0));
			rect.left=0;
			rect.top=80;
			rect.right=640;
			rect.bottom=112;
			DrawTextW(hdcMem,szScreen_Finale1,wcslen(szScreen_Finale1),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			//rect.left=0;
			rect.top=144;
			//rect.right=640;
			rect.bottom=176;
			DrawTextW(hdcMem,szScreen_Finale2,wcslen(szScreen_Finale2),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			break;
		case ST_Finale3:
			SelectObject(hdcMem,GetStockObject(NULL_PEN));
			SelectObject(hdcMem,GetStockObject(WHITE_BRUSH));
			Rectangle(hdcMem,0,0,641,385);
			SetTextColor(hdcMem,RGB(0,0,0));
			rect.left=0;
			rect.top=80;
			rect.right=640;
			rect.bottom=112;
			DrawTextW(hdcMem,szScreen_Finale1,wcslen(szScreen_Finale1),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			//rect.left=0;
			rect.top=144;
			//rect.right=640;
			rect.bottom=176;
			DrawTextW(hdcMem,szScreen_Finale2,wcslen(szScreen_Finale2),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			//rect.left=0;
			rect.top=208;
			//rect.right=640;
			rect.bottom=240;
			DrawTextW(hdcMem,szScreen_Finale3,wcslen(szScreen_Finale3),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			break;
		case ST_Finale4:
			SelectObject(hdcMem,GetStockObject(NULL_PEN));
			SelectObject(hdcMem,GetStockObject(WHITE_BRUSH));
			Rectangle(hdcMem,0,0,641,385);
			SetTextColor(hdcMem,RGB(0,0,0));
			rect.left=0;
			rect.top=80;
			rect.right=640;
			rect.bottom=112;
			DrawTextW(hdcMem,szScreen_Finale1,wcslen(szScreen_Finale1),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			//rect.left=0;
			rect.top=144;
			//rect.right=640;
			rect.bottom=176;
			DrawTextW(hdcMem,szScreen_Finale2,wcslen(szScreen_Finale2),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			//rect.left=0;
			rect.top=208;
			//rect.right=640;
			rect.bottom=240;
			DrawTextW(hdcMem,szScreen_Finale3,wcslen(szScreen_Finale3),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			//rect.left=0;
			rect.top=272;
			//rect.right=640;
			rect.bottom=304;
			DrawTextW(hdcMem,szScreen_Finale4,wcslen(szScreen_Finale4),&rect,DT_NOPREFIX|DT_TOP|DT_CENTER);
			break;
		case ST_TheEnd:
			drawImage(IM_End,hdcMem,0,0);
			rect.left=0;
			rect.top=0;
			rect.right=640;
			rect.bottom=384;
			DrawTextW(hdcMem,szScreen_Intro,wcslen(szScreen_Intro),&rect,DT_NOPREFIX|DT_TOP|DT_LEFT);
			DrawTextW(hdcMem,szScreen_TheEnd,wcslen(szScreen_TheEnd),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_BOTTOM);
			break;
		default:
			SetTextColor(hdcMem,RGB(255,255,255));
			rect.left=18;
			rect.top=18;
			rect.right=110;
			rect.bottom=34;
			swprintf(wbuf,szUI_Round,stmain.round);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			//rect.left=18;
			rect.top=50;
			//rect.right=110;
			rect.bottom=66;
			swprintf(wbuf,L"%s %d%s",szUI_Tower,stmain.floor,szUI_Floor);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			rect.left=38;
			rect.top=82;
			//rect.right=110;
			rect.bottom=98;
			swprintf(wbuf,L"%d",stmain.life);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			//rect.left=38;
			rect.top=114;
			//rect.right=110;
			rect.bottom=130;
			swprintf(wbuf,L"%d",stmain.attack);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			//rect.left=38;
			rect.top=146;
			//rect.right=110;
			rect.bottom=162;
			swprintf(wbuf,L"%d",stmain.defend);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			//rect.left=38;
			rect.top=178;
			//rect.right=110;
			rect.bottom=194;
			swprintf(wbuf,L"%d",stmain.gold);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			if (stmain.weapon>=0){
				rect.left=528;
				rect.top=32;
				rect.right=590;
				rect.bottom=48;
				swprintf(wbuf,L"%s",aszWeaponName[stmain.weapon]);
				DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			}
			if (stmain.armor>=0){
				rect.left=528;
				rect.top=80;
				rect.right=590;
				rect.bottom=96;
				swprintf(wbuf,L"%s",aszArmorName[stmain.armor]);
				DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			}
			rect.left=546;
			rect.top=119;
			rect.right=622;
			rect.bottom=135;
			swprintf(wbuf,L"%d",stmain.key[0]);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			//rect.left=546;
			rect.top=144;
			//rect.right=622;
			rect.bottom=160;
			swprintf(wbuf,L"%d",stmain.key[1]);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			//rect.left=546;
			rect.top=169;
			//rect.right=622;
			rect.bottom=185;
			swprintf(wbuf,L"%d",stmain.key[2]);
			DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
			if (target>CT_Null){
				rect.left=18;
				rect.top=258;
				rect.right=110;
				rect.bottom=274;
				swprintf(wbuf,L"%s",cell[target&CT_Mask].name);
				DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
				if (target&CT_Detail){
					rect.left=38;
					rect.top=281;
					rect.right=110;
					rect.bottom=297;
					swprintf(wbuf,L"%d",cell[target&CT_Mask].life);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					rect.left=38;
					rect.top=304;
					rect.right=110;
					rect.bottom=320;
					swprintf(wbuf,L"%d",cell[target&CT_Mask].attack);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					rect.left=38;
					rect.top=327;
					rect.right=110;
					rect.bottom=343;
					swprintf(wbuf,L"%d",cell[target&CT_Mask].defend);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					rect.left=38;
					rect.top=350;
					rect.right=110;
					rect.bottom=366;
					swprintf(wbuf,L"%d",cell[target&CT_Mask].gold);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
				}
				SetTextColor(hdcMem,RGB(0,0,0));
				ico_draw(ico[cell[target&CT_Mask].imageP],hdcMem,48,224);
			}
			SetTextColor(hdcMem,RGB(0,0,0));
			if (stmain.weapon>=0){
				ico_draw(ico[ICO_IronSwordP+stmain.weapon],hdcMem,592,16);
			}
			if (stmain.armor>=0){
				ico_draw(ico[ICO_IronShieldP+stmain.armor],hdcMem,592,64);
			}
			for (i=0;i<itemCount;++i){
				if (stmain.item[i]&&item[i].image>ICO_Null){
					ico_draw(ico[item[i].image],hdcMem,item[i].rect.left,item[i].rect.top);
				}
				if (stmain.item[i]>1){
					swprintf(wbuf,L"%d",stmain.item[i]);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),(LPRECT)&item[i].rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_BOTTOM);
				}
			}
			switch (story){
			case ST_Load:
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,hBrushGray);
				Rectangle(hdcMem,4*32,0*32,16*32+1,12*32+1);
				SetTextColor(hdcMem,RGB(255,255,255));
				rect.left=4*32;
				rect.top=0*32;
				rect.right=16*32;
				rect.bottom=3*32;
				DrawTextW(hdcMem,szScreen_Load,wcslen(szScreen_Load),&rect,DT_NOPREFIX|DT_CENTER);
				SetTextColor(hdcMem,RGB(0,0,0));
				SelectObject(hdcMem,GetStockObject(WHITE_BRUSH));
				for(j=0;j<3;++j){
					for (i=0;i<3;++i){
						Rectangle(hdcMem,4*i*32+xoffset-2,(3*j+3)*32+yoffset-2,(4*i+3)*32+xoffset+3,(3*j+5)*32+yoffset+3);
						rect.left=4*i*32+xoffset;
						rect.top=(3*j+3)*32+yoffset;
						rect.right=(4*i+3)*32+xoffset;
						rect.bottom=(3*j+5)*32+yoffset;
						temp=j*3+i;
						if (saveFloor[temp]<0||saveFloor[temp]==stsave[temp].floor){
							swprintf(wbuf,szScreen_LoadStatus,temp+1,stsave[temp].floor,stsave[temp].round,stsave[temp].life,stsave[temp].attack,stsave[temp].defend);
							DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_LEFT);
						}else{
							DrawTextW(hdcMem,szScreen_LoadNull,wcslen(szScreen_LoadNull),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
						}
					}
				}
				break;
			case ST_Book:
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,hBrushGray);
				Rectangle(hdcMem,4*32,0*32,16*32+1,12*32+1);
				SetTextColor(hdcMem,RGB(255,255,255));
				rect.left=4*32;
				rect.top=0*32;
				rect.right=16*32;
				rect.bottom=1*32;
				DrawTextW(hdcMem,szScreen_Book,wcslen(szScreen_Book),&rect,DT_NOPREFIX|DT_CENTER);
				for (i=0;i<11;++i){
					if (enemies[i]==CT_Null) break;
					SelectObject(hdcMem,hPenGray);
					MoveToEx(hdcMem,4*32,(i+1)*32,NULL);
					LineTo(hdcMem,16*32,(i+1)*32);
					SetTextColor(hdcMem,RGB(0,0,0));
					ico_draw(ico[ICO_Road],hdcMem,4*32,(i+1)*32);
					ico_draw(ico[cell[enemies[i]].image],hdcMem,4*32,(i+1)*32);
					ico_draw(ico[ICO_LifeT],hdcMem,5*32,(i+1)*32+16);
					ico_draw(ico[ICO_AttackT],hdcMem,5*32+88,(i+1)*32+16);
					ico_draw(ico[ICO_DefendT],hdcMem,5*32+176,(i+1)*32+16);
					ico_draw(ico[ICO_GoldT],hdcMem,5*32+264,(i+1)*32+16);
					ico_draw(ico[ICO_DamageT],hdcMem,5*32+176,(i+1)*32);
					SetTextColor(hdcMem,RGB(255,255,255));
					rect.left=5*32+16;
					rect.top=(i+1)*32+16;
					rect.right=5*32+88;
					rect.bottom=(i+2)*32;
					swprintf(wbuf,L"%d",cell[enemies[i]].life);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					rect.left=5*32+104;
					//rect.top=(i+1)*32+16;
					rect.right=5*32+176;
					//rect.bottom=(i+2)*32;
					swprintf(wbuf,L"%d",cell[enemies[i]].attack);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					rect.left=5*32+192;
					//rect.top=(i+1)*32+16;
					rect.right=5*32+264;
					//rect.bottom=(i+2)*32;
					swprintf(wbuf,L"%d",cell[enemies[i]].defend);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					rect.left=5*32+280;
					//rect.top=(i+1)*32+16;
					rect.right=5*32+352;
					//rect.bottom=(i+2)*32;
					swprintf(wbuf,L"%d",cell[enemies[i]].gold);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					SetTextColor(hdcMem,RGB(255,255,255));
					rect.left=5*32;
					rect.top=(i+1)*32;
					rect.right=5*32+176;
					rect.bottom=(i+1)*32+16;
					DrawTextW(hdcMem,cell[enemies[i]].name,wcslen(cell[enemies[i]].name),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_LEFT|DT_VCENTER);
					rect.left=5*32+192;
					//rect.top=(i+1)*32;
					rect.right=5*32+352;
					//rect.bottom=(i+1)*32+16;
					temp=predictTotalDamage(enemies[i]);
					if (temp<0){
						SetTextColor(hdcMem,RGB(255,0,255));
						DrawTextW(hdcMem,szScreen_StrongEnemy,wcslen(szScreen_StrongEnemy),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					}else{
						if (!temp){
							SetTextColor(hdcMem,RGB(0,255,0));
						}else if (temp<stmain.life){
							SetTextColor(hdcMem,RGB(255,255,0));
						}else{
							SetTextColor(hdcMem,RGB(255,0,0));
						}
						swprintf(wbuf,L"%d",temp);
						DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
					}
				}
				break;
			case ST_Note:
				temp=getNoteIndex();
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,hBrushGray);
				Rectangle(hdcMem,4*32,0*32,16*32+1,12*32+1);
				SetTextColor(hdcMem,RGB(255,255,255));
				rect.left=4*32;
				rect.top=0*32;
				rect.right=16*32;
				rect.bottom=1*32;
				DrawTextW(hdcMem,szScreen_Note,wcslen(szScreen_Note),&rect,DT_NOPREFIX|DT_CENTER);
				//rect.left=4*32;
				rect.top=2*32;
				//rect.right=16*32;
				rect.bottom=2*32+16;
				DrawTextW(hdcMem,L"<",1,&rect,DT_NOPREFIX|DT_SINGLELINE|DT_LEFT|DT_VCENTER);
				DrawTextW(hdcMem,L">",1,&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
				swprintf(wbuf,L"%d/%d",getPageNo(),getPageLen());
				DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
				//rect.left=4*32;
				rect.top=2*32+16;
				//rect.right=16*32;
				rect.bottom=3*32;
				DrawTextW(hdcMem,L"Home",4,&rect,DT_NOPREFIX|DT_SINGLELINE|DT_LEFT|DT_VCENTER);
				DrawTextW(hdcMem,L"End",3,&rect,DT_NOPREFIX|DT_SINGLELINE|DT_RIGHT|DT_VCENTER);
				swprintf(wbuf,L"#%d",temp);
				DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
				if (temp){
					//rect.left=4*32;
					rect.top=3*32+16;
					//rect.right=16*32;
					rect.bottom=4*32;
					swprintf(wbuf,L"%d%s",notes[temp].floor,szUI_Floor);
					DrawTextW(hdcMem,wbuf,wcslen(wbuf),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
					//rect.left=4*32;
					rect.top=5*32;
					//rect.right=16*32;
					rect.bottom=5*32+16;
					DrawTextW(hdcMem,cell[notes[temp].target].name,wcslen(cell[notes[temp].target].name),&rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
					SetTextColor(hdcMem,RGB(0,0,0));
					ico_draw(ico[ICO_Road],hdcMem,9*32+16,4*32);
					ico_draw(ico[cell[notes[temp].target].image],hdcMem,9*32+16,4*32);
				}
				break;
			case ST_Wake1:
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,GetStockObject(GRAY_BRUSH));
				Rectangle(hdcMem,xoffset+0*32,yoffset+0*32,xoffset+11*32+1,yoffset+11*32+1);
				break;
			case ST_Wake2:
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,GetStockObject(GRAY_BRUSH));
				Rectangle(hdcMem,xoffset+0*32,yoffset+0*32,xoffset+11*32+1,yoffset+11*32+1);
				break;
			case ST_Wake3:
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,GetStockObject(GRAY_BRUSH));
				Rectangle(hdcMem,xoffset+0*32,yoffset+0*32,xoffset+11*32+1,yoffset+11*32+1);
				break;
			case ST_Wake4:
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,GetStockObject(GRAY_BRUSH));
				Rectangle(hdcMem,xoffset+0*32,yoffset+0*32,xoffset+11*32+1,yoffset+11*32+1);
				break;
			default:
				SetTextColor(hdcMem,RGB(0,0,0));
				for (j=0;j<11;++j){
					for (i=0;i<11;++i){
						if (stmain.map[stmain.floor][j][i]>CT_Null){
							if (stmain.map[stmain.floor][j][i]&CT_Explode){
								ico_draw(ico[ICO_Explosion],hdcMem,i*32+xoffset,j*32+yoffset);
							}else{
								ico_draw(ico[cell[stmain.map[stmain.floor][j][i]].image],hdcMem,i*32+xoffset,j*32+yoffset);
							}
						}
					}
				}
				if (stmain.life>0){
					ico_draw(ico[ICO_BraveMan],hdcMem,stmain.x*32+xoffset,stmain.y*32+yoffset);
				}else{
					ico_draw(ico[ICO_Explosion],hdcMem,stmain.x*32+xoffset,stmain.y*32+yoffset);
				}
			}
			if (dialogY>=0){
				SelectObject(hdcMem,GetStockObject(NULL_PEN));
				SelectObject(hdcMem,GetStockObject(LTGRAY_BRUSH));
				Rectangle(hdcMem,4*32,dialogY*32,16*32+1,(dialogY+5)*32+1);
				SetTextColor(hdcMem,RGB(0,0,0));
				rect.left=4*32;
				rect.top=dialogY*32;
				rect.right=16*32;
				rect.bottom=(dialogY+5)*32;
				DrawTextW(hdcMem,dialogbuf,wcslen(dialogbuf),&rect,DT_NOPREFIX|DT_LEFT);
			}
			if (!story){
				SelectObject(hdcMem,hBrushGreen);
				for (i=0;i<16;++i){
					if (stmain.item[i]&&item[i].key[0]&&PtInRegion(hRgn[i],mx,my)){
						PaintRgn(hdcMem,hRgn[i]);
						DrawTextW(hdcMem,item[i].key,wcslen(item[i].key),(LPRECT)&item[i].rect,DT_NOPREFIX|DT_SINGLELINE|DT_CENTER|DT_VCENTER);
						break;
					}
				}
			}
		}
		InvalidateRect(hwnd,NULL,FALSE);
		return 0;
	case WM_ERASEBKGND:
		return TRUE;
	case WM_PAINT:
		hdc=GetDC(hwnd);
		BitBlt(hdc,0,0,clwidth,clheight,hdcMem,0,0,SRCCOPY);
		ReleaseDC(hwnd,hdc);
		ValidateRect(hwnd,NULL);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam)){
		case MENU_New:
			if (MessageBoxW(hwnd,szQuestion_NewGameConfirm,szTitle,MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2)==IDYES){
				newGame();
				target=CT_Null;
				dialogY=-1;
				story=0;
				swprintf(statusbuf,szStatus_NewGame);
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case MENU_Load:
			setDefLoadFileName();
			if (GetOpenFileNameW(&openfilename)){
				if (!(fp=_wfopen(fbuf,L"rb"))){
					swprintf(wbuf,szErr_OpenFile,fbuf);
					MessageBoxW(hwnd,wbuf,szTitle,MB_ICONERROR);
					return 0;
				}
				loadGame(fp);
				fclose(fp);
				target=CT_Null;
				dialogY=-1;
				story=0;
				swprintf(statusbuf,szStatus_LoadFile);
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case MENU_Save:
			if (story){
				MessageBoxW(hwnd,szErr_Save,szTitle,MB_ICONERROR);
				return 0;
			}
			setDefSaveFileName();
			if (GetSaveFileNameW(&openfilename)){
				if (!(fp=_wfopen(fbuf,L"wb"))){
					swprintf(wbuf,szErr_OpenFile,fbuf);
					MessageBoxW(hwnd,wbuf,szTitle,MB_ICONERROR);
					return 0;
				}
				saveGame(fp);
				fclose(fp);
				target=CT_Null;
				swprintf(statusbuf,szStatus_SaveFile);
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case MENU_Help:
			MessageBoxW(hwnd,szHelp,szTitle,MB_ICONINFORMATION);
			return 0;
#ifdef DEBUG
		case MENU_Life:
			choosecolor.rgbResult=stmain.life;
			for (i=0;i<16;++i){
				colordata[i]=i*1000;
			}
			ChooseColorW(&choosecolor);
			stmain.life=choosecolor.rgbResult;
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		case MENU_Attack:
			choosecolor.rgbResult=stmain.attack;
			for (i=0;i<16;++i){
				colordata[i]=i*50;
			}
			ChooseColorW(&choosecolor);
			stmain.attack=choosecolor.rgbResult;
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		case MENU_Defend:
			choosecolor.rgbResult=stmain.defend;
			for (i=0;i<16;++i){
				colordata[i]=i*50;
			}
			ChooseColorW(&choosecolor);
			stmain.defend=choosecolor.rgbResult;
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		case MENU_Gold:
			choosecolor.rgbResult=stmain.gold;
			for (i=0;i<16;++i){
				colordata[i]=i*1000;
			}
			ChooseColorW(&choosecolor);
			stmain.gold=choosecolor.rgbResult;
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		case MENU_Key:
			choosecolor.rgbResult=0;
			for (i=0;i<16;++i){
				colordata[i]=i;
			}
			ChooseColorW(&choosecolor);
			for (i=0;i<3;++i){
				stmain.key[i]=choosecolor.rgbResult;
			}
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		case MENU_Item:
			choosecolor.rgbResult=0;
			for (i=0;i<16;++i){
				colordata[i]=i;
			}
			ChooseColorW(&choosecolor);
			for (i=0;i<itemCount;++i){
				stmain.item[i]=choosecolor.rgbResult;
			}
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
#endif
		default:
			;
		}
		break;
	case WM_KEYDOWN:
		switch (wParam){
		case VK_RETURN://Enter
			if (storyProgress()){
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case VK_HOME:
			if (storyChoice(-2)){
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case VK_END:
			if (storyChoice(-1)){
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case VK_ESCAPE://Esc
			if (storyChoice(0)){
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (storyChoice(wParam-'0')){
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case VK_NUMPAD1:
		case VK_NUMPAD2:
		case VK_NUMPAD3:
		case VK_NUMPAD4:
		case VK_NUMPAD5:
		case VK_NUMPAD6:
		case VK_NUMPAD7:
		case VK_NUMPAD8:
		case VK_NUMPAD9:
			if (storyChoice(wParam-VK_NUMPAD0)){
				SendMessage(hwnd,WM_APP,0,0);
			}
			return 0;
		case 'R'://reset
			st_reset(&stmain);
			target=CT_Null;
			dialogY=-1;
			story=ST_Null;
			swprintf(statusbuf,szStatus_Reset);
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		}
		if (story>ST_Null) return 0;
		if (wParam=='L'){//quick load
			story=ST_Load;
			SendMessage(hwnd,WM_APP,0,0);
			return 0;
		}
		if (stmain.life<=0) return 0;
		switch (wParam){
		case VK_UP:
			if (stmain.y>0){
				if (touch(stmain.x,stmain.y-1)){
					--stmain.y;
					enter(1);
				}else{
					enter(0);
				}
				SendMessage(hwnd,WM_APP,0,0);
			}
			break;
		case VK_DOWN:
			if (stmain.y<10){
				if (touch(stmain.x,stmain.y+1)){
					++stmain.y;
					enter(1);
				}else{
					enter(0);
				}
				SendMessage(hwnd,WM_APP,0,0);
			}
			break;
		case VK_LEFT:
			if (stmain.x>0){
				if (touch(stmain.x-1,stmain.y)){
					--stmain.x;
					enter(1);
				}else{
					enter(0);
				}
				SendMessage(hwnd,WM_APP,0,0);
			}
			break;
		case VK_RIGHT:
			if (stmain.x<10){
				if (touch(stmain.x+1,stmain.y)){
					++stmain.x;
					enter(1);
				}else{
					enter(0);
				}
				SendMessage(hwnd,WM_APP,0,0);
			}
			break;
#ifdef DEBUG
		case VK_INSERT:
			if (stmain.floor<50){
				++stmain.floor;
				stmain.x=stairPosition[stmain.floor][SP_upX];
				stmain.y=stairPosition[stmain.floor][SP_upY];
				if (stmain.floor>stmain.maxfloor){
					stmain.maxfloor=stmain.floor;
				}
			}
			break;
		case VK_DELETE:
			if (stmain.floor>0){
				--stmain.floor;
				stmain.x=stairPosition[stmain.floor][SP_downX];
				stmain.y=stairPosition[stmain.floor][SP_downY];
				if (stmain.floor<stmain.minfloor){
					stmain.minfloor=stmain.floor;
				}
			}
			break;
#endif
		case VK_PRIOR://Page Up
			if (stmain.item[IT_OrbOfFlying]<=0) return 0;
			target=CT_OrbOfFlying;
			if (!isNearStair()){
				swprintf(statusbuf,szStatus_OrbOfFlyingForbidden);
			}else if (stmain.floor<49&&stmain.floor<stmain.maxfloor){
				goUpStair();
				swprintf(statusbuf,szStatus_OrbOfFlyingUsed);
				enter(0);
			}else{
				swprintf(statusbuf,szStatus_OrbOfFlyingFailH);
			}
			break;
		case VK_NEXT://Page Down
			if (stmain.item[IT_OrbOfFlying]<=0) return 0;
			target=CT_OrbOfFlying;
			if (!isNearStair()){
				swprintf(statusbuf,szStatus_OrbOfFlyingForbidden);
			}else if (stmain.floor>1&&stmain.floor>stmain.minfloor){
				goDownStair();
				swprintf(statusbuf,szStatus_OrbOfFlyingUsed);
				enter(0);
			}else{
				swprintf(statusbuf,szStatus_OrbOfFlyingFailL);
			}
			break;
		case 'S'://quick save
			target=CT_Null;
			if (stmain.item[IT_OrbOfHero]>0){
				st_save(SS_Quick);
				swprintf(statusbuf,szStatus_Save);
			}else{
				swprintf(statusbuf,szStatus_SaveForbidden);
			}
			SendMessage(hwnd,WM_APP,0,0);
			break;
		case 'H'://OrbOfHero
			if (stmain.item[IT_OrbOfHero]<=0) return 0;
			setEnemies();
			story=ST_Book;
			SendMessage(hwnd,WM_APP,0,0);
			break;
		case 'N'://OrbOfWisdom
			if (stmain.item[IT_OrbOfWisdom]<=0) return 0;
			cnote=-stmain.notes&stmain.notes;
			dialogY=6;
			swprintf(dialogbuf,notes[getNoteIndex()].dialog);
			story=ST_Note;
			SendMessage(hwnd,WM_APP,0,0);
			break;
		case 'W'://MagicElixir
			if (stmain.item[IT_MagicElixir]<=0) return 0;
			target=CT_MagicElixir;
			--stmain.item[IT_MagicElixir];
			temp=stmain.attack*10+stmain.defend*5;
			stmain.life+=temp;
			swprintf(statusbuf,szStatus_MagicElixirUsed,temp);
			break;
		case 'P'://MagicMattock
			if (stmain.item[IT_MagicMattock]<=0) return 0;
			target=CT_MagicMattock;
			--stmain.item[IT_MagicMattock];
			temp=0;
			if (stmain.y>0){
				temp2=stmain.map[stmain.floor][stmain.y-1][stmain.x];
				if (temp2==CT_Wall){
					stmain.map[stmain.floor][stmain.y-1][stmain.x]=CT_Null;
					temp=1;
				}
			}
			if (stmain.y<10){
				temp2=stmain.map[stmain.floor][stmain.y+1][stmain.x];
				if (temp2==CT_Wall){
					stmain.map[stmain.floor][stmain.y+1][stmain.x]=CT_Null;
					temp=1;
				}
			}
			if (stmain.x>0){
				temp2=stmain.map[stmain.floor][stmain.y][stmain.x-1];
				if (temp2==CT_Wall){
					stmain.map[stmain.floor][stmain.y][stmain.x-1]=CT_Null;
					temp=1;
				}
			}
			if (stmain.x<10){
				temp2=stmain.map[stmain.floor][stmain.y][stmain.x+1];
				if (temp2==CT_Wall){
					stmain.map[stmain.floor][stmain.y][stmain.x+1]=CT_Null;
					temp=1;
				}
			}
			swprintf(statusbuf,szStatus_MagicMattockUsed);
			if (temp){
				playSound(WAV_Open);
			}
			break;
		case 'B'://DestructibleBall
			if (stmain.item[IT_DestructibleBall]<=0) return 0;
			target=CT_DestructibleBall;
			--stmain.item[IT_DestructibleBall];
			temp=0;
			if (stmain.y>0){
				temp2=stmain.map[stmain.floor][stmain.y-1][stmain.x];
				if (temp2>CT_Null&&(cell[temp2].flag&CF_Bombable)){
					temp+=killMonster(stmain.x,stmain.y-1);
				}
			}
			if (stmain.y<10){
				temp2=stmain.map[stmain.floor][stmain.y+1][stmain.x];
				if (temp2>CT_Null&&(cell[temp2].flag&CF_Bombable)){
					temp+=killMonster(stmain.x,stmain.y+1);
				}
			}
			if (stmain.x>0){
				temp2=stmain.map[stmain.floor][stmain.y][stmain.x-1];
				if (temp2>CT_Null&&(cell[temp2].flag&CF_Bombable)){
					temp+=killMonster(stmain.x-1,stmain.y);
				}
			}
			if (stmain.x<10){
				temp2=stmain.map[stmain.floor][stmain.y][stmain.x+1];
				if (temp2>CT_Null&&(cell[temp2].flag&CF_Bombable)){
					temp+=killMonster(stmain.x+1,stmain.y);
				}
			}
			swprintf(statusbuf,szStatus_DestructibleBallUsed,temp);
			if (temp){
				playSound(WAV_MagicAttack);
			}
			break;
		case 'J'://WarpStaff
			if (stmain.item[IT_WarpStaff]<=0) return 0;
			target=CT_WarpStaff;
			if (stmain.map[stmain.floor][10-stmain.y][10-stmain.x]==CT_Null){
				--stmain.item[IT_WarpStaff];
				stmain.x=10-stmain.x;
				stmain.y=10-stmain.y;
				swprintf(statusbuf,szStatus_WarpStaffUsed);
			}else{
				swprintf(statusbuf,szStatus_WarpStaffFail);
			}
			break;
		case 'U'://WingsToFlyUp
			if (stmain.item[IT_WingsToFlyUp]<=0) return 0;
			target=CT_WingsToFlyUp;
			if (stmain.floor<50&&stmain.map[stmain.floor+1][stmain.y][stmain.x]==CT_Null){
				--stmain.item[IT_WingsToFlyUp];
				++stmain.floor;
				if (stmain.floor>stmain.maxfloor){
					stmain.maxfloor=stmain.floor;
				}
				swprintf(statusbuf,szStatus_WingsToFlyUpUsed);
			}else{
				swprintf(statusbuf,szStatus_WingsToFlyUpFail);
			}
			break;
		case 'D'://WingsToFlyDown
			if (stmain.item[IT_WingsToFlyDown]<=0) return 0;
			target=CT_WingsToFlyDown;
			if (stmain.floor>0&&stmain.map[stmain.floor-1][stmain.y][stmain.x]==CT_Null){
				--stmain.item[IT_WingsToFlyDown];
				--stmain.floor;
				if (stmain.floor<stmain.minfloor){
					stmain.minfloor=stmain.floor;
				}
				swprintf(statusbuf,szStatus_WingsToFlyDownUsed);
			}else{
				swprintf(statusbuf,szStatus_WingsToFlyDownFail);
			}
			break;
		case 'I'://SnowCrystal
			if (stmain.item[IT_SnowCrystal]<=0) return 0;
			temp=0;
			if (stmain.y>0){
				temp2=stmain.map[stmain.floor][stmain.y-1][stmain.x];
				if (temp2==CT_Lava){
					temp=1;
				}
			}
			if (stmain.y<10){
				temp2=stmain.map[stmain.floor][stmain.y+1][stmain.x];
				if (temp2==CT_Lava){
					temp=1;
				}
			}
			if (stmain.x>0){
				temp2=stmain.map[stmain.floor][stmain.y][stmain.x-1];
				if (temp2==CT_Lava){
					temp=1;
				}
			}
			if (stmain.x<10){
				temp2=stmain.map[stmain.floor][stmain.y][stmain.x+1];
				if (temp2==CT_Wall){
					temp=1;
				}
			}
			if (!temp) return 0;
			target=CT_SnowCrystal;
			for (j=0;j<11;++j){
				for(i=0;i<11;++i){
					if (stmain.map[stmain.floor][j][i]==CT_Lava){
						stmain.map[stmain.floor][j][i]=CT_Null;
					}
				}
			}
			swprintf(statusbuf,szStatus_SnowCrystalUsed);
			break;
		case 'K'://MagicKey
			if (stmain.item[IT_MagicKey]<=0) return 0;
			target=CT_MagicKey;
			--stmain.item[IT_MagicKey];
			temp=0;
			for (j=0;j<11;++j){
				for(i=0;i<11;++i){
					if (stmain.map[stmain.floor][j][i]==CT_YellowDoor){
						stmain.map[stmain.floor][j][i]=CT_Null;
						temp=1;
					}
				}
			}
			swprintf(statusbuf,szStatus_MagicKeyUsed);
			if (temp){
				playSound(WAV_Open);
			}
			break;
		case 'Q'://SuperMagicMattock
			if (stmain.item[IT_SuperMagicMattock]<=0) return 0;
			target=CT_SuperMagicMattock;
			--stmain.item[IT_SuperMagicMattock];
			temp=0;
			for (j=0;j<11;++j){
				for(i=0;i<11;++i){
					if (stmain.map[stmain.floor][j][i]==CT_Wall){
						stmain.map[stmain.floor][j][i]=CT_Null;
						temp=1;
					}
				}
			}
			swprintf(statusbuf,szStatus_SuperMagicMattockUsed);
			if (temp){
				playSound(WAV_Open);
			}
			break;
		default:
			return 0;
		}
		SendMessage(hwnd,WM_APP,0,0);
		return 0;
	case WM_MOUSEMOVE:
		mx=LOWORD(lParam);
		my=HIWORD(lParam);
		temp=0;
		if (lastrgn>=0){
			if (!PtInRegion(hRgn[lastrgn],mx,my)){
				temp=1;
				lastrgn=-1;
				ReleaseCapture();
			}
		}
		if (lastrgn<0){
			for (i=0;i<16;++i){
				if (item[i].key[0]&&PtInRegion(hRgn[i],mx,my)){
					temp=1;
					lastrgn=i;
					SetCapture(hwnd);
					break;
				}
			}
		}
		if (temp){
			PostMessage(hwnd,WM_APP,0,0);
		}
		return 0;
	case WM_LBUTTONDOWN:
		if (story) return 0;
		if (lastrgn<0||!stmain.item[lastrgn]) return 0;
		switch (lastrgn){
		case IT_OrbOfHero:
			SendMessage(hwnd,WM_KEYDOWN,'H',0);
			return 0;
		case IT_OrbOfWisdom:
			SendMessage(hwnd,WM_KEYDOWN,'N',0);
			return 0;
		case IT_OrbOfFlying:
			SendMessage(hwnd,WM_KEYDOWN,VK_PRIOR,0);
			return 0;
		case IT_OrbOfFlying2:
			SendMessage(hwnd,WM_KEYDOWN,VK_NEXT,0);
			return 0;
		case IT_MagicElixir:
			SendMessage(hwnd,WM_KEYDOWN,'W',0);
			return 0;
		case IT_MagicMattock:
			SendMessage(hwnd,WM_KEYDOWN,'P',0);
			return 0;
		case IT_DestructibleBall:
			SendMessage(hwnd,WM_KEYDOWN,'B',0);
			return 0;
		case IT_WarpStaff:
			SendMessage(hwnd,WM_KEYDOWN,'J',0);
			return 0;
		case IT_WingsToFlyUp:
			SendMessage(hwnd,WM_KEYDOWN,'U',0);
			return 0;
		case IT_WingsToFlyDown:
			SendMessage(hwnd,WM_KEYDOWN,'D',0);
			return 0;
		case IT_SnowCrystal:
			SendMessage(hwnd,WM_KEYDOWN,'I',0);
			return 0;
		case IT_MagicKey:
			SendMessage(hwnd,WM_KEYDOWN,'K',0);
			return 0;
		case IT_SuperMagicMattock:
			SendMessage(hwnd,WM_KEYDOWN,'Q',0);
			return 0;
		default:
			return 0;
		}
	case WM_DESTROY:
		for (i=0;i<16;++i){
			DeleteObject(hRgn[i]);
		}
		DeleteObject(hPenGray);
		DeleteObject(hBrushGreen);
		DeleteObject(hBrushGray);
		DeleteObject(hBrushBrown);
		DeleteObject(hBrushBg);
		if (hFont){
			DeleteObject(hFont);
		}
		DeleteDC(hdcMem);
		DeleteObject(hBitmap);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}

int main(){
	static int argc;
	static WCHAR **argv;
	static HINSTANCE hInstance;
	static int iCmdShow;
	static STARTUPINFOW si;
	static WCHAR wbuf[tbuflen];
	WNDCLASSW wndclass;
	HICON hIcon;
	HMENU hMenu;
#ifdef DEBUG
	HMENU hMenuP;
#endif
	HWND hwnd;
	MSG msg;
	int cxScreen,cyScreen,width,height,i;
	wchar_t *errmsg;

	argv=CommandLineToArgvW(GetCommandLineW(),&argc);
	hInstance=GetModuleHandleW(NULL);
	GetStartupInfoW(&si);
	iCmdShow=si.dwFlags&STARTF_USESHOWWINDOW?si.wShowWindow:SW_SHOWNORMAL;
	GetModuleFileNameW(NULL,dbuf,tbuflen);
	dbuf[tbuflen-1]=0;
	for (i=wcslen(dbuf)-1;dbuf[i]!='\\'&&i>=0;--i){
		dbuf[i]=0;
	}
	SetCurrentDirectoryW(dbuf);
	hIcon=LoadImageW(NULL,L"./res/TSW.ico",IMAGE_ICON,0,0,LR_LOADFROMFILE);
	if (!hIcon){
		swprintf(wbuf,szErr_OpenFile,L"./res/TSW.ico");
		MessageBoxW(NULL,wbuf,argv[0],MB_ICONERROR);
		return 0;
	}
	wndclass.style=CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc=WndProc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=hIcon;
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=NULL;
	wndclass.lpszMenuName=szAppName;
	wndclass.lpszClassName=szAppName;
	if (!RegisterClassW(&wndclass)){
		MessageBoxW(NULL,szErr_RegisterClass,argv[0],MB_ICONERROR);
		DestroyIcon(hIcon);
		return 0;
	}
	errmsg=loadIcons();
	if (errmsg){
		swprintf(wbuf,szErr_OpenFile,errmsg);
		MessageBoxW(NULL,wbuf,argv[0],MB_ICONERROR);
		DestroyIcon(hIcon);
		return 0;
	}
	errmsg=loadImages();
	if (errmsg){
		swprintf(wbuf,szErr_OpenFile,errmsg);
		MessageBoxW(NULL,wbuf,argv[0],MB_ICONERROR);
		destroyIcons();
		DestroyIcon(hIcon);
		return 0;
	}
	errmsg=loadWaves();
	if (errmsg){
		swprintf(wbuf,szErr_OpenFile,errmsg);
		MessageBoxW(NULL,wbuf,argv[0],MB_ICONERROR);
		destroyImages();
		destroyIcons();
		DestroyIcon(hIcon);
		return 0;
	}
	newGame();
	cxScreen=GetSystemMetrics(SM_CXSCREEN);
	cyScreen=GetSystemMetrics(SM_CYSCREEN);
	width=clwidth+GetSystemMetrics(SM_CXFIXEDFRAME)*2;
	height=clheight+GetSystemMetrics(SM_CYFIXEDFRAME)*2+GetSystemMetrics(SM_CYCAPTION)+GetSystemMetrics(SM_CYMENU);
	hMenu=CreateMenu();
	AppendMenuW(hMenu,MF_STRING,MENU_New,szMenu_New);
	AppendMenuW(hMenu,MF_STRING,MENU_Load,szMenu_Load);
	AppendMenuW(hMenu,MF_STRING,MENU_Save,szMenu_Save);
	AppendMenuW(hMenu,MF_STRING,MENU_Help,szMenu_Help);
#ifdef DEBUG
	AppendMenuW(hMenu,MF_SEPARATOR,0,NULL);
	hMenuP=CreateMenu();
	AppendMenuW(hMenuP,MF_STRING,MENU_Life,szMenu_Life);
	AppendMenuW(hMenuP,MF_STRING,MENU_Attack,szMenu_Attack);
	AppendMenuW(hMenuP,MF_STRING,MENU_Defend,szMenu_Defend);
	AppendMenuW(hMenuP,MF_STRING,MENU_Gold,szMenu_Gold);
	AppendMenuW(hMenuP,MF_STRING,MENU_Key,szMenu_Key);
	AppendMenuW(hMenuP,MF_STRING,MENU_Item,szMenu_Item);
	AppendMenuW(hMenu,MF_POPUP,(UINT_PTR)hMenuP,szMenu_Debug);
#endif
	hwnd=CreateWindowW(szAppName,szTitle,WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,(cxScreen-width)/2,(cyScreen-height)/2,width,height,NULL,hMenu,hInstance,NULL);
	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	destroyWaves();
	destroyImages();
	destroyIcons();
	DestroyIcon(hIcon);
	LocalFree(argv);
	return msg.wParam;
}
