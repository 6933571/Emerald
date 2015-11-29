// Demo
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
	EEInitialize();

	EEBitmap src(L"Texture\\etc\\xmyrz.jpg");
	EECharacterGenerator generator;

	std::string resultString;
	generator.Generate(src, resultString);

	EESetFontHeight(2);
	EEBitmap result = EEGetFontBitmap(resultString.data());

	std::ofstream fout("test.txt");
	fout << resultString;
	fout.close();

	EEQuad2D quad(Rect_Float(0, 0, (float)EEGetWidth(), (float)EEGetHeight()), result);
	quad.SetIsUseColor(true);
	quad.SetColor(EEColor::BLACK);

	while (EERun())
	{
		EEBeginScene(EEColor::WHITE);

		quad.Process();

		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif