// Music Demo
#if 1
#include "../Emerald.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
int main(int _argc, char** _argv)
{
	EEMusic music;
	music.AsyncLoadMusic("Music/zhntn.mp3");
	music.SetFrequencyRatio(1.f);
	music.Start();

	//music.Open("Music/zhntn.mp3");
	//music.Play();
	//music.Play(0.5, 0.1, 2);




	EEDesc desc;
	desc.applicationName = L"Emerald";	//��������
	desc.isFullScreen = false;			//�Ƿ�ȫ��
	desc.width = 800;					//���ڿ��
	desc.height = 450;					//���ڸ߶�
	desc.isSSAA = true;					//�ǿ��������
	desc.isVsync = true;				//�Ƿ�ֱͬ��
	EEInitialize(desc);

	int sampleSize = music.GetBitsPerSample() / 8;
	float tdWidth = 1.5f;
	EEScene scene;
	std::vector<EEQuad2D> tdQuads(desc.width);
	for (auto& tdQuad : tdQuads)
	{
		tdQuad.SetPositionY((float)desc.height / 2);
		tdQuad.SetWidth(tdWidth);
		tdQuad.SetColor(EEColor::RED);
		scene.AddObject(&tdQuad);
	}
	int loopPos = 0;
	// int offset = music.GetChannels() > 1 ? 
	while (EERun())
	{
		EEBeginScene(EEColor::BLACK);

		std::string sample = music.GetCurrentSample();
		if (sample.size())
		{
			// todo: just deal with the left channel
			for (unsigned int i = 0; i < sample.size(); ++i)
			{
				tdQuads[loopPos].SetPositionX(desc.width - scene.GetPositionX());
				tdQuads[loopPos].SetHeight(sample[i]);
				scene.SetPositionX(scene.GetPositionX() - tdWidth);

				loopPos = ++loopPos % tdQuads.size();
			}
		}
		scene.Process();

		EEEndScene();
	}

	EEShutdown();
	system("pause");
	return 0;
}
#endif