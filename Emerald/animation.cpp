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

	EETexture hitTex[34] = {
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect30.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect29.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect28.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect27.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect26.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect25.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect24.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect23.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect22.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect21.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect20.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect19.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect18.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect17.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect16.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect15.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect14.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect13.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect12.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect11.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect10.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect9.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect8.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect7.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect6.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect5.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect4.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect3.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/effect2.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/hit-1�����Լ�����.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/hit-2�����Լ�����.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/hit-3�����Լ�����.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/hit-4�����Լ�����.png",
		L"Texture/Project Diva Freedom/����ģʽ/HIT/sad-01.png",
	};
	EESlide hitSlide(Rect_Float(300, 200, 428, 328), hitTex, 29);
	hitSlide.SetInterval(0.5f / 29.f);
	EEAnimationFrame frame0;
	frame0.object = &hitSlide;
	frame0.duration = 0.3f;
	
	EEQuad2D quad1(Rect_Float(300, 200, 428, 328), hitTex[29]);
	EEAnimationFrame frame1;
	frame1.object = &quad1;
	frame1.duration = 0.3f;
	//frame1.actions.push_back(boost::bind(EEMoveBy, _1, 2.0f, FLOAT2(100.0f, 100.0f), _2, false));
	

	EEAnimation animation;
	animation.AddFrame(frame0);
	animation.AddFrame(frame1);
	animation.Start();
	animation.SetIsLoop(true);

	EEAnimationEmitter emitter;
	emitter.SetAnimation(animation);
	emitter.Emit(FLOAT3(0.f, 0.f, 0.f));
	emitter.Emit(FLOAT3(100.f, 100.f, 0.f));
	emitter.Emit(FLOAT3(200.f, 0.f, 0.f));



	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		//EEShowFPSInTitle(L"- -");

		animation.Process();
		emitter.Process();

		printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif