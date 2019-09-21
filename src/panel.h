#define weaponCount 5
enum weaponEnum{
	WEP_Null=-1,
	WEP_IronSword,
	WEP_SilverSword,
	WEP_SwordOfKnight,
	WEP_HolySword,
	WEP_SacredSword,
};

#define armorCount 5
enum armorEnum{
	ARM_Null=-1,
	ARM_IronShield,
	ARM_SilverShield,
	ARM_ShieldOfKnight,
	ARM_HolyShield,
	ARM_SacredShield,
};

#define itemCount 16
enum itemEnum{
	IT_OrbOfHero,
	IT_OrbOfWisdom,
	IT_OrbOfFlying,
	IT_OrbOfFlying2,
	IT_Cross,
	IT_MagicElixir,
	IT_MagicMattock,
	IT_DestructibleBall,
	IT_WarpStaff,
	IT_WingsToFlyUp,
	IT_WingsToFlyDown,
	IT_DragonSlayer,
	IT_SnowCrystal,
	IT_MagicKey,
	IT_SuperMagicMattock,
	IT_LuckyGold,
};

struct item_t{
	int image;
	RECT rect;
	const wchar_t *key;
};

const struct item_t item[itemCount]={
	{ICO_OrbOfHeroP,		{528,208,560,240},	L"H"	},
	{ICO_OrbOfWisdomP,		{560,208,592,240},	L"N"	},
	{ICO_OrbOfFlyingP,		{592,208,624,224},	L"PgUp"	},
	{ICO_Null,			{592,224,624,240},	L"PgDn"	},
	{ICO_CrossP,			{528,240,560,272},	L""	},
	{ICO_MagicElixirP,		{560,240,592,272},	L"W"	},
	{ICO_MagicMattockP,		{592,240,624,272},	L"P"	},
	{ICO_DestructibleBallP,		{528,272,560,304},	L"B"	},
	{ICO_WarpStaffP,		{560,272,592,304},	L"J"	},
	{ICO_WingsToFlyUpP,		{592,272,624,304},	L"U"	},
	{ICO_WingsToFlyDownP,		{528,304,560,336},	L"D"	},
	{ICO_DragonSlayerP,		{560,304,592,336},	L""	},
	{ICO_SnowCrystalP,		{592,304,624,336},	L"I"	},
	{ICO_MagicKeyP,			{528,336,560,368},	L"K"	},
	{ICO_SuperMagicMattockP,	{560,336,592,368},	L"Q"	},
	{ICO_LuckyGoldP,		{592,336,624,368},	L""	},
};

int target;
