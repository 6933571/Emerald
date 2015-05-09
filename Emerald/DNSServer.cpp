//DNS Server
#if 1
#include "Emerald.h"
#include <map>
#include <iostream>

using namespace std;

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

	EEDNSServer server("127.0.0.1", 53);

	while (EERun())
	{
		server.Process();
	}

	EEShutdown();
	return 0;
}







#endif