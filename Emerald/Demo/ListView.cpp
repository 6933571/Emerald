// ListView Demo
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
	desc.isVsync = true;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	EETexture bgTex(L"Texture\\etc\\xmyrz.jpg");
	EEQuad2D quad(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), bgTex);
	EEQuad2D quad2(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), bgTex);
	EEListView listView(Rect_Float(0, 0, (float)EEGetWidth() / 2, (float)EEGetHeight() / 2));
	listView.AddObject(&quad);
	listView.AddObject(&quad2);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		listView.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif