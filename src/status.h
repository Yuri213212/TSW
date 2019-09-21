enum keyEnum{
	KEY_Red,
	KEY_Blue,
	KEY_Yellow,
};

#define saveSlotCount 9

enum saveSlotEnum{
	SS_Quick,
	SS_1F,
	SS_10F,
	SS_15F,
	SS_20F,
	SS_25F,
	SS_35F,
	SS_40F,
	SS_49F,
};

const int saveFloor[saveSlotCount]={
	-1,1,10,
	15,20,25,
	35,40,49,
};

struct status{
	int round;
	int floor;
	int maxfloor;
	int minfloor;
	int x;
	int y;
	int life;
	int attack;
	int defend;
	int gold;
	int weapon;
	int armor;
	int altar;
	int notes;
	int key[3];
	int item[16];
	int map[51][11][11];
};

int autosave;
struct status stmain,stsave[saveSlotCount];

void st_reset(struct status *st){
	int i;

	st->round=1;
	st->floor=initFloor;
	st->maxfloor=initFloor;
	st->minfloor=initFloor;
	st->x=initX;
	st->y=initY;
	st->life=1000;
	st->attack=100;
	st->defend=100;
	st->gold=0;
	st->weapon=WEP_SacredSword;
	st->armor=ARM_SacredShield;
	st->altar=1;
	st->notes=0;
	for (i=0;i<3;++i){
		st->key[i]=0;
	}
	for (i=0;i<16;++i){
		st->item[i]=0;
	}
	memcpy(st->map,&map,sizeof(map));
}

void st_load(int slot){
	memcpy(&stmain,&stsave[slot],sizeof(struct status));
}

void st_save(int slot){
	memcpy(&stsave[slot],&stmain,sizeof(struct status));
}

void st_nextRound(){
	int i;

	++stmain.round;
	stmain.floor=initFloor;
	stmain.maxfloor=initFloor;
	stmain.minfloor=initFloor;
	stmain.x=initX;
	stmain.y=initY;
	stmain.life/=44;
	stmain.attack/=44;
	stmain.defend/=44;
	stmain.gold=0;
	stmain.weapon=WEP_Null;
	stmain.armor=ARM_Null;
	stmain.altar=1;
	stmain.notes=0;
	for (i=0;i<3;++i){
		stmain.key[i]=0;
	}
	for (i=0;i<16;++i){
		stmain.item[i]=0;
	}
	memcpy(&stmain.map,&map,sizeof(map));
	st_save(SS_1F);
}

void newGame(){
	int i;

	st_reset(&stmain);
	for (i=0;i<saveSlotCount;++i){
		st_reset(&stsave[i]);
	}
}

void setDefLoadFileName(){
	swprintf(fbuf,L"%s*.sav",dbuf);
}

void setDefSaveFileName(){
	static SYSTEMTIME time;

	GetSystemTime(&time);
	swprintf(fbuf,L"%s%04d%02d%02d%02d%02d%02d.sav",dbuf,time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond);
}

void loadGame(FILE *fp){
	fread(&stmain,sizeof(struct status),1,fp);
	fread(stsave,sizeof(struct status),saveSlotCount,fp);
}

void saveGame(FILE *fp){
	fwrite(&stmain,sizeof(struct status),1,fp);
	fwrite(stsave,sizeof(struct status),saveSlotCount,fp);
}
