// Slide Demo
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

	EETexture bgTex(L"Texture\\test.gif");
	EESlide mainScene(Rect_Float(0, 0, (float)bgTex.GetWidth(), (float)bgTex.GetHeight()), bgTex, 0.1f);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		mainScene.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif