//Send recorder by UDP(Server)
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

	EEUDPServer server("192.168.229.1", 23333);

	sockaddr_in addr;
	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		std::string data;
		if (server.Recv(&addr, data))
		{
			server.Send(&addr,data);
		}

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif