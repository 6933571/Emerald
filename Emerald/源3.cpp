#if 1
#include "Emerald.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
//int main(int _argc, char** _argv)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";  //��������
	desc.isFullScreen = false;     //�Ƿ�ȫ��
	desc.width = 800;            //���ڿ��
	desc.height = 450;           //���ڸ߶�
	desc.isSSAA = true;           //�ǿ��������
	desc.isVsync = false;          //�Ƿ�ֱͬ��
	EEInitialize(desc);

	EEFont helloworld(FLOAT3(100.0f, 100.0f, 0.0f), "hello world", EEColor::YELLOW);


	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		helloworld.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif