//Points Demo
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
	desc.isSSAA = false;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	std::vector<FLOAT2> pointsData;
	for (float i = 0; i < 800; ++i)
		pointsData.push_back(FLOAT2(i, 200.f));
	EEPoints2D points(pointsData);
	points.SetColor(EEColor::RED);


	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		EEShowFPSInTitle(L"- -");

		points.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif