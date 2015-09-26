// Send recorder by UDP(Server)
#if 0
#include "../Emerald.h"
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

	EEUDPServer server("fe80::11ea:39a6:7ae1:187c%38", 23333);
	//EEUDPServer server("fe80::f43b:e20:d94e:a87c%10", 23333);
	//EEUDPServer server("2001:da8:215:c5c4:f43b:e20:d94e:a87c", 23333);
	//EEUDPServer server("192.168.229.1", 23333);

	sockaddr_storage addr;
	map<string, sockaddr_storage> clients;
	while (EERun())
	{
		//EEBeginScene(EEColor::BLACK);

		std::string data;
		int headpos = 0;
		int tailpos = 0;
		if (server.Recv(&addr, data))
		{
			std::string name;
			if ((headpos = data.find("<name>", headpos)) != -1)
			{
				headpos += 6;
				if ((tailpos = data.find("<name>", headpos)) != -1)
				{
					name.assign(data, headpos, tailpos - headpos);
					clients.erase(name);
					clients.insert(std::pair<string, sockaddr_storage>(name, addr));
					headpos = tailpos;
				}
			}
			for (auto client = clients.begin(); client != clients.end(); ++client)
			{
				if (client->first != name)
					server.Send(&client->second, data);
			}
		}

		//EEEndScene();
	}

	EEShutdown();
	return 0;
}







#endif