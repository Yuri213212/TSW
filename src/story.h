enum storyEnum{
	ST_Null,
	ST_Intro,
	ST_Load,
	ST_Book,
	ST_Note,
	ST_3F1,
	ST_3F2,
	ST_Title,
	ST_Coma0,
	ST_Coma1,
	ST_Coma2,
	ST_Coma3,
	ST_Coma4,
	ST_Wake1,
	ST_Wake2,
	ST_Wake3,
	ST_Wake4,
	ST_10F1,
	ST_10F2,
	ST_10F3,
	ST_10F4,
	ST_20F1,
	ST_20F2,
	ST_25F,
	ST_32F1,
	ST_32F11,
	ST_32F2,
	ST_40F1,
	ST_40F11,
	ST_40F12,
	ST_40F13,
	ST_40F2,
	ST_40F21,
	ST_40F22,
	ST_40F23,
	ST_40F3,
	ST_40F31,
	ST_40F32,
	ST_40F33,
	ST_40F4,
	ST_40F41,
	ST_40F42,
	ST_40F43,
	ST_40F5,
	ST_40F51,
	ST_40F6,
	ST_42F1,
	ST_42F2,
	ST_42F3,
	ST_42F4,
	ST_49F1,
	ST_49F2,
	ST_50F1,
	ST_50F2,
	ST_50F3,
	ST_50F4,
	ST_50F5,
	ST_50F6,
	ST_50F7,
	ST_50F8,
	ST_50F9,
	ST_50F10,
	ST_50F11,
	ST_50F12,
	ST_Finale0,
	ST_Finale1,
	ST_Finale2,
	ST_Finale3,
	ST_Finale4,
	ST_TheEnd,
	ST_Thief2F1,
	ST_Thief2F2,
	ST_Thief2F3,
	ST_Thief2F4,
	ST_Thief15F,
	ST_Thief29F1,
	ST_Thief29F2,
	ST_Thief29F3,
	ST_Thief35F1,
	ST_Thief35F2,
	ST_Thief50F,
	ST_Princess1,
	ST_Princess2,
	ST_OldManT,
	ST_OldMan2F,
	ST_OldMan3F,
	ST_OldMan16F2,
	ST_MerchantT,
	ST_Merchant2F,
	ST_Merchant2FB,
	ST_Merchant6F,
	ST_Merchant6FB,
	ST_Merchant7F,
	ST_Merchant7FB,
	ST_Merchant12F1,
	ST_Merchant12FB,
	ST_Merchant12F2,
	ST_Merchant15F,
	ST_Merchant15FB,
	ST_Merchant28F,
	ST_Merchant31F,
	ST_Merchant31FB,
	ST_Merchant38F,
	ST_Merchant38FB,
	ST_Merchant39F,
	ST_Merchant39FB,
	ST_Merchant45F,
	ST_Merchant45FB,
	ST_Merchant47F,
	ST_Merchant47FB,
	ST_Altar,
	ST_BattleEndless,
	ST_Jammed,
};

int defendMonster(int x,int y){//return 0 to block story change
	int type,temp;

	type=stmain.map[stmain.floor][y][x];
	if (!(type>CT_Null&&(cell[type].flag&CF_EnemyMask))){
		MessageBoxW(NULL,szErr_Logic,szTitle,MB_ICONERROR);
		story=ST_Jammed;
		return 0;
	}
	target=type|CT_Detail;
	temp=getTotalDamageD(type);
	if (temp<0){
		playSound(WAV_Attack);
		swprintf(statusbuf,szStatus_BattleEndless,cell[type].name);
		story=ST_BattleEndless;
		return 0;
	}
	stmain.life-=temp;
	if (stmain.life<=0){
		stmain.life=0;
		playSound(WAV_Attack);
		swprintf(statusbuf,szStatus_BattleLose,cell[type].name);
		story=ST_Null;
		return 0;
	}
	stmain.map[stmain.floor][y][x]|=CT_Explode;
	temp=cell[type].gold;
	if (stmain.item[IT_LuckyGold]){
		temp*=2;
	}
	stmain.gold+=temp;
	playSound(WAV_Attack);
	swprintf(statusbuf,szStatus_BattleWinD,cell[type].name,temp);
	return 1;
}

int storyProgress(){//return 1 to redraw
	int i;

	switch (story){
	case ST_Intro:
		swprintf(statusbuf,szStatus_Init);
		story=ST_Null;
		return 1;
	case ST_3F1:
		target=CT_BraveMan;
		stmain.map[3][7][4]=CT_MagicSergeant;
		stmain.map[3][8][3]=CT_MagicSergeant;
		stmain.map[3][8][5]=CT_MagicSergeant;
		stmain.map[3][9][4]=CT_MagicSergeant;
		swprintf(dialogbuf,szDialog_Story3F2);
		story=ST_3F2;
		return 1;
	case ST_3F2:
		target=CT_Null;
		stmain.map[3][6][4]=CT_Null;
		stmain.map[3][7][4]=CT_Null;
		stmain.map[3][8][3]=CT_Null;
		stmain.map[3][8][5]=CT_Null;
		stmain.map[3][9][4]=CT_Null;
		playSound(WAV_MagicAttack);
		dialogY=-1;
		story=ST_Title;
		return 1;
	case ST_Title:
		story=ST_Coma0;
		return 1;
	case ST_Coma0:
		story=ST_Coma1;
		return 1;
	case ST_Coma1:
		story=ST_Coma2;
		return 1;
	case ST_Coma2:
		story=ST_Coma3;
		return 1;
	case ST_Coma3:
		story=ST_Coma4;
		return 1;
	case ST_Coma4:
		stmain.floor=2;
		stmain.x=2;
		stmain.y=7;
		if (stmain.round==1){
			stmain.life-=600;
			stmain.attack-=90;
			stmain.defend-=90;
			stmain.weapon=WEP_Null;
			stmain.armor=ARM_Null;
		}
		dialogY=1;
		swprintf(dialogbuf,szDialog_Wake1);
		story=ST_Wake1;
		return 1;
	case ST_Wake1:
		swprintf(dialogbuf,szDialog_Wake2);
		story=ST_Wake2;
		return 1;
	case ST_Wake2:
		swprintf(dialogbuf,szDialog_Wake3);
		story=ST_Wake3;
		return 1;
	case ST_Wake3:
		swprintf(dialogbuf,szDialog_Wake4);
		story=ST_Wake4;
		return 1;
	case ST_Wake4:
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_10F1:
		target=CT_Null;
		stmain.map[10][0][5]=CT_SkeletonA;
		stmain.map[10][3][1]=CT_Null;
		stmain.map[10][3][9]=CT_Null;
		stmain.map[10][3][5]=CT_SkeletonB;
		stmain.map[10][5][5]=CT_SkeletonB;
		for (i=0;i<3;++i){
			stmain.map[10][2][i]=CT_Null;
			stmain.map[10][2][8+i]=CT_Null;
			stmain.map[10][3+i][4]=CT_SkeletonC;
			stmain.map[10][3+i][6]=CT_SkeletonC;
		}
		stmain.map[10][2][5]=CT_SteelGate;
		stmain.map[10][6][5]=CT_SteelGate;
		playSound(WAV_Open);
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_10F2:
		target=CT_Null;
		stmain.map[10][2][5]=CT_Null;
		playSound(WAV_Open);
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_10F3:
		target=CT_Null;
		stmain.map[10][3][3]=CT_Null;
		stmain.map[10][3][7]=CT_Null;
		stmain.map[10][6][5]=CT_Null;
		stmain.map[10][10][5]=CT_UpStair;
		stmain.map[10][2][0]=CT_RedCrystal;
		stmain.map[10][2][1]=CT_RedCrystal;
		stmain.map[10][2][2]=CT_RedCrystal;
		stmain.map[10][2][8]=CT_BlueCrystal;
		stmain.map[10][2][9]=CT_BlueCrystal;
		stmain.map[10][2][10]=CT_BlueCrystal;
		stmain.map[10][3][0]=CT_BlueElixir;
		stmain.map[10][3][1]=CT_BlueElixir;
		stmain.map[10][3][2]=CT_BlueElixir;
		stmain.map[10][3][8]=CT_YellowKey;
		stmain.map[10][3][9]=CT_YellowKey;
		stmain.map[10][3][10]=CT_YellowKey;
		stmain.map[10][8][5]=CT_CellTag;
		playSound(WAV_Open);
		dialogY=-1;
		story=ST_Null;
		autosave=SS_10F;
		swprintf(statusbuf,szStatus_Save);
		return 1;
	case ST_10F4:
		target=CT_Null;
		stmain.map[10][9][5]=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_20F1:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_20F2:
		target=CT_Null;
		stmain.map[20][2][5]=CT_Null;
		stmain.map[20][8][5]=CT_Null;
		stmain.map[20][0][5]=CT_UpStair;
		stmain.map[20][4][3]=CT_RedCrystal;
		stmain.map[20][5][3]=CT_RedCrystal;
		stmain.map[20][6][3]=CT_RedCrystal;
		stmain.map[20][4][7]=CT_BlueCrystal;
		stmain.map[20][5][7]=CT_BlueCrystal;
		stmain.map[20][6][7]=CT_BlueCrystal;
		stmain.map[20][7][4]=CT_BlueElixir;
		stmain.map[20][7][5]=CT_BlueElixir;
		stmain.map[20][7][6]=CT_BlueElixir;
		stmain.map[20][3][4]=CT_YellowKey;
		stmain.map[20][3][5]=CT_YellowKey;
		stmain.map[20][3][6]=CT_YellowKey;
		playSound(WAV_Open);
		dialogY=-1;
		story=ST_Null;
		autosave=SS_20F;
		swprintf(statusbuf,szStatus_Save);
		return 1;
	case ST_25F:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_32F1:
		stmain.map[32][5][5]=CT_Null;
		stmain.map[32][8][5]=CT_GoldenKnight;
		if (defendMonster(5,8)){
			story=ST_32F11;
		}
		dialogY=-1;
		return 1;
	case ST_32F11:
		stmain.map[32][8][5]=CT_GoldenKnight;
		swprintf(statusbuf,szStatus_Story);
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story32F2);
		story=ST_32F2;
		return 1;
	case ST_32F2:
		target=CT_Null;
		stmain.map[32][8][5]=CT_Null;
		stmain.map[29][1][6]=CT_Null;
		stmain.map[2][10][10]=CT_Thief;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_40F1:
		stmain.map[40][3][4]=CT_Null;
		stmain.map[40][5][5]=CT_GhostSoldier;
		if (defendMonster(5,5)){
			story=ST_40F11;
		}
		dialogY=-1;
		return 1;
	case ST_40F11:
		stmain.map[40][3][3]=CT_Null;
		stmain.map[40][5][5]=CT_GhostSoldier;
		if (defendMonster(5,5)){
			story=ST_40F12;
		}
		dialogY=-1;
		return 1;
	case ST_40F12:
		stmain.map[40][3][2]=CT_Null;
		stmain.map[40][5][5]=CT_GhostSoldier;
		if (defendMonster(5,5)){
			story=ST_40F13;
		}
		dialogY=-1;
		return 1;
	case ST_40F13:
		target=CT_GoldenKnight;
		stmain.map[40][5][5]=CT_Null;
		swprintf(statusbuf,szStatus_Story);
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story40F2);
		story=ST_40F2;
		return 1;
	case ST_40F2:
		stmain.map[40][3][6]=CT_Null;
		stmain.map[40][5][5]=CT_Soldier;
		if (defendMonster(5,5)){
			story=ST_40F21;
		}
		dialogY=-1;
		return 1;
	case ST_40F21:
		stmain.map[40][3][7]=CT_Null;
		stmain.map[40][5][5]=CT_Soldier;
		if (defendMonster(5,5)){
			story=ST_40F22;
		}
		dialogY=-1;
		return 1;
	case ST_40F22:
		stmain.map[40][3][8]=CT_Null;
		stmain.map[40][5][5]=CT_Soldier;
		if (defendMonster(5,5)){
			story=ST_40F23;
		}
		dialogY=-1;
		return 1;
	case ST_40F23:
		target=CT_GoldenKnight;
		stmain.map[40][5][5]=CT_Null;
		swprintf(statusbuf,szStatus_Story);
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story40F3);
		story=ST_40F3;
		return 1;
	case ST_40F3:
		stmain.map[40][1][3]=CT_Null;
		stmain.map[40][5][5]=CT_Swordsman;
		if (defendMonster(5,5)){
			story=ST_40F31;
		}
		dialogY=-1;
		return 1;
	case ST_40F31:
		stmain.map[40][1][2]=CT_Null;
		stmain.map[40][5][5]=CT_Swordsman;
		if (defendMonster(5,5)){
			story=ST_40F32;
		}
		dialogY=-1;
		return 1;
	case ST_40F32:
		stmain.map[40][1][1]=CT_Null;
		stmain.map[40][5][5]=CT_Swordsman;
		if (defendMonster(5,5)){
			story=ST_40F33;
		}
		dialogY=-1;
		return 1;
	case ST_40F33:
		target=CT_GoldenKnight;
		stmain.map[40][5][5]=CT_Null;
		swprintf(statusbuf,szStatus_Story);
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story40F4);
		story=ST_40F4;
		return 1;
	case ST_40F4:
		stmain.map[40][1][7]=CT_Null;
		stmain.map[40][5][5]=CT_Knight;
		if (defendMonster(5,5)){
			story=ST_40F41;
		}
		dialogY=-1;
		return 1;
	case ST_40F41:
		stmain.map[40][1][8]=CT_Null;
		stmain.map[40][5][5]=CT_Knight;
		if (defendMonster(5,5)){
			story=ST_40F42;
		}
		dialogY=-1;
		return 1;
	case ST_40F42:
		stmain.map[40][1][9]=CT_Null;
		stmain.map[40][5][5]=CT_Knight;
		if (defendMonster(5,5)){
			story=ST_40F43;
		}
		dialogY=-1;
		return 1;
	case ST_40F43:
		target=CT_GoldenKnight;
		stmain.map[40][5][5]=CT_Null;
		swprintf(statusbuf,szStatus_Story);
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story40F5);
		story=ST_40F5;
		return 1;
	case ST_40F5:
		stmain.map[40][1][5]=CT_Null;
		stmain.map[40][5][5]=CT_GoldenKnight;
		if (defendMonster(5,5)){
			story=ST_40F51;
		}
		dialogY=-1;
		return 1;
	case ST_40F51:
		stmain.map[40][5][5]=CT_GoldenKnight;
		swprintf(statusbuf,szStatus_Story);
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story40F6);
		story=ST_40F6;
		return 1;
	case ST_40F6:
		target=CT_Null;
		stmain.map[40][5][5]=CT_Null;
		stmain.map[40][7][5]=CT_Null;
		stmain.map[40][0][5]=CT_UpStair;
		stmain.map[40][1][1]=CT_RedCrystal;
		stmain.map[40][1][2]=CT_RedCrystal;
		stmain.map[40][1][3]=CT_RedCrystal;
		stmain.map[40][1][7]=CT_BlueCrystal;
		stmain.map[40][1][8]=CT_BlueCrystal;
		stmain.map[40][1][9]=CT_BlueCrystal;
		stmain.map[40][3][2]=CT_BlueElixir;
		stmain.map[40][3][3]=CT_BlueElixir;
		stmain.map[40][3][4]=CT_BlueElixir;
		stmain.map[40][3][6]=CT_YellowKey;
		stmain.map[40][3][7]=CT_YellowKey;
		stmain.map[40][3][8]=CT_YellowKey;
		playSound(WAV_Open);
		dialogY=-1;
		story=ST_Null;
		autosave=SS_40F;
		swprintf(statusbuf,szStatus_Save);
		return 1;
	case ST_42F1:
		target=CT_Zeno49A;
		swprintf(dialogbuf,szDialog_Story42F2);
		story=ST_42F2;
		return 1;
	case ST_42F2:
		target=CT_GoldenKnight;
		stmain.map[42][6][5]=CT_MagicSergeant;
		stmain.map[42][7][4]=CT_MagicSergeant;
		stmain.map[42][7][6]=CT_MagicSergeant;
		stmain.map[42][8][5]=CT_MagicSergeant;
		swprintf(dialogbuf,szDialog_Story42F3);
		story=ST_42F3;
		return 1;
	case ST_42F3:
		target=CT_Zeno49A;
		stmain.map[42][7][5]=CT_Null;
		stmain.map[42][6][5]=CT_Null;
		stmain.map[42][7][4]=CT_Null;
		stmain.map[42][7][6]=CT_Null;
		stmain.map[42][8][5]=CT_Null;
		playSound(WAV_MagicAttack);
		swprintf(dialogbuf,szDialog_Story42F4);
		story=ST_42F4;
		return 1;
	case ST_42F4:
		target=CT_Null;
		stmain.map[42][5][5]=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_49F1:
		target=CT_Null;
		stmain.map[49][1][4]=CT_MagicSergeant;
		stmain.map[49][1][5]=CT_MagicSergeant;
		stmain.map[49][1][6]=CT_MagicSergeant;
		stmain.map[49][2][4]=CT_MagicSergeant;
		stmain.map[49][2][6]=CT_MagicSergeant;
		stmain.map[49][3][4]=CT_MagicSergeant;
		stmain.map[49][3][5]=CT_MagicSergeant;
		stmain.map[49][3][6]=CT_MagicSergeant;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_49F2:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_50F1:
		target=CT_Thief;
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story50F2);
		story=ST_50F2;
		return 1;
	case ST_50F2:
		target=CT_BraveMan;
		stmain.map[50][4][5]=CT_Zeno49A;
		playSound(WAV_Zeno);
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story50F3);
		story=ST_50F3;
		return 1;
	case ST_50F3:
		target=CT_Zeno49A;
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story50F4);
		story=ST_50F4;
		return 1;
	case ST_50F4:
		target=CT_BraveMan;
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story50F5);
		story=ST_50F5;
		return 1;
	case ST_50F5:
		target=CT_Zeno49A;
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story50F6);
		story=ST_50F6;
		return 1;
	case ST_50F6:
		target=CT_BraveMan;
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story50F7);
		story=ST_50F7;
		return 1;
	case ST_50F7:
		target=CT_Zeno49A;
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story50F8);
		story=ST_50F8;
		return 1;
	case ST_50F8:
		target=CT_BraveMan;
		dialogY=7;
		swprintf(dialogbuf,szDialog_Story50F9);
		story=ST_50F9;
		return 1;
	case ST_50F9:
		target=CT_Zeno49A;
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story50F10);
		story=ST_50F10;
		return 1;
	case ST_50F10:
		if (stmain.round>1){
			stmain.map[50][4][5]=CT_Null;
			stmain.map[50][5][5]=CT_Zeno50;
			if (defendMonster(5,5)){
				story=ST_50F11;
			}
			dialogY=-1;
			return 1;
		}
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_50F11:
		target=CT_Zeno49A;
		swprintf(statusbuf,szStatus_Story);
		dialogY=0;
		swprintf(dialogbuf,szDialog_Story50F11);
		story=ST_50F12;
		return 1;
	case ST_50F12:
		story=ST_Finale0;
		return 1;
	case ST_Finale0:
		story=ST_Finale1;
		return 1;
	case ST_Finale1:
		story=ST_Finale2;
		return 1;
	case ST_Finale2:
		story=ST_Finale3;
		return 1;
	case ST_Finale3:
		story=ST_Finale4;
		return 1;
	case ST_Finale4:
		story=ST_TheEnd;
		return 1;
	case ST_TheEnd:
		target=CT_Null;
		st_nextRound();
		dialogY=-1;
		story=ST_Null;
		autosave=SS_1F;
		swprintf(statusbuf,szStatus_Save);
		return 1;
	case ST_Thief2F1:
		target=CT_Null;
		stmain.map[2][6][2]=CT_Null;
		stmain.map[2][7][0]=CT_Thief;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief2F2:
		target=CT_Null;
		stmain.map[2][7][0]=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief2F3:
		target=CT_Null;
		stmain.map[2][10][10]=CT_ThiefTalked;
		stmain.map[35][8][3]=CT_Null;
		stmain.map[35][9][4]=CT_Thief;
		stmain.map[35][9][5]=CT_CellTag;
		stmain.map[36][1][10]=CT_CellTag;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief2F4:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief15F:
		target=CT_Null;
		stmain.map[15][0][8]=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief29F1:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief29F2:
		target=CT_Null;
		stmain.map[29][1][6]=CT_ThiefTalked;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief29F3:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief35F1:
		target=CT_Null;
		stmain.map[35][9][4]=CT_ThiefTalked;
		stmain.map[2][10][10]=CT_Null;
		stmain.map[35][9][5]=CT_Null;
		stmain.map[36][1][10]=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief35F2:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Thief50F:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Princess1:
		target=CT_BraveMan;
		swprintf(dialogbuf,szDialog_Princess2);
		story=ST_Princess2;
		return 1;
	case ST_Princess2:
		target=CT_Null;
		stmain.map[50][4][5]=CT_Thief;
		if (stmain.map[25][5][5]==CT_Null){
			stmain.map[24][1][5]=CT_Null;
			stmain.map[24][2][5]=CT_Null;
			stmain.map[24][3][5]=CT_Null;
			stmain.map[24][0][4]=CT_Wall;
			stmain.map[24][0][6]=CT_Wall;
			stmain.map[24][0][5]=CT_CellTag;
		}
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_OldManT:
	case ST_MerchantT:
		target=CT_Null;
		statusbuf[0]=0;
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_OldMan3F:
		target=CT_OrbOfHero;
		stmain.item[IT_OrbOfHero]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_OrbOfHero);
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_OldMan16F2:
		target=CT_MagicElixir;
		stmain.item[IT_MagicElixir]+=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_MagicElixir);
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant2F:
		target=CT_Null;
		stmain.gold+=1000;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_Merchant2F);
		dialogY=-1;
		story=ST_Null;
		return 1;
	default:
		;
	}
	return 0;
}

