#define wavCount 6
enum wavEnum{
	WAV_Get,
	WAV_Open,
	WAV_Attack,
	WAV_MagicAttack,
	WAV_Zeno,
	WAV_Vampire,
};

typedef void* HWAV;

const wchar_t wavPath[wavCount][32]={
	L"./res/sound/Get.wav",
	L"./res/sound/Open.wav",
	L"./res/sound/Attack.wav",
	L"./res/sound/MagicAttack.wav",
	L"./res/sound/Zeno.wav",
	L"./res/sound/Vampire.wav",
};

HWAV wav[wavCount];

wchar_t *loadWaves(){
	HWAV hwav;
	FILE *fp;
	int i,j;

	for (i=0;i<wavCount;++i){
		if (!(fp=_wfopen(wavPath[i],L"rb"))){
			for (j=i;j;--j){
				free(wav[j]);
			}
			return (wchar_t *)wavPath[i];
		}
		fseek(fp,0,SEEK_END);
		j=ftell(fp);
		hwav=malloc(j);
		rewind(fp);
		fread(hwav,j,1,fp);
		fclose(fp);
		wav[i]=hwav;
	}
	return NULL;
}

void destroyWaves(){
	int i;

	for (i=0;i<wavCount;++i){
		free(wav[i]);
	}
}

void playSound(int type){
	PlaySoundW(wav[type],NULL,SND_MEMORY|SND_ASYNC);
}
