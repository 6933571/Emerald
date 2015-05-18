//AnimationEditer Demo
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

	EEAnimationEmitter *emitter = new EEAnimationEmitter();
	std::vector<EEAnimationFrame*> target = emitter->GetAnimation()->GetFrames();

	EETexture button1Tex(L"Texture/Project Diva Freedom\\������\\Ĭ������/����ģʽ.png");
	EEButton addItem(EE_BUTTON_SCALE, Rect_Float((float)EEGetWidth() * 0.03f, (float)EEGetHeight() * 0.8489f, (float)EEGetWidth() * 0.1075f, (float)EEGetHeight() * 0.9856f), 1.3f, 0.2f, 0.2f, button1Tex);
	EEComboBox *combo = new EEComboBox(Rect_Float(100.f, 300.f, 200.f, 320.f), EEColor::WHITE, EEColor::BLACK);

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		addItem.Process();
		combo->Process();
		if (EEIsMouseInput())
		{
			EEGetMouse();
			emitter->Emit(FLOAT3(EEGetMousePosition(), 0.0f));
		}
		emitter->Process();

		EEEndScene();
	}
	SAFE_DELETE(emitter);

	EEShutdown();
	return 0;
}

#endif