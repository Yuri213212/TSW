struct note_t{
	int floor;
	int target;
	const wchar_t *dialog;
};

const struct note_t notes[]={
	{0,	CT_Null,	L""			},
	{4,	CT_OldMan,	szDialog_OldMan4F	},
	{6,	CT_OldMan,	szDialog_OldMan6F	},
	{6,	CT_Merchant,	szDialog_Merchant6FB	},
	{7,	CT_Merchant,	szDialog_Merchant7FB	},
	{12,	CT_Merchant,	szDialog_Merchant12FB	},
	{15,	CT_Merchant,	szDialog_Merchant15FB	},
	{16,	CT_OldMan,	szDialog_OldMan16F1	},
	{18,	CT_OldMan,	szDialog_OldMan18F	},
	{21,	CT_OldMan,	szDialog_OldMan21F	},
	{27,	CT_OldMan,	szDialog_OldMan27F	},
	{31,	CT_OldMan,	szDialog_OldMan31F	},
	{31,	CT_Merchant,	szDialog_Merchant31FB	},
	{33,	CT_OldMan,	szDialog_OldMan33F	},
	{36,	CT_OldMan,	szDialog_OldMan36F	},
	{37,	CT_OldMan,	szDialog_OldMan37F	},
	{38,	CT_Merchant,	szDialog_Merchant38FB	},
	{39,	CT_OldMan,	szDialog_OldMan39F	},
	{39,	CT_Merchant,	szDialog_Merchant39FB	},
	{42,	CT_OldMan,	szDialog_OldMan42F	},
	{45,	CT_OldMan,	szDialog_OldMan45F	},
	{45,	CT_Merchant,	szDialog_Merchant45FB	},
	{46,	CT_OldMan,	szDialog_OldMan46F	},
	{47,	CT_Merchant,	szDialog_Merchant47FB	},
	{48,	CT_OldMan,	szDialog_OldMan48F	},
};

int cnote;

int countBits(int x){
	int temp,c;

	c=0;
	for (temp=x;temp;temp&=(temp-1)){
		++c;
	}
	return c;
}

int getPageNo(){
	return countBits(stmain.notes&(cnote|(cnote-1)));
}

int getPageLen(){
	return countBits(stmain.notes);
}

int getNoteIndex(){
	int temp,y;

	y=0;
	for (temp=cnote;temp>1;temp>>=1){
		++y;
	}
	return y;
}
