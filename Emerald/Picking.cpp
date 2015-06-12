//Picking Demo
#if 1
#include "Emerald.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(int _argc, char** _argv)
{
	EEAxisAlignedBox qwe;

	EEDesc desc;
	desc.applicationName = L"Emerald";	//��������
	desc.isFullScreen = false;			//�Ƿ�ȫ��
	desc.width = 800;					//���ڿ��
	desc.height = 450;					//���ڸ߶�
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	EETexture tex(L"Texture\\etc\\xmyrz.jpg");
	EETexture tex0(L"Texture/������/�����汳��.jpg");
	EETexture tex1(L"Texture/������/ģʽ��ǩ/����ģʽ.png");
	EEBox box(FLOAT3(50.0f, 20.0f, 10.0f), 10.0f, 10.f, 10.f, tex);
	EESphere sphere(20.f, 100, 100, tex1);
	sphere.SetPosition(FLOAT3(-50.0f, 20.0f, 10.0f));
	EEGrid grid(200.f, 200.f, 100, 100);
	grid.SetColor(EEColor::RED);
	grid.SetPosition(FLOAT3(0.f, -40.0f, 10.0f));
	EECylinder cylinder(10.f, 20.f, 20.f, 50, 50, tex0);
	cylinder.SetPosition(FLOAT3(0.0f, -20.0f, 10.0f));
	EETexture tex2(L"Mesh/model.jpg");
	EEPolyhedron polyhedron(L"Mesh/model.txt", tex2);
	polyhedron.SetPosition(FLOAT3(0.0f, 0.0f, 10.0f));

	FLOAT3 position = EEGetCameraPosition();
	FLOAT3 look = EEGetCameraLook();

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		//EEShowFPSInTitle(L"- -");

		EECameraProcess(EE_CAMERA_FIRST);
		box.Process();
		sphere.Process();
		grid.Process();
		cylinder.Process();
		polyhedron.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif