#if 0
#include "Emerald.h"

#define WAVEWIDTH 100

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	EEDesc desc;
	desc.applicationName = L"Emerald";  //��������
	desc.isFullScreen = false;     //�Ƿ�ȫ��
	desc.width = 800;            //���ڿ��
	desc.height = 450;           //���ڸ߶�
	desc.isSSAA = true;           //�ǿ��������
	desc.isVsync = false;          //�Ƿ�ֱͬ��
	EEInitialize(desc);

	
	EEMusic music;
	music.Open("Music/jx.mp3");
	music.SetFrequencyRatio(2.0f);
	music.Play(0.2f);
	
	

	EETexture upTex(L"Texture/����/������/CG����.png");
	EEQuad *quads[WAVEWIDTH];
	for (int i = 0; i < WAVEWIDTH; ++i)
	{
		quads[i] = new EEQuad(Rect_Float(5.f * i, 400.f, 5.f * i + 5.f, 401.f), upTex);
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
				Rect_Float rectA = quads[i + 1]->GetQuadRect();
				Rect_Float rectB = quads[i + 1]->GetQuadRect();
				rectA.y = rectB.y;
				rectA.w = rectB.w;
				quads[i + 1]->SetQuadRect(rectA);
			}
			Rect_Float rectA = quads[WAVEWIDTH - 1]->GetQuadRect();
			rectA.w = 400.f + amplitudeMax - 128;
			amplitudeMax = 128;
			rectA.y = 400.f + amplitudeMin - 128;
			amplitudeMin = 128;
			quads[WAVEWIDTH - 1]->SetQuadRect(rectA);
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