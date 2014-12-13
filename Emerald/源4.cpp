#if 1
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

	EEFont word1(FLOAT3(100.0f, 100.0f, 0.0f), "send:", EEColor::YELLOW);
	EEFont word2(FLOAT3(100.0f, 200.0f, 0.0f), "recv:", EEColor::YELLOW);

	EETCPServer server("192.168.229.1", 23333);
	EETCPClient client("192.168.229.1", 23333);


	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		server.Process();
		char buf[100];
		memset(buf, 0x00, 100);
		std::cin >> buf;
		server.Send(buf);
		word1.AddText(buf);
		std::string asd;
		client.Recv(asd);
		word2.AddText(asd.c_str());
		word1.Process();
		word2.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif