int dialogY,story;
int enemies[11];

int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}

void setEnemies(){
	int type,i,j,k;
	int buffer[121];

	k=0;
	for (j=0;j<11;++j){
		for (i=0;i<11;++i){
			type=stmain.map[stmain.floor][j][i];
			if (cell[type].flag&CF_Listable){
				buffer[k++]=type;
			}
		}
		enemies[j]=CT_Null;
	}
	if (!k) return;
	qsort(buffer,k,sizeof(int),cmp);
	j=0;
	type=buffer[0];
	enemies[j++]=type;
	for (i=0;i<k;++i){
		if (buffer[i]!=type){
			type=buffer[i];
			enemies[j++]=type;
			if (j>=11) break;
		}
	}
}

int getAttackMul(int type){
	return ((type==CT_Zombie||type==CT_ZombieKnight||type==CT_Vampire)&&stmain.item[IT_Cross])||(type==CT_DragonS&&stmain.item[IT_DragonSlayer])?2:1;
}

int predictTotalDamage(int type){
	int mydamage,enemydamage;

	mydamage=stmain.attack*getAttackMul(type)-cell[type].defend;
	if (mydamage<=0) return -1;//unable to attack
	enemydamage=cell[type].attack-stmain.defend;
	if (enemydamage<=0){
		enemydamage=0;
	}
	return (cell[type].life-1)/mydamage*enemydamage;
}

int getTotalDamageA(int type){
	int mydamage,enemydamage,totalwin,totallose;

	enemydamage=cell[type].attack-stmain.defend;
	if (enemydamage<=0){
		enemydamage=0;
		totallose=0;
	}else{
		totallose=((stmain.life-1)/enemydamage+1)*enemydamage;
	}
	mydamage=stmain.attack*getAttackMul(type)-cell[type].defend;
	if (mydamage<=0){
		if (!enemydamage) return -1;//draw
		return totallose;
	}
	totalwin=(cell[type].life-1)/mydamage*enemydamage;
	return totalwin<totallose?totalwin:totallose;
}

int getTotalDamageD(int type){
	int mydamage,enemydamage,totalwin,totallose;

	enemydamage=cell[type].attack-stmain.defend;
	if (enemydamage<=0){
		enemydamage=0;
		totallose=0;
	}else{
		totallose=((stmain.life-1)/enemydamage+1)*enemydamage;
	}
	mydamage=stmain.attack*getAttackMul(type)-cell[type].defend;
	if (mydamage<=0){
		if (!enemydamage) return -1;//draw
		return totallose;
	}
	totalwin=((cell[type].life-1)/mydamage+1)*enemydamage;
	return totalwin<totallose?totalwin:totallose;
}

int isNearStair(){
	int type;

	if (stmain.y>0){
		type=stmain.map[stmain.floor][stmain.y-1][stmain.x];
		if (type==CT_UpStair||type==CT_DownStair) return 1;
	}
	if (stmain.y<10){
		type=stmain.map[stmain.floor][stmain.y+1][stmain.x];
		if (type==CT_UpStair||type==CT_DownStair) return 1;
	}
	if (stmain.x>0){
		type=stmain.map[stmain.floor][stmain.y][stmain.x-1];
		if (type==CT_UpStair||type==CT_DownStair) return 1;
	}
	if (stmain.x<10){
		type=stmain.map[stmain.floor][stmain.y][stmain.x+1];
		if (type==CT_UpStair||type==CT_DownStair) return 1;
	}
	return 0;
}

void goUpStair(){
	++stmain.floor;
	if (stmain.floor==44){
		++stmain.floor;
	}
	stmain.x=stairPosition[stmain.floor][SP_upX];
	stmain.y=stairPosition[stmain.floor][SP_upY];
	if (stmain.floor>stmain.maxfloor){
		stmain.maxfloor=stmain.floor;
	}
}

void goDownStair(){
	--stmain.floor;
	if (stmain.floor==44){
		--stmain.floor;
	}
	stmain.x=stairPosition[stmain.floor][SP_downX];
	stmain.y=stairPosition[stmain.floor][SP_downY];
	if (stmain.floor<stmain.minfloor){
		stmain.minfloor=stmain.floor;
	}
}
