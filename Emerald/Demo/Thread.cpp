// Thread Demo
#if 0
#include "../Emerald.h"

using namespace std;

void test()
{
	try
	{
		while (true)
		{
			std::cout << "asd";
			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}
	}
	catch (boost::thread_interrupted&)
	{
		return;
	}
}

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

	std::cout << boost::this_thread::get_id() << std::endl;
	std::cout << boost::thread::hardware_concurrency() << std::endl;
	boost::thread *temp = new boost::thread(boost::bind(&test));
	temp->interrupt();
	//temp.detach();
	//temp.join();

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif