#define initFloor	1
#define initX		5
#define initY		10

enum stairPositionEnum{
	SP_upX,
	SP_upY,
	SP_downX,
	SP_downY,
};

const int stairPosition[51][4]={
	{ 1, 0, 1, 0},//0F
	{ 1, 0, 1, 0},
	{ 0, 1, 0, 9},
	{ 1,10, 9,10},
	{10, 9, 0, 9},
	{ 1,10, 0, 1},
	{ 0, 1,10, 9},
	{10, 9, 0, 1},
	{ 0, 1, 5, 1},
	{ 5, 1, 0, 9},
	{ 0, 9, 5, 9},//10F
	{ 5, 9, 10, 9},
	{ 9,10, 1,10},
	{ 1,10, 9,10},
	{ 9,10, 5, 9},
	{ 5, 9, 5, 1},
	{ 5, 1, 5, 9},
	{ 5, 9, 5, 1},
	{ 5, 1, 0, 1},
	{ 0, 1, 5, 9},
	{ 5, 9, 5, 1},//20F
	{ 5, 1, 5, 9},
	{ 5, 9, 5, 6},
	{ 0, 1,10, 1},
	{ 1,10, 1,10},
	{ 1,10, 1,10},
	{ 1,10, 1,10},
	{ 1,10, 9,10},
	{ 9,10, 1,10},
	{ 0, 9, 5, 9},
	{ 5, 9, 5, 1},//30F
	{ 5, 1, 5, 9},
	{ 5, 9, 9, 0},
	{ 9, 0, 1, 0},
	{ 1, 0, 5, 9},
	{ 5, 9, 9, 0},
	{10, 1,10, 9},
	{10, 9, 1, 0},
	{ 1, 0, 9, 0},
	{10, 1, 9,10},
	{ 9,10, 4, 0},//40F
	{ 5, 1, 5, 9},
	{ 5, 9, 1, 0},
	{ 0, 1, 0, 9},
	{ 0, 1, 0, 1},
	{ 1, 0, 9, 0},
	{10, 1,10, 9},
	{ 9,10, 0, 1},
	{10, 9, 0, 9},
	{ 1,10, 1,10},
	{ 5, 6, 5, 6},//50F
};
