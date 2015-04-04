//Animation Demo
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

	EETexture bgTex(L"Texture\\etc\\xmyrz.jpg");
	//EETexture bgTex(L"Texture\\test3.gif");

	//EETexture bgTex(L"Texture\\Project Diva Freedom\\������\\Ĭ������\\����.jpg");
	EEQuad2D quad1(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), bgTex);
	quad1.SetTexIndex(1);
	EEAnimationFrame frame1;
	frame1.object = &quad1;
	frame1.duration = 1.0f;
	frame1.actions.push_back(boost::bind(EEMoveBy, _1, 2.0f, FLOAT2(100.0f, 100.0f), _2, false));

	EEAnimation animation;
	animation.AddFrame(frame1);
	animation.Start();

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		//EEShowFPSInTitle(L"- -");

		animation.Process();

		printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif