//Points Demo
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
	desc.isSSAA = true;				//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	EEPoints2D points;
	points.SetColor(EEColor::BLACK);
	points.AddPoints(EEDDALine(FLOAT2(500.f, 200.f), FLOAT2(600.f, 400.f)));
	points.AddPoints(EEBresenhamLine(FLOAT2(510.f, 200.f), FLOAT2(610.f, 400.f)));
	points.AddPoints(EEBresenhamArc(FLOAT2(510.f, 200.f), 100.f));
	points.AddPoints(EEPNArc(FLOAT2(510.f, 200.f), 80.f));
	points.AddPoints(EEEllipse(FLOAT2(100.f, 200.f), 100.f, 50.f));
	points.AddPoints(EEFillPolygon(
	{ FLOAT2(100.f, 100.f), FLOAT2(150.f, 300.f), FLOAT2(300.f, 300.f), FLOAT2(350.f, 100.f) },
	{ FLOAT2(150, 150.f), FLOAT2(160.f, 250.f), FLOAT2(290.f, 250.f), FLOAT2(300.f, 150.f) }));

	EETexture strip(L"Texture/Project Diva Freedom/����ģʽ/NOTE/Strip/Strip/Strip-Blue.png");
	std::vector<FLOAT2> pointsData;
	for (float t = 0; t < 1.0f; t += 0.001f)
		pointsData.push_back(EEBSpline(FLOAT2(100.f, 50.f), FLOAT2(200.f, 100.f), FLOAT2(300.f, 50.f), FLOAT2(400.f, 100.f), t));
	EECurve2D curve(pointsData, strip);
	curve.SetWidth(30.f);

	while (EERun())
	{
		EEBeginScene(EEColor::WHITE);

		points.Process();
		curve.Process();

		//printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif