#if 0
#include "Emerald.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(int _argc, char** _argv)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";  //��������
	desc.isFullScreen = false;     //�Ƿ�ȫ��
	desc.width = 800;            //���ڿ��
	desc.height = 450;           //���ڸ߶�
	desc.isSSAA = true;           //�ǿ��������
	desc.isVsync = false;          //�Ƿ�ֱͬ��
	EEInitialize(desc);

	EERecorder recorder;
	recorder.Start();
	recorder.Play();


	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);


		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif