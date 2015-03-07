#pragma once
#ifndef _EE_TIMER_H_
#define _EE_TIMER_H_

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

//----------------------------------------------------------------------------------------------------
namespace Emerald
{
	//EETimer
	//----------------------------------------------------------------------------------------------------
	class EETimer
	{
	public:
		inline EETimer()
		{
		}

		EETimer(const EETimer&)
		{
		}

		virtual ~EETimer()
		{
			Shutdown();
		}

		bool Initialize();
		void Shutdown();

		void Start();				//��ͣ��ָ���ʱ
		void Stop();				//��ͣ
		void Reset();				//���ã���ʼ��ʱ����ʱ����ʼ����ʱ����
		void Tick();				//��ʱһ�Σ�ÿһ֡����һ��
		double GetTotalTime() const;	//���ض�ʱ���ӿ�ʼ��ʱ�����ڵ���ʱ�䣨��������ͣʱ�䣩����λ����
		double GetDeltaTime() const;	//���ر��μ�ʱ���ϴμ�ʱ֮���ʱ����λ����
		int GetFPS() const;
		void ShowFPSInTitle();
		void ShowFPSInTitle(LPCWSTR _title);

	private:
		void CountPFS();

	private:
		double	m_secsPerCount;		//ϵͳ�йأ�����ϵͳ������֮���ʱ���ֵ����λ����
		double	m_deltaTime;		//�����ϴμ�ʱ֮���ʱ����λ����
		__int64 m_baseTime;			//��ʱ����ʼ��������ʼʱ���
		__int64 m_stopTime;			//�����ǰΪ��ͣ״̬����ָ��ʱ����ʼʱ��
		__int64 m_pausedTime;		//��ͣ����ʱ���ۼ�
		__int64	m_currTime;			//���μ�ʱ��ʱ���
		__int64	m_prevTime;			//�ϴμ�ʱ��ʱ���
		bool m_isStopped;			//�Ƿ���ͣ
		int m_FPS;
	};

	//EETimer_APIs
	//----------------------------------------------------------------------------------------------------
	void EETimerStart();
	void EETimerStop();
	void EETimerReset();
	void EETimerTick();
	double EEGetTotalTime();
	double EEGetDeltaTime();
	int EEGetFPS();
	void EEShowFPSInTitle();
	void EEShowFPSInTitle(LPCWSTR _title);
}


#endif