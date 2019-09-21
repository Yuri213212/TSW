#define imageCount 4
enum imageEnum{
	IM_Opening,
	IM_Logo,
	IM_Coma,
	IM_End,
};

const wchar_t imagePath[imageCount][32]={
	L"./res/Opening.bmp",
	L"./res/Logo.bmp",
	L"./res/Coma.bmp",
	L"./res/End.bmp",
};

HBITMAP image[imageCount];

wchar_t *loadImages(){
	HBITMAP hbitmap;
	int i,j;

	for (i=0;i<imageCount;++i){
		hbitmap=LoadImageW(NULL,imagePath[i],IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		if (!hbitmap){
			for (j=i;j;--j){
				DeleteObject(image[j]);
			}
			return (wchar_t *)imagePath[i];
		}
		image[i]=hbitmap;
	}
	return NULL;
}

void destroyImages(){
	int i;

	for (i=0;i<imageCount;++i){
		DeleteObject(image[i]);
	}
}

void drawImage(int type,HDC hdc,int x,int y){
	HDC hdc2,hdcMem;
	BITMAP bitmap;

	GetObject(image[type],sizeof(BITMAP),&bitmap);
	hdc2=GetDC(NULL);
	hdcMem=CreateCompatibleDC(hdc2);
	ReleaseDC(NULL,hdc2);
	SelectObject(hdcMem,image[type]);
	BitBlt(hdc,x,y,bitmap.bmWidth,bitmap.bmHeight,hdcMem,0,0,SRCCOPY);
	DeleteDC(hdcMem);
}
