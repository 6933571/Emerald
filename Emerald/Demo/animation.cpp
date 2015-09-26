//Animation Demo
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
	EESlide hitSlide(Rect_Float(-64, -64, 64, 64), hitTex, 29);
	hitSlide.SetInterval(0.05f / 29.f);
	EEAnimationFrame frame0;
	frame0.SetObject(hitSlide);
	frame0.duration = 0.05f;
	
	EEQuad2D quad1(Rect_Float(-40, -40, 40, 40), hitTex[29]);
	//quad1.SetAlpha(0.0f);
	EEAnimationFrame frame1;
	frame1.SetObject(quad1);
	frame1.duration = 0.35f;
	frame1.actions.push_back(boost::bind(EEFade, _1, 0.35f, 0.0f, _2));
	frame1.actions.push_back(boost::bind(EEScale, _1, 0.35f, 2.0f, _2));

	EEQuad2D quad2(Rect_Float(-40, -40, 40, 40), hitTex[30]);
	EEAnimationFrame frame2;
	frame2.SetObject(quad2);
	frame2.duration = 0.05f;
	frame2.actions.push_back(boost::bind(EERotateYX, _1, 0.05f, EE_2PI, _2, false));

	EEQuad2D quad3(Rect_Float(-50, -50, 50, 50), hitTex[31]);
	quad3.SetAlpha(0.8f);
	EEAnimationFrame frame3;
	frame3.SetObject(quad3);
	frame3.duration = 0.05f;
	frame3.actions.push_back(boost::bind(EEFade, _1, 0.1f, 0.0f, _2));

	EEQuad2D quad4(Rect_Float(-50, -50, 50, 50), hitTex[32]);
	EEAnimationFrame frame4;
	frame4.SetObject(quad4);
	frame4.duration = 0.07f;
	frame4.actions.push_back(boost::bind(EEFade, _1, 0.07f, 0.0f, _2));
	frame4.actions.push_back(boost::bind(EEScale, _1, 0.07f, 4.0f, _2));

	EEAnimation animation;
	animation.AddFrame(frame0);
	animation.AddFrame(frame2);
	animation.AddFrame(frame3);
	animation.AddFrame(frame1);
	animation.AddFrame(frame4);
	animation.Start();
	//animation.SetIsLoop(true);

	EEAnimationEmitter emitter;
	emitter.SetAnimation(animation);
	//emitter.Emit(FLOAT3(0.f, 0.f, 0.f));
	//emitter.Emit(FLOAT3(100.f, 100.f, 0.f));
	//emitter.Emit(FLOAT3(200.f, 0.f, 0.f));

	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);
		//EEShowFPSInTitle(L"- -");

		//animation.Process();
		
		emitter.Process();
		if (EEIsMouseInput())
		{
			EEGetMouse();
			emitter.Emit(FLOAT3(EEGetMousePosition(), 0.0f));
		}

		//printf("%d ", EEGetFPS());
		EEEndScene();
	}

	EEShutdown();
	return 0;
}

#endif