#include <windows.h>
#include <stdlib.h>
#include <wchar.h>

struct icon{
	int width;
	int height;
	HBITMAP image;
	HBITMAP mask;
};

void ico_delete(struct icon *ico){
	if (!ico) return;
	DeleteObject(ico->image);
	DeleteObject(ico->mask);
	free(ico);
}

struct icon *ico_load(const wchar_t *path){
	struct icon *ico;
	HDC hdc,hdcImage,hdcMask;
	HBITMAP hbitmap;
	BITMAP bitmap;

	hbitmap=LoadImageW(NULL,path,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	if (!hbitmap) return NULL;
	ico=(struct icon *)malloc(sizeof(struct icon));
	ico->image=hbitmap;
	GetObject(hbitmap,sizeof(BITMAP),&bitmap);
	ico->width=bitmap.bmWidth;
	ico->height=bitmap.bmHeight;
	ico->mask=CreateBitmap(ico->width,ico->height,1,1,NULL);
	hdc=GetDC(NULL);
	hdcImage=CreateCompatibleDC(hdc);
	hdcMask=CreateCompatibleDC(hdc);
	ReleaseDC(NULL,hdc);
	SelectObject(hdcImage,ico->image);
	SelectObject(hdcMask,ico->mask);
	SetBkColor(hdcImage,RGB(0,0,0));
	BitBlt(hdcMask,0,0,ico->width,ico->height,hdcImage,0,0,SRCCOPY);
	DeleteDC(hdcImage);
	DeleteDC(hdcMask);
	return ico;
}

void ico_draw(struct icon *ico,HDC hdc,int x,int y){
	HDC hdc2,hdcMem;

	if (!ico) return;
	hdc2=GetDC(NULL);
	hdcMem=CreateCompatibleDC(hdc2);
	ReleaseDC(NULL,hdc2);
	SelectObject(hdcMem,ico->mask);
	BitBlt(hdc,x,y,ico->width,ico->height,hdcMem,0,0,SRCAND);
	SelectObject(hdcMem,ico->image);
	BitBlt(hdc,x,y,ico->width,ico->height,hdcMem,0,0,SRCPAINT);
	DeleteDC(hdcMem);
}
