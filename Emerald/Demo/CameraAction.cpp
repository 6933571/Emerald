// CameraAction Demo
#if 0
#include "../Emerald.h"

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
	
	EETexture bgTex(L"Texture\\������\\�����汳��.jpg");
	EETexture button2Tex(L"Texture/������/ģʽ��ǩ/����ģʽ.png");
	EEBox *box = new EEBox(FLOAT3(0.0f, 0.0f, 10.0f), 10.0f, 10.f, 10.f, button2Tex);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		EEShowFPSInTitle(L"- -");

		EECameraProcess(EE_CAMERA_FIRST);
		box->Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif