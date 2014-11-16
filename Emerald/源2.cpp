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
	//music.SetFrequencyRatio(1.0f);
	music.Start(0.0f);

	//order 1, time 0 - +��
	EETexture bgTex(L"Texture\\������\\�����汳��.jpg");
	EEScene *mainScene = new EEScene(Rect_Float(100, 100, (float)EEGetWidth(), (float)EEGetHeight()), bgTex);
	mainScene->SetLocalZOrder(1.0f);

	//order 0, time 0 - +��
	EETexture nameTex(L"Texture\\������\\��Ϸ����.png");
	EEQuad *nameQuad = new EEQuad(Rect_Float(70, 170, 470, 270), nameTex);
	nameQuad->SetLocalZOrder(0.0f);
	nameQuad->SetAlpha(0.0f);
	EEFade(nameQuad, 1.0f, 1.0f);

	//order 0.1, time 1 - +��
	EETexture round1Tex(L"Texture\\������\\Բ��ͼ��1.png");
	EEQuad *round1Quad = new EEQuad(Rect_Float(70, 75, 370, 375), round1Tex);
	round1Quad->SetLocalZOrder(0.1f);
	round1Quad->SetAlpha(0.0f);
	EEFade(round1Quad, 1.0f, 1.0f, 1.0f);
	EERotate(round1Quad, 16.0f, 2 * EE_2PI, round1Quad->GetFinalCenter(), 1.0f);

	//order 0.1, time 2 - +��
	EETexture round2Tex(L"Texture\\������\\Բ��ͼ��2����ɫ��.png");
	EEQuad *round2Quad = new EEQuad(Rect_Float(0, 5, 440, 445), round2Tex);
	round2Quad->SetLocalZOrder(0.1f);
	round2Quad->SetAlpha(0.0f);
	EEFade(round2Quad, 1.0f, 1.0f, 2.0f);
	EERotate(round2Quad, 16.0f, - 2 * EE_2PI, round2Quad->GetFinalCenter(), 2.0f);

	//order 0.1, time 3.5 - +��
	EETexture road1Tex(L"Texture\\������\\��·��ͼ��1����ɫ��.png");
	EEQuad *road1Quad = new EEQuad(Rect_Float(300, 65, 500, 385), road1Tex);
	road1Quad->SetLocalZOrder(0.1f);
	road1Quad->SetAlpha(0.0f);
	EEFade(road1Quad, 1.0f, 1.0f, 3.5f);

	//order 0.1, time 3.0 - +��
	EETexture road2Tex(L"Texture\\������\\��·��ͼ��2����ɫ��.png");
	EEQuad *road2Quad = new EEQuad(Rect_Float(40, 45, 600, 405), road2Tex);
	road2Quad->SetLocalZOrder(0.1f);
	road2Quad->SetAlpha(0.0f);
	EEFade(road2Quad, 1.0f, 1.0f, 3.0f);

	//order 0.1, time 3.5 - +��
	EETexture TopTex(L"Texture\\������\\�Ͽ�.png");
	EEQuad *TopQuad = new EEQuad(Rect_Float(0, 0, (float)EEGetWidth(), 25.f), TopTex);
	TopQuad->SetLocalZOrder(0.1f);
	TopQuad->SetAlpha(0.0f);
	EEFade(TopQuad, 1.0f, 1.0f, 3.5);

	//order 0.1, time 3.5 - +��
	EETexture BottomTex(L"Texture\\������\\�Ͽ�.png");
	EEQuad *BottomQuad = new EEQuad(Rect_Float(0, (float)EEGetHeight() - 25.f, (float)EEGetWidth(), (float)EEGetHeight()), BottomTex);
	BottomQuad->SetLocalZOrder(0.1f);
	BottomQuad->SetAlpha(0.0f);
	EEFade(BottomQuad, 1.0f, 1.0f, 3.5);


	EETexture button1Tex(L"Texture/������/ģʽ��ǩ/����ģʽ.png");
	EEButton *button1 = new EEButton(EE_BUTTON_SCALE, Rect_Float(40.f, 380.f, 100.f, 440.f), 1.3f, 0.2f, 0.2f, button1Tex, NULL);
	button1->SetLocalZOrder(0.0f);
	button1->SetAlpha(0.0f);
	EEFade(button1, 1.0f, 1.0f, 3.5);

	EETexture button2Tex(L"Texture/������/ģʽ��ǩ/����ģʽ.png");
	EEButton *button2 = new EEButton(EE_BUTTON_SCALE, Rect_Float(120.f, 380.f, 180.f, 440.f), 1.3f, 0.2f, 0.2f, button2Tex, NULL);
	button2->SetLocalZOrder(0.0f);
	button2->SetAlpha(0.0f);
	EEFade(button2, 1.0f, 1.0f, 3.5);

	EETexture button3Tex(L"Texture/������/ģʽ��ǩ/��Ϸ�̵�.png");
	EEButton *button3 = new EEButton(EE_BUTTON_SCALE, Rect_Float(200.f, 380.f, 260.f, 440.f), 1.3f, 0.2f, 0.2f, button3Tex, NULL);
	button3->SetLocalZOrder(0.0f);
	button3->SetAlpha(0.0f);
	EEFade(button3, 1.0f, 1.0f, 3.5);

	EETexture musicFrameTex(L"Texture/������/������/ʱ����.png");
	EETexture musicProgressTex(L"Texture/������/������/����.png");
	EEProgressbar *progressbar = new EEProgressbar(Rect_Float(580.f, 335.f, 770.f, 340.f), Rect_Float(580.f, 335.f, 770.f, 340.f), musicFrameTex, musicProgressTex, NULL);



	mainScene->AddObject(round1Quad);
	mainScene->AddObject(round2Quad);
	//mainScene->AddObject(road1Quad);
	//mainScene->AddObject(road2Quad);
	mainScene->AddObject(TopQuad);
	mainScene->AddObject(BottomQuad);
	mainScene->AddObject(nameQuad);
	mainScene->AddObject(button1);
	mainScene->AddObject(button2);
	mainScene->AddObject(button3);
	mainScene->AddObject(progressbar);

	while (EERun())
	{
		EEBeginScene(EEColor::WHITE);

		progressbar->SetProgress(music.GetProgress());
		EEProcess(mainScene);

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif