// ScrollView Demo
#if 1
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
	EEScrollView scrollView(Rect_Float(0, 0, (float)EEGetWidth() / 2, (float)EEGetHeight() / 2));
	scrollView.SetContent(&quad);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		scrollView.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif