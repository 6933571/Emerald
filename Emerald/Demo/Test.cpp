#if 0
#include "Emerald.h"
using namespace std;

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(int _argc, char** _argv)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";	//��������
	desc.isFullScreen = false;			//�Ƿ�ȫ��
	desc.width = 480;					//���ڿ��
	desc.height = 640;					//���ڸ߶�
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	EETexture tex0(L"Texture/yangliu.jpg");

	EEQuad2D quad(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), tex0);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		quad.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif