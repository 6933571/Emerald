//Font Demo
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
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);


	EEBitmap bitmap1 = EEGetFontBitmap(L'��');
	EEBitmap bitmap2 = EEGetFontBitmap(L'?');
	EEBitmap bitmap = EEBitmapCombineHorizontal(bitmap1, bitmap2);
	std::vector<EEBitmap> bitmaps;
	EEBitmapDivideVertical(bitmap, 3, bitmaps);

	EETexture fonttex(bitmaps[1]);
	EEScene mainScene(Rect_Float(0, 0, (float)fonttex.GetWidth(), (float)fonttex.GetHeight()), fonttex);
	mainScene.SetLocalZOrder(10.0f);



	EETexture bgTex(L"Texture\\������\\�����汳��.jpg");
	EETexture button2Tex(L"Texture/������/ģʽ��ǩ/����ģʽ.png");
	EEFont helloworld(FLOAT3(100.0f, 100.0f, 0.0f), EEColor::YELLOW, "hello world");
	EELineEditer *lineEditer = new EELineEditer(Rect_Float(200.f, 300.f, 300.f, 350.f), bgTex, EEColor::BLACK);
	EELineEditer *lineEditer2 = new EELineEditer(Rect_Float(400.f, 300.f, 500.f, 350.f), bgTex, EEColor::BLACK);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		EEShowFPSInTitle(L"- -");

		mainScene.Process();
		lineEditer->Process();
		lineEditer2->Process();
		helloworld.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif