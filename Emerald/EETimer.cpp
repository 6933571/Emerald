#include "EETimer.h"
#include "EECore.h"

namespace Emerald
{
	//EETimer
	//----------------------------------------------------------------------------------------------------
	bool EETimer::Initialize()
	{
		__int64 frequency;
		//�ռ�ϵͳ��Ϣ����ʼ��������֮���ʱ���
		QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
		m_secsPerCount = 1.f / frequency;
		m_deltaTime = 0.f;
		m_baseTime = 0;
		m_stopTime = 0;
		m_pausedTime = 0;
		m_currTime = 0;
		m_prevTime = 0;
		m_isStopped = false;

		Tick();

		return true;
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::Shutdown()
	{
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::Start()
	{
		//��ͣ�ָ�
		//�����������ͣ״̬���򲻲���
		//���Ϊ��ͣ״̬
		if (m_isStopped)
		{
			//�Ȼ�ȡ��ʼʱ��
			__int64 startTime;
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&startTime));

			//�ѱ�����ͣʱ���ۼƵ�����ͣʱ����
			m_pausedTime += (startTime - m_stopTime);
			m_prevTime = startTime;
			m_stopTime = 0;
			m_isStopped = false;
		}
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::Stop()
	{
		if (!m_isStopped)
		{
			__int64 curr;
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curr));
			m_stopTime = curr;
			m_isStopped = true;
		}
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::Reset()
	{
		//���ö�ʱ�������빤��״̬
		__int64 curr;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curr));
		//ȷ����ʼʱ��
		m_baseTime = curr;
		m_currTime = curr;
		m_prevTime = curr;
		m_deltaTime = 0.f;

		m_stopTime = 0;
		//��ͣ�ۼ�����
		m_pausedTime = 0;
		m_isStopped = false;
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::Tick()
	{
		//if (EECore::s_EECore->GetControlMutex())
		//	boost::unique_lock<boost::shared_mutex> lock(*EECore::s_EECore->GetControlMutex());
		//ÿ֡���õļ�ʱ����
		//���ڸ��¶�ʱ��״̬

		//���Ϊ��ͣ״̬���򲻲���
		if (m_isStopped)
		{
			m_deltaTime = 0.f;
			return;
		}

		//�Ȼ�ȡ��ǰʱ��
		__int64 curr;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curr));
		m_currTime = curr;
		//���������һ�μ�ʱ��ʱ���
		m_deltaTime = (m_currTime - m_prevTime)*m_secsPerCount;
		//ȷ��Ϊ����(��ʵһ������²�����Ϊ��)
		m_deltaTime = m_deltaTime<0 ? 0.f : m_deltaTime;

		//���ϴ�ʱ�����Ϊ����ʱ�䣬���´�Tick��
		m_prevTime = m_currTime;

		CountPFS();
	}

	//----------------------------------------------------------------------------------------------------
	double EETimer::GetTotalTime() const
	{
		//�������ͣ״̬������ͼ��ʾ��
		//	��ʼʱ��T0			��ͣ��ʼʱ��S	��ǰʱ��T
		//		|---------------------|------------|
		//�ܵ�ʱ��Ϊ:S - T0 - ��ͣ���ۼ�ʱ��
		//ע��Ѽ���ת��Ϊ��
		if (m_isStopped)
		{
			return (m_stopTime - m_baseTime - m_pausedTime)*m_secsPerCount;
		}
		//���������״̬
		//	��ʼʱ��T0							��ǰʱ��T
		//		|----------------------------------|
		//�ܵ�ʱ��Ϊ��T - T0 - ��ͣ���ۼ�ʱ��
		//ע��Ѽ���ת��Ϊ��
		else
		{
			return (m_currTime - m_baseTime - m_pausedTime)*m_secsPerCount;
		}
	}

	//----------------------------------------------------------------------------------------------------
	double EETimer::GetDeltaTime() const
	{
		//�������ϴμ�ʱ�м��ʱ���
		return m_deltaTime;
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::ShowFPSInTitle()
	{
		static int tmp = 0;
		if (tmp != m_FPS)
		{
			tmp = m_FPS;
			wchar_t text[50];
			swprintf_s(text, L"%s%d", L"FPS:", m_FPS);
			SetWindowTextW(EECore::s_EECore->GetHWnd(), text);
		}
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::ShowFPSInTitle(LPCWSTR _title)
	{
		static int tmp = 0;
		if (tmp != m_FPS)
		{
			tmp = m_FPS;
			wchar_t text[50];
			swprintf_s(text, L"%s\t%s%d ", _title, L"FPS:", m_FPS);
			SetWindowTextW(EECore::s_EECore->GetHWnd(), text);
		}
	}

	//----------------------------------------------------------------------------------------------------
	void EETimer::CountPFS()
	{
		static float begin = (float)GetTotalTime();
		static int frameCounter = 0;
		if ((float)GetTotalTime() - begin >= 1.f)
		{
			m_FPS = frameCounter;
			begin = (float)GetTotalTime();
			frameCounter = 0;
		}
		++frameCounter;
	}

	//EETimer_APIs
	//----------------------------------------------------------------------------------------------------
	void EETimerStart() { EECore::s_EECore->GetEETimer()->Start(); };

	//----------------------------------------------------------------------------------------------------
	void EETimerStop() { EECore::s_EECore->GetEETimer()->Stop(); };

	//----------------------------------------------------------------------------------------------------
	void EETimerReset() { EECore::s_EECore->GetEETimer()->Reset(); };

	//----------------------------------------------------------------------------------------------------
	void EETimerTick() { EECore::s_EECore->GetEETimer()->Tick(); };

	//----------------------------------------------------------------------------------------------------
	double EEGetTotalTime() { return EECore::s_EECore->GetEETimer()->GetTotalTime(); };

	//----------------------------------------------------------------------------------------------------
	double EEGetDeltaTime() { return EECore::s_EECore->GetEETimer()->GetDeltaTime(); };

	//----------------------------------------------------------------------------------------------------
	void EEShowFPSInTitle() { EECore::s_EECore->GetEETimer()->ShowFPSInTitle(); };

	//----------------------------------------------------------------------------------------------------
	void EEShowFPSInTitle(LPCWSTR _title) { EECore::s_EECore->GetEETimer()->ShowFPSInTitle(_title); };
}