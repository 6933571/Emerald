//LineEditer Demo
#if 0
#include "Emerald.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(int _argc, char** _argv)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";	//��������
	desc.isFullScreen = false;			//�Ƿ�ȫ��
	desc.width = 800;					//���ڿ��
	desc.height = 450;					//���ڸ߶�
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	EETexture bgTex(L"Texture\\������\\�����汳��.jpg");
	EETexture button2Tex(L"Texture/������/ģʽ��ǩ/����ģʽ.png");
	EEFont helloworld(FLOAT3(100.0f, 100.0f, 0.0f), "hello world", EEColor::YELLOW);
	EELineEditer *lineEditer = new EELineEditer(Rect_Float(200.f, 300.f, 300.f, 350.f), bgTex, EEColor::BLACK);
	EELineEditer *lineEditer2 = new EELineEditer(Rect_Float(400.f, 300.f, 500.f, 350.f), bgTex, EEColor::BLACK);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		EEShowFPSInTitle(L"- -");

		lineEditer->Process();
		lineEditer2->Process();
		helloworld.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif