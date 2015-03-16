//Ripple Demo
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
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	//EETexture bgTex(L"Texture\\etc\\xmyrz.jpg");
	EETexture bgTex(L"Texture\\test3.gif");
	
	//EETexture bgTex(L"Texture\\Project Diva Freedom\\������\\Ĭ������\\����.jpg");
	EEScene mainScene(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), bgTex);
	mainScene.SetTexIndex(1);
	EERippleC ripple(bgTex);
	//ripple.Disturb((int)(100.f / 800.f * bgTex.GetWidth()), (int)(100.f / 450.f * bgTex.GetHeight()), 10, 256);
	
	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		//EEShowFPSInTitle(L"- -");

		
		if (EECore::s_EECore->IsKeyDown(VK_LBUTTON))
		{
			Point pos = EEGetMousePosition();
			ripple.Disturb((int)(pos.x / 800.f * bgTex.GetWidth()), (int)(pos.y / 450.f * bgTex.GetHeight()), 10, 256);
		}
		ripple.Process();
		
		mainScene.Process();

		printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif