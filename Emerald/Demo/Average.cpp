// Ripple Demo
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
	
	unsigned char data[5] = { 255, 2, 41, 0, 0 };
	EEBitmap bitmap(1, 1, data);
	EEAverageC *test = new EEAverageC(EETexture(bitmap));

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		test->Process();
		//int a = 1;
		//int b = 1;
		//int times = 10000000;
		//while (times--)
		//{
		//	a += times;
		//	//a += times;
		//}

		printf("%f\n", EEGetDeltaTime());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif