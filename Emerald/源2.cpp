#if 1
#include "Emerald.h"
//#include <xnamath.h>

#define WAVEWIDTH 100

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";  //��������
	desc.isFullScreen = false;     //�Ƿ�ȫ��
	desc.width = 800;            //���ڿ��
	desc.height = 450;           //���ڸ߶�
	desc.isSSAA = true;           //�ǿ��������
	desc.isVsync = false;          //�Ƿ�ֱͬ��
	EEInitialize(desc);

	EEMusic music;
	music.Open("Music/jx.mp3");
	music.SetFrequencyRatio(2.0f);
	//music.Start(0.2f);

	EETexture bgTex(L"Texture\\������\\�����汳��.jpg");
	EEScene *mainScene = new EEScene(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), bgTex);

	EETexture nameTex(L"Texture\\������\\��Ϸ����.png");
	EEQuad *nameQuad = new EEQuad(Rect_Float(70, 170, 470, 270), nameTex);
	nameQuad->SetAlpha(0.0f);
	EEFade(nameQuad, 1.0f, 1.0f);
	mainScene->AddObject(nameQuad);

	while (EERun())
	{
		EEShowFPSInTitle(L"- -");
		EEBeginScene(EEColor::WHITE);

		EEProcess(mainScene);

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif