// Demo
#if 1
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

	// EETexture tex0(L"Texture\\etc\\101087.jpg");
	EETexture tex1(L"Texture\\etc\\xmyrz.jpg");
	EETexture tex1_gray = tex1.Clone();
	EEGrayC gray(tex1_gray);
	gray.Process();

	EEQuad2D quad(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), tex1);
	//EEDilateC erode(tex1, tex1_gray, INT2(12, 12));
	EEErodeC erode(tex1, tex1_gray, INT2(12, 12));
	erode.Process();

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		//erode.Process();
		quad.Process();

		printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif