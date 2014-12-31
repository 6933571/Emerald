//Music Demo
#if 0
#include "Emerald.h"

#define WAVEWIDTH 100

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";	//��������
	desc.isFullScreen = false;			//�Ƿ�ȫ��
	desc.width = 800;					//���ڿ��
	desc.height = 450;					//���ڸ߶�
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = false;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	
	EEMusic music;
	music.Open("Music/jx.mp3");
	music.SetFrequencyRatio(2.0f);
	music.Play(0.2f);
	
	

	EETexture upTex(L"Texture/����/������/CG����.png");
	EEQuad2D *quads[WAVEWIDTH];
	for (int i = 0; i < WAVEWIDTH; ++i)
	{
		quads[i] = new EEQuad2D(Rect_Float(5.f * i, 400.f, 5.f * i + 5.f, 401.f), upTex);
	}

	int num = music.GetSampled();
	short amplitudeMax = 128;
	short amplitudeMin = 128;

	while (EERun())
	{
		EEShowFPSInTitle(L"- -");
		EEBeginScene(EEColor::WHITE);

		if (num < music.GetSampled())
		{
			int delta = music.GetSampled() - num;
			while (delta--)
			{
				short data = *(short*)music.GetSampleData(num + delta) / 256;
				if (amplitudeMax < data)
					amplitudeMax = data;
				if (amplitudeMin > data)
					amplitudeMin = data;
			}

			for (int i = 0; i < WAVEWIDTH - 1; ++i)
			{
				Rect_Float rectA = quads[i + 1]->GetRect();
				Rect_Float rectB = quads[i + 1]->GetRect();
				rectA.y = rectB.y;
				rectA.w = rectB.w;
				quads[i + 1]->SetRect(rectA);
			}
			Rect_Float rectA = quads[WAVEWIDTH - 1]->GetRect();
			rectA.w = 400.f + amplitudeMax - 128;
			amplitudeMax = 128;
			rectA.y = 400.f + amplitudeMin - 128;
			amplitudeMin = 128;
			quads[WAVEWIDTH - 1]->SetRect(rectA);
		}

		for (int i = 0; i < WAVEWIDTH; ++i)
		{
			EEProcess(quads[i]);
		}

		EEEndScene();
	}

	EEShutdown();
	return 0;
}
#endif