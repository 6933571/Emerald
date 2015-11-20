// Bitmap Demo
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
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	EEBitmap bitmap(L"Texture\\etc\\xmyrz.jpg");
	EEQuad2D quad(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight() + 200), bitmap);
	quad.SetLocalZOrder(10.0f);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		quad.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif