// Demo
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
	EEInitialize();

	EETexture tex0(L"Texture\\etc\\101087.jpg");
	EETexture tex1(L"Texture\\etc\\xmyrz.jpg");
	//EETexture bgTex(L"Texture\\test3.gif");

	//EETexture bgTex(L"Texture\\Project Diva Freedom\\������\\Ĭ������\\����.jpg");
	EEQuad2D quad(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), tex1);
	EEContrastAndBrightC cb(tex1);
	cb.SetContrast(200.f);
	cb.SetBright(0.1f);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		quad.Process();

		printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif