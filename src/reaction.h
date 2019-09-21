int killMonster(int x,int y){//return gold obtained
	int type,temp,result,i,j;

	type=stmain.map[stmain.floor][y][x];
	if (!(type>CT_Null&&(cell[type].flag&CF_EnemyMask))){
		MessageBoxW(NULL,szErr_Logic,szTitle,MB_ICONERROR);
		story=ST_Jammed;
		return 0;
	}
	stmain.map[stmain.floor][y][x]=CT_Null;
	result=cell[type].gold;
	if (stmain.item[IT_LuckyGold]){
		result*=2;
	}
	stmain.gold+=result;
	switch (stmain.floor){
	case 2:
		temp=0;
		if (stmain.map[stmain.floor][1][5]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][1][7]==CT_Null){
			++temp;
		}
		if (temp==2&&y==1&&(x==5||x==7)){
			stmain.map[stmain.floor][4][4]=CT_Null;
			stmain.map[stmain.floor][4][8]=CT_Null;
			stmain.map[stmain.floor][7][4]=CT_Null;
			stmain.map[stmain.floor][7][8]=CT_Null;
			stmain.map[stmain.floor][10][4]=CT_Null;
			stmain.map[stmain.floor][10][8]=CT_Null;
			break;
		}
		break;
	case 8:
		temp=0;
		if (stmain.map[stmain.floor][4][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][4][10]==CT_Null){
			++temp;
		}
		if (temp==2&&y==4&&(x==8||x==10)){
			stmain.map[stmain.floor][3][9]=CT_Null;
			break;
		}
		break;
	case 10:
		temp=0;
		for (j=3;j<=5;++j){
			for (i=4;i<=6;++i){
				if (stmain.map[stmain.floor][j][i]==CT_Null){
					++temp;
				}
			}
		}
		if (temp==9&&(y>=3&&y<=5)&&(x>=4&&x<=6)){
			target=CT_SkeletonA;
			dialogY=6;
			swprintf(dialogbuf,szDialog_Story10F2);
			story=ST_10F2;
			break;
		}
		if (y==0&&x==5){
			dialogY=6;
			swprintf(dialogbuf,szDialog_Story10F3);
			story=ST_10F3;
			break;
		}
		break;
	case 11:
		temp=0;
		if (stmain.map[stmain.floor][4][0]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][4][2]==CT_Null){
			++temp;
		}
		if (temp==2&&y==4&&(x==0||x==2)){
			stmain.map[stmain.floor][3][1]=CT_Null;
			break;
		}
		break;
	case 14:
		temp=0;
		if (stmain.map[stmain.floor][0][0]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][1][1]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][0][2]==CT_Null){
			++temp;
		}
		if (temp==3&&((y==0&&x==0)||(y==1&&x==1)||(y==0&&x==2))){
			stmain.map[stmain.floor][2][0]=CT_RedKey;
			break;
		}
		break;
	case 15:
		if (y==5&&x==5){
			for (j=3;j<=5;++j){
				for (i=4;i<=6;++i){
					stmain.map[stmain.floor][j][i]=CT_Null;
				}
			}
			stmain.map[stmain.floor][2][5]=CT_Null;
			stmain.map[stmain.floor][8][5]=CT_Null;
			stmain.map[stmain.floor][4][5]=CT_MagicMattock;
			autosave=SS_15F;
			break;
		}
		break;
	case 17:
		temp=0;
		if (stmain.map[stmain.floor][4][0]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][4][2]==CT_Null){
			++temp;
		}
		if (temp==2&&y==4&&(x==0||x==2)){
			stmain.map[stmain.floor][3][1]=CT_Null;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][7][0]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][2]==CT_Null){
			++temp;
		}
		if (temp==2&&y==7&&(x==0||x==2)){
			stmain.map[stmain.floor][6][1]=CT_Null;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][4][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][4][10]==CT_Null){
			++temp;
		}
		if (temp==2&&y==4&&(x==8||x==10)){
			stmain.map[stmain.floor][3][9]=CT_Null;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][7][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][10]==CT_Null){
			++temp;
		}
		if (temp==2&&y==7&&(x==8||x==10)){
			stmain.map[stmain.floor][6][9]=CT_Null;
			break;
		}
		break;
	case 20:
		if (y==5&&x==5){
			dialogY=0;
			swprintf(dialogbuf,szDialog_Story20F2);
			story=ST_20F2;
			break;
		}
		break;
	case 25:
		if (y==5&&x==5){
			stmain.map[stmain.floor][9][5]=CT_Null;
			stmain.map[stmain.floor][7][3]=CT_RedKey;
			stmain.map[stmain.floor][7][4]=CT_RedKey;
			stmain.map[stmain.floor][7][5]=CT_RedKey;
			stmain.map[stmain.floor][7][6]=CT_RedKey;
			stmain.map[stmain.floor][7][7]=CT_RedKey;
			if (stmain.map[26][5][5]==CT_PrincessTalked){
				stmain.map[24][1][5]=CT_Null;
				stmain.map[24][2][5]=CT_Null;
				stmain.map[24][3][5]=CT_Null;
				stmain.map[24][0][4]=CT_Wall;
				stmain.map[24][0][6]=CT_Wall;
				stmain.map[24][0][5]=CT_CellTag;
			}
			autosave=SS_25F;
			break;
		}
		break;
	case 30:
		temp=0;
		for (i=2;i<=4;++i){
			if (stmain.map[stmain.floor][4][i]==CT_Null){
				++temp;
			}
		}
		for (i=6;i<=8;++i){
			if (stmain.map[stmain.floor][4][i]==CT_Null){
				++temp;
			}
		}
		if (temp==6&&y==4&&((x>=2&&x<=4)||(x>=6&&x<=8))){
			stmain.map[stmain.floor][3][5]=CT_Null;
			stmain.map[stmain.floor][6][5]=CT_Null;
			stmain.map[stmain.floor][0][5]=CT_UpStair;
			break;
		}
		break;
	case 32:
		temp=0;
		if (stmain.map[stmain.floor][9][0]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][9][2]==CT_Null){
			++temp;
		}
		if (temp==2&&y==9&&(x==0||x==2)){
			stmain.map[stmain.floor][8][1]=CT_Null;
			break;
		}
		break;
	case 33:
		temp=0;
		if (stmain.map[stmain.floor][4][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][4][10]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][6][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][6][10]==CT_Null){
			++temp;
		}
		if (temp==4&&((y==4&&x==8)||(y==4&&x==10)||(y==6&&x==8)||(y==6&&x==10))){
			stmain.map[stmain.floor][3][9]=CT_Null;
			stmain.map[stmain.floor][4][9]=CT_Null;
			stmain.map[stmain.floor][7][9]=CT_Null;
			break;
		}
		break;
	case 34:
		temp=0;
		if (stmain.map[stmain.floor][3][4]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][3][6]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][3][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][3][10]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][4]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][6]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][8]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][10]==CT_Null){
			++temp;
		}
		if (temp==8&&(\
			(y==3&&x==4)||(y==3&&x==6)||(y==3&&x==8)||(y==3&&x==10)||\
			(y==7&&x==4)||(y==7&&x==6)||(y==7&&x==8)||(y==7&&x==10)\
		)){
			stmain.map[stmain.floor][5][1]=CT_RedKey;
			stmain.map[stmain.floor][4][0]=CT_YellowKey;
			stmain.map[stmain.floor][4][2]=CT_YellowKey;
			stmain.map[stmain.floor][6][0]=CT_YellowKey;
			stmain.map[stmain.floor][6][2]=CT_YellowKey;
			break;
		}
		break;
	case 35:
		if (y==6&&x==5){
			for (j=4;j<=6;++j){
				for (i=4;i<=6;++i){
					stmain.map[stmain.floor][j][i]=CT_Null;
				}
			}
			stmain.map[stmain.floor][2][5]=CT_Null;
			stmain.map[stmain.floor][5][5]=CT_SnowCrystal;
			stmain.map[stmain.floor][4][4]=CT_BlueElixir;
			stmain.map[stmain.floor][4][5]=CT_BlueElixir;
			stmain.map[stmain.floor][4][6]=CT_BlueElixir;
			autosave=SS_35F;
			break;
		}
		break;
	case 38:
		temp=0;
		if (stmain.map[stmain.floor][9][0]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][9][2]==CT_Null){
			++temp;
		}
		if (temp==2&&y==9&&(x==0||x==2)){
			stmain.map[stmain.floor][8][1]=CT_FakeWall;
			break;
		}
		break;
	case 41:
		if (y==1&&x==1){
			stmain.map[stmain.floor][1][9]=CT_FakeWall;
			break;
		}
		if (y==1&&x==9){
			stmain.map[stmain.floor][5][4]=CT_Wall;
			stmain.map[stmain.floor][5][5]=CT_Wall;
			stmain.map[stmain.floor][5][6]=CT_Wall;
			stmain.map[stmain.floor][6][4]=CT_Null;
			stmain.map[stmain.floor][6][6]=CT_Null;
			stmain.map[stmain.floor][4][5]=CT_WingsToFlyDown;
			break;
		}
		break;
	case 44:
		temp=0;
		if (stmain.map[stmain.floor][8][4]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][8][6]==CT_Null){
			++temp;
		}
		if (temp==2&&y==8&&(x==4||x==6)){
			stmain.map[stmain.floor][7][5]=CT_Null;
			break;
		}
		break;
	case 45:
		temp=0;
		if (stmain.map[stmain.floor][8][4]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][10][4]==CT_Null){
			++temp;
		}
		if (temp==2&&(y==8||y==10)&&x==4){
			stmain.map[stmain.floor][9][3]=CT_Null;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][8][7]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][10][7]==CT_Null){
			++temp;
		}
		if (temp==2&&(y==8||y==10)&&x==7){
			stmain.map[stmain.floor][9][6]=CT_Null;
			break;
		}
		break;
	case 48:
		if (y==0&&x==0){
			stmain.map[stmain.floor][7][7]=CT_Null;
			break;
		}
		break;
	case 49:
		if (y==2&&x==5){
			for (j=1;j<=3;++j){
				for (i=4;i<=6;++i){
					stmain.map[stmain.floor][j][i]=CT_Null;
				}
			}
			stmain.map[stmain.floor][6][5]=CT_Null;
			stmain.map[stmain.floor][1][4]=CT_RedKey;
			stmain.map[stmain.floor][1][6]=CT_DragonSlayer;
			stmain.map[stmain.floor][3][1]=CT_RedCrystal;
			stmain.map[stmain.floor][3][2]=CT_RedCrystal;
			stmain.map[stmain.floor][3][3]=CT_RedCrystal;
			stmain.map[stmain.floor][3][7]=CT_BlueCrystal;
			stmain.map[stmain.floor][3][8]=CT_BlueCrystal;
			stmain.map[stmain.floor][3][9]=CT_BlueCrystal;
			stmain.map[stmain.floor][4][4]=CT_BlueElixir;
			stmain.map[stmain.floor][4][5]=CT_BlueElixir;
			stmain.map[stmain.floor][4][6]=CT_BlueElixir;
			autosave=SS_49F;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][7][4]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][7][6]==CT_Null){
			++temp;
		}
		if (temp==2&&y==7&&(x==4||x==6)){
			stmain.map[stmain.floor][6][5]=CT_Null;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][9][4]==CT_Null){
			++temp;
		}
		if (stmain.map[stmain.floor][9][6]==CT_Null){
			++temp;
		}
		if (temp==2&&y==9&&(x==4||x==6)){
			stmain.map[stmain.floor][8][5]=CT_Null;
			break;
		}
		temp=0;
		if (stmain.map[stmain.floor][1][4]==CT_MagicSergeant){
			++temp;
		}
		if (stmain.map[stmain.floor][1][6]==CT_MagicSergeant){
			++temp;
		}
		if (stmain.map[stmain.floor][3][4]==CT_MagicSergeant){
			++temp;
		}
		if (stmain.map[stmain.floor][3][6]==CT_MagicSergeant){
			++temp;
		}
		if (temp==4){
			temp=0;
			if (stmain.map[stmain.floor][1][5]==CT_Null){
				++temp;
			}
			if (stmain.map[stmain.floor][2][4]==CT_Null){
				++temp;
			}
			if (stmain.map[stmain.floor][2][6]==CT_Null){
				++temp;
			}
			if (stmain.map[stmain.floor][3][5]==CT_Null){
				++temp;
			}
			if (temp==4&&((y==1&&x==5)||(y==2&&x==4)||(y==2&&x==6)||(y==3&&x==5))){
				stmain.map[stmain.floor][2][5]=CT_Zeno49B;
				target=CT_Zeno49B;
				swprintf(statusbuf,szStatus_Story);
				dialogY=7;
				swprintf(dialogbuf,szDialog_Story49F2);
				story=ST_49F2;
			}
			break;
		}
		break;
	default:
		;
	}
	return result;
}

int touch(int x,int y){//return 0 to block moving
	int type,temp;

	type=stmain.map[stmain.floor][y][x];
	if (stmain.floor==50&&type==CT_Zeno49A){
		swprintf(statusbuf,szStatus_Story);
		story=ST_Finale0;
		return 0;
	}
	if (type==CT_Null||type==CT_CellTag){
		target=CT_Null;
		statusbuf[0]=0;
		return 1;
	}
	if (cell[type].flag&CF_Untouchable) return 0;
	if (cell[type].flag&CF_EnemyMask){
		target=type|CT_Detail;
		if (stmain.attack*getAttackMul(type)<=cell[type].defend){
			swprintf(statusbuf,szStatus_BattleForbidden,cell[type].name);
			return 0;
		}
		temp=getTotalDamageA(type);
		stmain.life-=temp;
		if (stmain.life<=0){
			stmain.life=0;
			playSound(WAV_Attack);
			swprintf(statusbuf,szStatus_BattleLose,cell[type].name);
			return 0;
		}
		temp=killMonster(x,y);
		playSound(WAV_Attack);
		swprintf(statusbuf,szStatus_BattleWinA,cell[type].name,temp);
		return 1;
	}
	switch (type){
	case CT_Thief:
	case CT_ThiefTalked:
		target=type;
		switch (stmain.floor){
		case 2:
			if (y==6&&x==2){
				stmain.map[stmain.floor][6][1]=CT_Null;
				playSound(WAV_Open);
				swprintf(statusbuf,szStatus_Story);
				dialogY=1;
				swprintf(dialogbuf,szDialog_Thief2F1);
				story=ST_Thief2F1;
				break;
			}
			if (y==7&&x==0){
				swprintf(statusbuf,szStatus_Story);
				dialogY=1;
				swprintf(dialogbuf,szDialog_Thief2F2);
				story=ST_Thief2F2;
				break;
			}
			if (y==10&&x==10){
				swprintf(statusbuf,szStatus_Story);
				dialogY=1;
				if (type==CT_Thief){
					swprintf(dialogbuf,szDialog_Thief2F3);
					story=ST_Thief2F3;
				}else{
					swprintf(dialogbuf,szDialog_Thief2F4);
					story=ST_Thief2F4;
				}
				break;
			}
			break;
		case 15:
			if (y==0&&x==8){
				stmain.map[stmain.floor][0][7]=CT_Null;
				playSound(WAV_Open);
				swprintf(statusbuf,szStatus_Story);
				dialogY=2;
				swprintf(dialogbuf,szDialog_Thief15F);
				story=ST_Thief15F;
				break;
			}
			break;
		case 29:
			if (y==3&&x==5){
				swprintf(statusbuf,szStatus_Story);
				dialogY=6;
				swprintf(dialogbuf,szDialog_Thief29F1);
				story=ST_Thief29F1;
				break;
			}
			if (y==1&&x==6){
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				if (type==CT_Thief){
					swprintf(dialogbuf,szDialog_Thief29F2);
					story=ST_Thief29F2;
				}else{
					swprintf(dialogbuf,szDialog_Thief29F3);
					story=ST_Thief29F3;
				}
				break;
			}
			break;
		case 35:
			if (y==9&&x==4){
				swprintf(statusbuf,szStatus_Story);
				dialogY=1;
				if (type==CT_Thief){
					swprintf(dialogbuf,szDialog_Thief35F1);
					story=ST_Thief35F1;
				}else{
					swprintf(dialogbuf,szDialog_Thief35F2);
					story=ST_Thief35F2;
				}
				break;
			}
			break;
		case 50:
			if (y==4&&x==5){
				swprintf(statusbuf,szStatus_Story);
				dialogY=7;
				swprintf(dialogbuf,szDialog_Thief50F);
				story=ST_Thief50F;
				break;
			}
			break;
		default:
			;
		}
		return 0;
	case CT_Princess:
	case CT_PrincessTalked:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_PrincessTalked;
		swprintf(statusbuf,szStatus_Story);
		dialogY=0;
		swprintf(dialogbuf,szDialog_Princess1);
		story=ST_Princess1;
		return 0;
	case CT_OldMan:
	case CT_OldManTalked:
		target=type;
		if (stmain.floor==2&&y==6&&x==10){
			dialogY=1;
			if (type==CT_OldMan){
				swprintf(statusbuf,szStatus_Merchant);
				swprintf(dialogbuf,szDialog_OldMan2F);
				story=ST_OldMan2F;
			}else{
				swprintf(statusbuf,szStatus_Story);
				swprintf(dialogbuf,szDialog_OldManT);
				story=ST_OldManT;
			}
			return 0;
		}
		stmain.map[stmain.floor][y][x]=CT_OldManTalked;
		switch (stmain.floor){
		case 3:
			if (y==3&&x==10){
				swprintf(statusbuf,szStatus_Story);
				dialogY=6;
				if (type==CT_OldMan){
					swprintf(dialogbuf,szDialog_OldMan3F);
					story=ST_OldMan3F;
				}else{
					swprintf(dialogbuf,szDialog_OldManT);
					story=ST_OldManT;
				}
				break;
			}
			break;
		case 4:
			if (y==0&&x==9){
				stmain.notes|=1<<1;
				swprintf(statusbuf,szStatus_Story);
				dialogY=3;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan4F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 6:
			if (y==7&&x==3){
				stmain.notes|=1<<2;
				swprintf(statusbuf,szStatus_Story);
				dialogY=1;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan6F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 16:
			if (y==10&&x==0){
				stmain.notes|=1<<7;
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan16F1:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			if (y==10&&x==10){
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				if (type==CT_OldMan){
					swprintf(dialogbuf,szDialog_OldMan16F2);
					story=ST_OldMan16F2;
				}else{
					swprintf(dialogbuf,szDialog_OldManT);
					story=ST_OldManT;
				}
				break;
			}
			break;
		case 18:
			if (y==1&&x==2){
				stmain.notes|=1<<8;
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan18F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 21:
			if (y==5&&x==5){
				stmain.notes|=1<<9;
				swprintf(statusbuf,szStatus_Story);
				dialogY=7;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan21F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 23:
			if (y==10&&x==10){
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				swprintf(dialogbuf,szDialog_OldMan23F);
				story=ST_OldManT;
				break;
			}
			break;
		case 27:
			if (y==0&&x==5){
				stmain.notes|=1<<10;
				swprintf(statusbuf,szStatus_Story);
				dialogY=3;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan27F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 31:
			if (y==0&&x==10){
				stmain.notes|=1<<11;
				swprintf(statusbuf,szStatus_Story);
				dialogY=3;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan31F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 33:
			if (y==2&&x==3){
				stmain.notes|=1<<13;
				swprintf(statusbuf,szStatus_Story);
				dialogY=5;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan33F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 36:
			if (y==0&&x==0){
				stmain.notes|=1<<14;
				swprintf(statusbuf,szStatus_Story);
				dialogY=3;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan36F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 37:
			if (y==10&&x==0){
				stmain.notes|=1<<15;
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan37F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 39:
			if (y==10&&x==0){
				stmain.notes|=1<<17;
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan39F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 42:
			if (y==3&&x==0){
				stmain.notes|=1<<19;
				swprintf(statusbuf,szStatus_Story);
				dialogY=6;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan42F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 45:
			if (y==5&&x==8){
				stmain.notes|=1<<20;
				swprintf(statusbuf,szStatus_Story);
				dialogY=0;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan45F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 46:
			if (y==8&&x==7){
				stmain.notes|=1<<22;
				swprintf(statusbuf,szStatus_Story);
				dialogY=2;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan46F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		case 48:
			if (y==1&&x==2){
				stmain.notes|=1<<24;
				swprintf(statusbuf,szStatus_Story);
				dialogY=4;
				swprintf(dialogbuf,type==CT_OldMan?szDialog_OldMan48F:szDialog_OldManT);
				story=ST_OldManT;
				break;
			}
			break;
		default:
			;
		}
		return 0;
	case CT_Merchant:
	case CT_MerchantBought:
	case CT_MerchantTalked:
		target=type;
		switch (stmain.floor){
		case 2:
			if (y==3&&x==10){
				dialogY=6;
				swprintf(statusbuf,szStatus_Story);
				if (type==CT_Merchant){
					stmain.map[stmain.floor][y][x]=CT_MerchantBought;
					swprintf(dialogbuf,szDialog_Merchant2F);
					story=ST_Merchant2F;
				}else{
					swprintf(dialogbuf,szDialog_Merchant2FB);
					story=ST_MerchantT;
				}
				break;
			}
		case 6:
			if (y==3&&x==7){
				dialogY=6;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant6F);
					story=ST_Merchant6F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<3;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant6FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 7:
			if (y==0&&x==5){
				dialogY=3;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant7F);
					story=ST_Merchant7F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<4;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant7FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 12:
			if (y==0&&x==0){
				dialogY=3;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant12F1);
					story=ST_Merchant12F1;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<5;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant12FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			if (y==0&&x==10){
				swprintf(statusbuf,szStatus_Merchant);
				dialogY=3;
				swprintf(dialogbuf,szDialog_Merchant12F2);
				story=ST_Merchant12F2;
				break;
			}
			break;
		case 15:
			if (y==10&&x==10){
				dialogY=4;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant15F);
					story=ST_Merchant15F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<6;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant15FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 28:
			if (y==3&&x==7){
				swprintf(statusbuf,szStatus_Merchant);
				dialogY=6;
				swprintf(dialogbuf,szDialog_Merchant28F);
				story=ST_Merchant28F;
				break;
			}
			break;
		case 31:
			if (y==10&&x==0){
				dialogY=4;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant31F);
					story=ST_Merchant31F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<12;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant31FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 38:
			if (y==1&&x==4){
				dialogY=4;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant38F);
					story=ST_Merchant38F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<16;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant38FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 39:
			if (y==1&&x==8){
				dialogY=4;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant39F);
					story=ST_Merchant39F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<18;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant39FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 45:
			if (y==2&&x==8){
				dialogY=5;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant45F);
					story=ST_Merchant45F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<21;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant45FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		case 47:
			if (y==1&&x==4){
				dialogY=4;
				if (type==CT_Merchant){
					swprintf(statusbuf,szStatus_Merchant);
					swprintf(dialogbuf,szDialog_Merchant47F);
					story=ST_Merchant47F;
				}else{
					stmain.map[stmain.floor][y][x]=CT_MerchantTalked;
					stmain.notes|=1<<23;
					swprintf(statusbuf,szStatus_Story);
					swprintf(dialogbuf,type==CT_MerchantBought?szDialog_Merchant47FB:szDialog_MerchantT);
					story=ST_MerchantT;
				}
				break;
			}
			break;
		default:
			;
		}
		return 0;
	case CT_Altar:
		target=type;
		temp=stmain.altar;
		temp=(temp*temp-temp)*10+20;
		swprintf(statusbuf,szStatus_Altar);
		dialogY=3;
		swprintf(dialogbuf,szDialog_Altar,temp,stmain.altar*100,(stmain.floor+9)/10*2,(stmain.floor+9)/10*4);
		story=ST_Altar;
		return 0;
	case CT_UpStair:
		target=type;
		goUpStair();
		swprintf(statusbuf,szStatus_UpStair);
		return 0;
	case CT_DownStair:
		target=type;
		goDownStair();
		swprintf(statusbuf,szStatus_DownStair);
		return 0;
	case CT_FakeWall:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		if (stmain.floor==12&&y==0&&x==10){
			stmain.map[stmain.floor][y][x]=CT_Merchant;
		}
		if (stmain.floor==16&&y==10&&x==10){
			stmain.map[stmain.floor][y][x]=CT_OldMan;
		}
		if (stmain.floor==19&&y==2&&x==5){
			stmain.map[stmain.floor][y][x]=CT_Cross;
		}
		if (stmain.floor==41&&y==1&&x==9){
			stmain.map[stmain.floor][y][x]=CT_MagicianA;
		}
		playSound(WAV_Open);
		swprintf(statusbuf,szStatus_WallCollapse);
		return 0;
	case CT_FakeRoad:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Wall;
		if (stmain.floor==48&&y==0&&x==0){
			stmain.map[stmain.floor][y][x]=CT_MagicSergeant;
		}
		playSound(WAV_Open);
		swprintf(statusbuf,szStatus_WallAppear);
		return 0;
	case CT_RedDoor:
		target=type;
		if (stmain.key[KEY_Red]>0){
			stmain.map[stmain.floor][y][x]=CT_Null;
			--stmain.key[KEY_Red];
			playSound(WAV_Open);
			swprintf(statusbuf,szStatus_RedDoorOpen);
			return 0;
		}
		swprintf(statusbuf,szStatus_RedDoorBlock);
		return 0;
	case CT_BlueDoor:
		target=type;
		if (stmain.key[KEY_Blue]>0){
			stmain.map[stmain.floor][y][x]=CT_Null;
			--stmain.key[KEY_Blue];
			playSound(WAV_Open);
			swprintf(statusbuf,szStatus_BlueDoorOpen);
			return 0;
		}
		swprintf(statusbuf,szStatus_BlueDoorBlock);
		return 0;
	case CT_YellowDoor:
		target=type;
		if (stmain.key[KEY_Yellow]>0){
			stmain.map[stmain.floor][y][x]=CT_Null;
			--stmain.key[KEY_Yellow];
			swprintf(statusbuf,szStatus_YellowDoorOpen);
			if (stmain.floor==39){
				temp=0;
				if (stmain.map[stmain.floor][1][1]==CT_YellowDoor){
					++temp;
				}
				if (stmain.map[stmain.floor][1][5]==CT_YellowDoor){
					++temp;
				}
				if (stmain.map[stmain.floor][3][1]==CT_YellowDoor){
					++temp;
				}
				if (stmain.map[stmain.floor][3][3]==CT_YellowDoor){
					++temp;
				}
				if (stmain.map[stmain.floor][5][1]==CT_YellowDoor){
					++temp;
				}
				if (stmain.map[stmain.floor][5][3]==CT_YellowDoor){
					++temp;
				}
				if (stmain.map[stmain.floor][5][5]==CT_YellowDoor){
					++temp;
				}
				if (temp==7){
					temp=0;
					if (stmain.map[stmain.floor][1][3]==CT_Null){
						++temp;
					}
					if (stmain.map[stmain.floor][3][5]==CT_Null){
						++temp;
					}
					if (temp==2&&((y==1&&x==3)||(y==3&&x==5))){
						stmain.map[stmain.floor][3][3]=CT_WarpStaff;
					}
				}
			}
			if (stmain.floor==43&&y==0&&x==7){
				if (stmain.map[stmain.floor][0][8]==CT_MagicSergeant){
					stmain.map[stmain.floor][y][x]=CT_CellTag;
				}
			}
			playSound(WAV_Open);
			return 0;
		}
		swprintf(statusbuf,szStatus_YellowDoorBlock);
		return 0;
	case CT_Lava:
		target=type;
		swprintf(statusbuf,szStatus_LavaBlock);
		return 0;
	case CT_RedKey:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.key[KEY_Red];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetRedKey);
		return 1;
	case CT_BlueKey:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.key[KEY_Blue];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetBlueKey);
		return 1;
	case CT_YellowKey:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.key[KEY_Yellow];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetYellowKey);
		return 1;
	case CT_RedElixir:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=(stmain.floor+9)/10*cell[type].life;
		stmain.life+=temp;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetRedElixir,temp);
		return 1;
	case CT_BlueElixir:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=(stmain.floor+9)/10*cell[type].life;
		stmain.life+=temp;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetBlueElixir,temp);
		return 1;
	case CT_RedCrystal:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=(stmain.floor+9)/10*cell[type].attack;
		stmain.attack+=temp;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetRedCrystal,temp);
		return 1;
	case CT_BlueCrystal:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=(stmain.floor+9)/10*cell[type].defend;
		stmain.defend+=temp;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetBlueCrystal,temp);
		return 1;
	case CT_IronSword:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].attack;
		stmain.attack+=temp;
		if (stmain.weapon<WEP_IronSword){
			stmain.weapon=WEP_IronSword;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetWeapon,szCell_IronSword,temp);
		return 1;
	case CT_SilverSword:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].attack;
		stmain.attack+=temp;
		if (stmain.weapon<WEP_SilverSword){
			stmain.weapon=WEP_SilverSword;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetWeapon,szCell_SilverSword,temp);
		return 1;
	case CT_SwordOfKnight:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].attack;
		stmain.attack+=temp;
		if (stmain.weapon<WEP_SwordOfKnight){
			stmain.weapon=WEP_SwordOfKnight;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetWeapon,szCell_SwordOfKnight,temp);
		return 1;
	case CT_HolySword:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].attack;
		if (stmain.weapon<WEP_HolySword){
			stmain.weapon=WEP_HolySword;
		}
		stmain.attack+=temp;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetWeapon,szCell_HolySword,temp);
		return 1;
	case CT_SacredSword:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].attack;
		if (stmain.weapon<WEP_SacredSword){
			stmain.weapon=WEP_SacredSword;
		}
		stmain.attack+=temp;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetWeapon,szCell_SacredSword,temp);
		return 1;
	case CT_IronShield:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].defend;
		stmain.defend+=temp;
		if (stmain.armor<ARM_IronShield){
			stmain.armor=ARM_IronShield;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetArmor,szCell_IronShield,temp);
		return 1;
	case CT_SilverShield:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].defend;
		stmain.defend+=temp;
		if (stmain.armor<ARM_SilverShield){
			stmain.armor=ARM_SilverShield;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetArmor,szCell_SilverShield,temp);
		return 1;
	case CT_ShieldOfKnight:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].defend;
		stmain.defend+=temp;
		if (stmain.armor<ARM_ShieldOfKnight){
			stmain.armor=ARM_ShieldOfKnight;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetArmor,szCell_ShieldOfKnight,temp);
		return 1;
	case CT_HolyShield:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].defend;
		stmain.defend+=temp;
		if (stmain.armor<ARM_HolyShield){
			stmain.armor=ARM_HolyShield;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetArmor,szCell_HolyShield,temp);
		return 1;
	case CT_SacredShield:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		temp=cell[type].defend;
		stmain.defend+=temp;
		if (stmain.armor<ARM_SacredShield){
			stmain.armor=ARM_SacredShield;
		}
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetArmor,szCell_SacredShield,temp);
		return 1;
	case CT_OrbOfHero:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_OrbOfHero]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_OrbOfHero);
		return 1;
	case CT_OrbOfWisdom:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_OrbOfWisdom]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_OrbOfWisdom);
		return 1;
	case CT_OrbOfFlying:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_OrbOfFlying]=1;
		stmain.item[IT_OrbOfFlying2]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_OrbOfFlying);
		return 1;
	case CT_Cross:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_Cross]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetCross);
		return 1;
	case CT_MagicElixir:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_MagicElixir];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_MagicElixir);
		return 1;
	case CT_MagicMattock:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_MagicMattock];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_MagicMattock);
		return 1;
	case CT_DestructibleBall:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_DestructibleBall];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_DestructibleBall);
		return 1;
	case CT_WarpStaff:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_WarpStaff]+=3;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_WarpStaff);
		return 1;
	case CT_WingsToFlyUp:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_WingsToFlyUp];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_WingsToFlyUp);
		return 1;
	case CT_WingsToFlyDown:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_WingsToFlyDown];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_WingsToFlyDown);
		return 1;
	case CT_DragonSlayer:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_DragonSlayer]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetDragonSlayer);
		return 1;
	case CT_SnowCrystal:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_SnowCrystal]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_SnowCrystal);
		return 1;
	case CT_MagicKey:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_MagicKey];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_MagicKey);
		return 1;
	case CT_SuperMagicMattock:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		++stmain.item[IT_SuperMagicMattock];
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetItem,szCell_SuperMagicMattock);
		return 1;
	case CT_LuckyGold:
		target=type;
		stmain.map[stmain.floor][y][x]=CT_Null;
		stmain.item[IT_LuckyGold]=1;
		playSound(WAV_Get);
		swprintf(statusbuf,szStatus_GetLuckyGold);
		return 1;
	default:
		;
	}
	return 0;
}

void enter(int moved){
	int type[4];
	int i,temp;

	if (moved){
		if (stmain.armor<ARM_SacredShield){
			for (i=0;i<4;++i){
				type[i]=CT_Null;
			}
			if (stmain.y>0){
				type[0]=stmain.map[stmain.floor][stmain.y-1][stmain.x];
			}
			if (stmain.y<10){
				type[1]=stmain.map[stmain.floor][stmain.y+1][stmain.x];
			}
			if (stmain.x>0){
				type[2]=stmain.map[stmain.floor][stmain.y][stmain.x-1];
			}
			if (stmain.x<10){
				type[3]=stmain.map[stmain.floor][stmain.y][stmain.x+1];
			}
			temp=0;
			if (type[0]==CT_MagicSergeant&&type[1]==CT_MagicSergeant){
				temp+=stmain.life-stmain.life/2;
			}
			if (type[2]==CT_MagicSergeant&&type[3]==CT_MagicSergeant){
				temp+=stmain.life-stmain.life/2;
			}
			for (i=0;i<4;++i){
				if (type[i]==CT_MagicianB){
					temp+=100;
				}
				if (type[i]==CT_MagicianA){
					temp+=200;
				}
			}
			if (temp>0){
				stmain.life-=temp;
				playSound(WAV_MagicAttack);
				if (stmain.life<=0){
					stmain.life=0;
					swprintf(statusbuf,szStatus_MagicLose);
				}else{
					swprintf(statusbuf,szStatus_MagicAttack,temp);
				}
			}
		}
		if (stmain.floor==47){
			if (stmain.y>1&&stmain.map[stmain.floor][stmain.y-1][stmain.x]==CT_MagicianA&&stmain.map[stmain.floor][stmain.y-2][stmain.x]==CT_Null){
				stmain.map[stmain.floor][stmain.y-1][stmain.x]=CT_Null;
				stmain.map[stmain.floor][stmain.y-2][stmain.x]=CT_MagicianA;
			}
			if (stmain.y<9&&stmain.map[stmain.floor][stmain.y+1][stmain.x]==CT_MagicianA&&stmain.map[stmain.floor][stmain.y+2][stmain.x]==CT_Null){
				stmain.map[stmain.floor][stmain.y+1][stmain.x]=CT_Null;
				stmain.map[stmain.floor][stmain.y+2][stmain.x]=CT_MagicianA;
			}
			if (stmain.x>1&&stmain.map[stmain.floor][stmain.y][stmain.x-1]==CT_MagicianA&&stmain.map[stmain.floor][stmain.y][stmain.x-2]==CT_Null){
				stmain.map[stmain.floor][stmain.y][stmain.x-1]=CT_Null;
				stmain.map[stmain.floor][stmain.y][stmain.x-2]=CT_MagicianA;
			}
			if (stmain.x<9&&stmain.map[stmain.floor][stmain.y][stmain.x+1]==CT_MagicianA&&stmain.map[stmain.floor][stmain.y][stmain.x+2]==CT_Null){
				stmain.map[stmain.floor][stmain.y][stmain.x+1]=CT_Null;
				stmain.map[stmain.floor][stmain.y][stmain.x+2]=CT_MagicianA;
			}
		}
	}
	if (stmain.map[stmain.floor][stmain.y][stmain.x]==CT_CellTag){
		stmain.map[stmain.floor][stmain.y][stmain.x]=CT_Null;
		switch (stmain.floor){
		case 3:
			if (stmain.y==8&&stmain.x==4){
				target=CT_Zeno49A;
				stmain.map[stmain.floor][6][4]=CT_Zeno49A;
				playSound(WAV_Zeno);
				swprintf(statusbuf,szStatus_Story);
				dialogY=1;
				swprintf(dialogbuf,szDialog_Story3F1);
				story=ST_3F1;
				break;
			}
			break;
		case 10:
			if (stmain.y==4&&stmain.x==5){
				target=CT_SkeletonA;
				swprintf(statusbuf,szStatus_Story);
				dialogY=6;
				swprintf(dialogbuf,szDialog_Story10F1);
				story=ST_10F1;
				break;
			}
			if (stmain.y==8&&stmain.x==5){
				target=CT_Thief;
				stmain.map[stmain.floor][9][5]=CT_Thief;
				swprintf(statusbuf,szStatus_Story);
				dialogY=2;
				swprintf(dialogbuf,szDialog_Story10F4);
				story=ST_10F4;
				break;
			}
			break;
		case 15:
			if (stmain.y==7&&stmain.x==5){
				stmain.map[stmain.floor][8][5]=CT_SteelGate;
				playSound(WAV_Open);
				break;
			}
			break;
		case 20:
			if (stmain.y==7&&stmain.x==5){
				target=CT_Vampire;
				stmain.map[stmain.floor][8][5]=CT_SteelGate;
				stmain.map[stmain.floor][4][4]=CT_Null;
				stmain.map[stmain.floor][4][5]=CT_Null;
				stmain.map[stmain.floor][4][6]=CT_Null;
				stmain.map[stmain.floor][5][4]=CT_Null;
				stmain.map[stmain.floor][5][6]=CT_Null;
				stmain.map[stmain.floor][6][4]=CT_Null;
				stmain.map[stmain.floor][6][5]=CT_Null;
				stmain.map[stmain.floor][6][6]=CT_Null;
				stmain.map[stmain.floor][5][5]=CT_Vampire;
				playSound(WAV_Vampire);
				swprintf(statusbuf,szStatus_Story);
				dialogY=0;
				swprintf(dialogbuf,szDialog_Story20F1);
				story=ST_20F1;
				break;
			}
			break;
		case 24:
			if (stmain.y==0&&stmain.x==5){
				target=CT_BraveMan;
				stmain.floor=50;
				stmain.x=5;
				stmain.y=6;
				swprintf(statusbuf,szStatus_Story);
				dialogY=7;
				swprintf(dialogbuf,szDialog_Story50F1);
				story=ST_50F1;
				break;
			}
			break;
		case 25:
			if (stmain.y==8&&stmain.x==5){
				target=CT_GreatMagicMaster;
				stmain.map[stmain.floor][9][5]=CT_SteelGate;
				playSound(WAV_Open);
				swprintf(statusbuf,szStatus_Story);
				dialogY=0;
				swprintf(dialogbuf,szDialog_Story25F);
				story=ST_25F;
				break;
			}
			break;
		case 28:
			if (stmain.y==10&&stmain.x==1){
				stmain.map[29][2][5]=CT_Null;
				stmain.map[29][3][5]=CT_Null;
				stmain.map[29][1][6]=CT_Thief;
				break;
			}
			break;
		case 29:
			if (stmain.y==9&&stmain.x==0){
				stmain.map[28][10][1]=CT_CellTag;
				break;
			}
			break;
		case 30:
			if (stmain.y==5&&stmain.x==5){
				stmain.map[stmain.floor][3][5]=CT_SteelGate;
				stmain.map[stmain.floor][6][5]=CT_SteelGate;
				playSound(WAV_Open);
				break;
			}
			break;
		case 32:
			if (stmain.y==9&&stmain.x==5){
				target=CT_GoldenKnight;
				stmain.map[stmain.floor][5][5]=CT_GoldenKnight;
				swprintf(statusbuf,szStatus_Story);
				dialogY=0;
				swprintf(dialogbuf,szDialog_Story32F1);
				story=ST_32F1;
				break;
			}
			break;
		case 33:
			if (stmain.y==4&&stmain.x==9){
				stmain.map[stmain.floor][3][9]=CT_SteelGate;
				stmain.map[stmain.floor][7][9]=CT_SteelGate;
				playSound(WAV_Open);
				break;
			}
			if (stmain.y==9&&stmain.x==8){
				stmain.map[stmain.floor][9][7]=CT_Wall;
				playSound(WAV_Open);
				break;
			}
			break;
		case 35:
			if (stmain.y==9&&stmain.x==5){
				stmain.map[2][10][10]=CT_Null;
				stmain.map[36][1][10]=CT_Null;
				break;
			}
			break;
		case 36:
			if (stmain.y==1&&stmain.x==10){
				stmain.map[2][10][10]=CT_Null;
				stmain.map[35][9][5]=CT_Null;
				break;
			}
			break;
		case 38:
			if (stmain.y==5&&stmain.x==1){
				stmain.map[stmain.floor][4][1]=CT_Wall;
				playSound(WAV_Open);
				break;
			}
			break;
		case 40:
			if (stmain.y==6&&stmain.x==5){
				target=CT_GoldenKnight;
				stmain.map[stmain.floor][7][5]=CT_SteelGate;
				playSound(WAV_Open);
				swprintf(statusbuf,szStatus_Story);
				dialogY=7;
				swprintf(dialogbuf,szDialog_Story40F1);
				story=ST_40F1;
				break;
			}
			break;
		case 42:
			if (stmain.y==9&&stmain.x==5){
				target=CT_GoldenKnight;
				stmain.map[stmain.floor][5][5]=CT_Zeno49A;
				stmain.map[2][10][10]=CT_Null;
				stmain.map[35][9][4]=CT_Null;
				stmain.map[35][9][5]=CT_Null;
				stmain.map[36][1][10]=CT_Null;
				playSound(WAV_Zeno);
				swprintf(statusbuf,szStatus_Story);
				dialogY=0;
				swprintf(dialogbuf,szDialog_Story42F1);
				story=ST_42F1;
				break;
			}
			break;
		case 43:
			if (stmain.y==0&&stmain.x==7){
				stmain.map[stmain.floor][0][8]=CT_Null;
				stmain.map[stmain.floor][0][10]=CT_MagicSergeant;
				stmain.map[stmain.floor][0][6]=CT_Wall;
				stmain.map[stmain.floor][0][9]=CT_Wall;
				playSound(WAV_Open);
				break;
			}
			break;
		case 49:
			if (stmain.y==5&&stmain.x==5){
				target=CT_Zeno49A;
				stmain.map[stmain.floor][6][5]=CT_SteelGate;
				stmain.map[stmain.floor][2][5]=CT_Zeno49A;
				playSound(WAV_Zeno);
				swprintf(statusbuf,szStatus_Story);
				dialogY=7;
				swprintf(dialogbuf,szDialog_Story49F1);
				story=ST_49F1;
				break;
			}
			break;
		default:
			;
		}
	}
}