int storyChoice(int n){//return 1 to redraw //0=cancel, 1~9=choice 1~9, -2=prev, -1=next
	int temp;

	switch (story){
	case ST_Load:
		if (n<0) return 0;
		if (!n){
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		temp=n-1;
		if (saveFloor[temp]<0||saveFloor[temp]==stsave[temp].floor){
			st_load(temp);
			target=CT_Null;
			swprintf(statusbuf,szStatus_Load);
			dialogY=-1;
			story=ST_Null;
		}
		return 1;
	case ST_Book:
		if (n) return 0;
		story=ST_Null;
		return 1;
	case ST_Note:
		if (n>0) return 0;
		if (!n){
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n==-2){//prev
			if (getPageNo()>1){
				for (cnote>>=1;!(cnote&stmain.notes);cnote>>=1);
				swprintf(dialogbuf,notes[getNoteIndex()].dialog);
				return 1;
			}
		}else{//next
			if (getPageNo()<getPageLen()){
				for (cnote<<=1;!(cnote&stmain.notes);cnote<<=1);
				swprintf(dialogbuf,notes[getNoteIndex()].dialog);
				return 1;
			}
		}
		return 0;
	case ST_BattleEndless:
		if (n) return 0;
		target=CT_Null;
		stmain.life=0;
		swprintf(statusbuf,szStatus_BattleSurrender);
		dialogY=-1;
		story=ST_Null;
		return 1;
	default:
		;
	}
	if (n<0) return 0;
	switch (story){
	case ST_OldMan2F:
		target=CT_Null;
		if (!n){
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		stmain.map[2][6][10]=CT_OldManTalked;
		stmain.attack+=stmain.attack*3/100;
		stmain.defend+=stmain.defend*3/100;
		swprintf(statusbuf,szStatus_OldMan2F);
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant6F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=50){
			stmain.map[6][3][7]=CT_MerchantBought;
			stmain.gold-=50;
			stmain.key[KEY_Blue]+=1;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant7F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=50){
			stmain.map[7][0][5]=CT_MerchantBought;
			stmain.gold-=50;
			stmain.key[KEY_Yellow]+=5;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant12F1:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=800){
			stmain.map[12][0][0]=CT_MerchantBought;
			stmain.gold-=800;
			stmain.key[KEY_Red]+=1;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant12F2:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=1000){
			stmain.map[12][0][0]=CT_MerchantBought;
			stmain.gold-=1000;
			stmain.key[KEY_Yellow]+=1;
			playSound(WAV_Get);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
			dialogY=-1;
			story=ST_Null;
		}
		return 1;
	case ST_Merchant15F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=200){
			stmain.map[15][10][10]=CT_MerchantBought;
			stmain.gold-=200;
			stmain.key[KEY_Blue]+=1;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant28F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.key[KEY_Yellow]>=1){
			stmain.map[12][0][0]=CT_MerchantBought;
			stmain.key[KEY_Yellow]-=1;
			stmain.gold+=100;
			playSound(WAV_Get);
		}else{
			swprintf(statusbuf,szStatus_NoKey);
			dialogY=-1;
			story=ST_Null;
		}
		return 1;
	case ST_Merchant31F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=1000){
			stmain.map[31][10][0]=CT_MerchantBought;
			stmain.gold-=1000;
			stmain.key[KEY_Blue]+=1;
			stmain.key[KEY_Yellow]+=4;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant38F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=200){
			stmain.map[38][1][4]=CT_MerchantBought;
			stmain.gold-=200;
			stmain.key[KEY_Yellow]+=3;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant39F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=2000){
			stmain.map[39][1][8]=CT_MerchantBought;
			stmain.gold-=2000;
			stmain.key[KEY_Blue]+=3;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant45F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=1000){
			stmain.map[45][2][8]=CT_MerchantBought;
			stmain.gold-=1000;
			stmain.life+=2000;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_Bought);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Merchant47F:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n!=1) return 0;
		if (stmain.gold>=4000){
			stmain.map[47][1][4]=CT_MerchantBought;
			stmain.gold-=4000;
			target=CT_SuperMagicMattock;
			stmain.item[IT_SuperMagicMattock]+=1;
			playSound(WAV_Get);
			swprintf(statusbuf,szStatus_GetItem,szCell_SuperMagicMattock);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	case ST_Altar:
		if (!n){
			target=CT_Null;
			statusbuf[0]=0;
			dialogY=-1;
			story=ST_Null;
			return 1;
		}
		if (n>3) return 0;
		temp=stmain.altar;
		temp=(temp*temp-temp)*10+20;
		if (stmain.gold>=temp){
			stmain.gold-=temp;
			switch (n){
			case 1:
				temp=stmain.altar*100;
				stmain.life+=temp;
				swprintf(statusbuf,szStatus_AltarLife,temp);
				break;
			case 2:
				temp=(stmain.floor+9)/10*2;
				stmain.attack+=temp;
				swprintf(statusbuf,szStatus_AltarAttack,temp);
				break;
			case 3:
				temp=(stmain.floor+9)/10*4;
				stmain.defend+=temp;
				swprintf(statusbuf,szStatus_AltarDefend,temp);
				break;
			default:
				;
			}
			++stmain.altar;
			playSound(WAV_Get);
		}else{
			swprintf(statusbuf,szStatus_NoMoney);
		}
		dialogY=-1;
		story=ST_Null;
		return 1;
	default:
		;
	}
	return 0;
}
