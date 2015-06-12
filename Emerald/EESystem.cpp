#include "EESystem.h"
#include "EECore.h"

//----------------------------------------------------------------------------------------------------
namespace Emerald
{
	//EESystem
	//----------------------------------------------------------------------------------------------------
	bool EESystem::Initialize(LPCWSTR _applicationName, bool _isFullScreen, int _width, int _height)
	{
		m_applicationName = new WCHAR[wcslen(_applicationName) + 1];
		memcpy((void*)m_applicationName, _applicationName, wcslen(_applicationName) * sizeof(WCHAR) + sizeof(WCHAR));
		m_isFullScreen = _isFullScreen;
		m_width = _width;
		m_height = _height;
		m_hInstance = GetModuleHandle(NULL);
		InitWindows();

		return true;
	}

	//----------------------------------------------------------------------------------------------------
	void EESystem::Shutdown()
	{
		ShutdownWindows();
		SAFE_DELETE_ARRAY(m_applicationName);
	}

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetHInstance(HINSTANCE _para) { m_hInstance = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetHWnd(HWND _para) { m_hWnd = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetApplicationName(LPCWSTR _para) { m_applicationName = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetIsFullScreen(bool _para) { m_isFullScreen = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetWidth(int _para) { m_width = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetHeight(int _para) { m_height = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetRect(const RECT& _para) { m_rect = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetInsideCentre(const INT2& _para) { m_insideCentre = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::SetOutsideCentre(const INT2& _para) { m_outsideCentre = _para; return true; };

	//----------------------------------------------------------------------------------------------------
	HINSTANCE EESystem::GetHInstance() const { return m_hInstance; };

	//----------------------------------------------------------------------------------------------------
	HWND EESystem::GetHWnd() const { return m_hWnd; };

	//----------------------------------------------------------------------------------------------------
	LPCWSTR EESystem::GetApplicationName() const { return m_applicationName; };

	//----------------------------------------------------------------------------------------------------
	bool EESystem::GetIsFullScreen() const { return m_isFullScreen; };

	//----------------------------------------------------------------------------------------------------
	int EESystem::GetWidth() const { return m_width; };

	//----------------------------------------------------------------------------------------------------
	int EESystem::GetHeight() const { return m_height; };

	//----------------------------------------------------------------------------------------------------
	RECT EESystem::GetRect() const { return m_rect; };

	//----------------------------------------------------------------------------------------------------
	INT2 EESystem::GetInsideCentre() const { return m_insideCentre; };

	//----------------------------------------------------------------------------------------------------
	INT2 EESystem::GetOutsideCentre() const { return m_outsideCentre; };

	//----------------------------------------------------------------------------------------------------
	void EESystem::InitWindows()
	{
		//register the windows class
		WNDCLASSEXW wc;
		wc.cbSize = sizeof(WNDCLASSEXW);						//������Ĵ�С
		wc.style = CS_HREDRAW | CS_VREDRAW;						//���ڵķ��
		wc.lpfnWndProc = WndProc;								//ָ��������ָ�룬WndProc�������ڴ���ϵͳ��Ϣ
		wc.cbClsExtra = 0;										//����������ṹ��ĸ����ֽ���
		wc.cbWndExtra = 0;										//��������ʵ����ĸ����ֽ���
		wc.hInstance = m_hInstance;								//��ģ���ʵ�����
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);					//ͼ��ľ��
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);				//���ľ��
		wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ˢ�ľ��
		wc.lpszMenuName = NULL;									//ָ��˵���ָ��
		wc.lpszClassName = m_applicationName;					//ָ�������Ƶ�ָ��
		wc.hIconSm = wc.hIcon;									//ָ�򴰿�����Сͼ��ľ��
		RegisterClassExW(&wc);

		//�豸��ʼ��(ȫ�����
		int posX;			//�������Ͻǵ�λ��X
		int posY;			//�������Ͻǵ�λ��Y

		if (m_isFullScreen)
		{
			DEVMODE dmScreenSettings;
			memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));

			dmScreenSettings.dmSize = sizeof(dmScreenSettings);
			dmScreenSettings.dmPelsWidth = (unsigned long)m_width;
			dmScreenSettings.dmPelsHeight = (unsigned long)m_height;
			dmScreenSettings.dmBitsPerPel = 32;
			dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

			posX = posY = 0;
		}
		else
		{
			posX = (GetSystemMetrics(SM_CXSCREEN) - m_width) / 2;
			posY = (GetSystemMetrics(SM_CYSCREEN) - m_height) / 2;
		}

		//create window
		m_hWnd = CreateWindowExW(
			WS_EX_APPWINDOW,										//���ڵ���չ���
			m_applicationName,										//ָ�򴰿������ֵ�ָ��
			m_applicationName,										//ָ�򴰿����ֵ�ָ��
			//WS_OVERLAPPEDWINDOW,												//���ڵķ��
			WS_POPUP,
			posX, posY,												//��������Ļ����ʾ����ʼλ��
			m_width, m_height,										//���ڵĿ�Ⱥ͸߶�
			NULL,													//ָ�򱻴������ڵĵĸ����ڵľ��
			NULL,													//�˵��ľ��
			m_hInstance,											//�봰���������ģ���ʵ�����
			NULL);													//ָ��һ��ֵ��ָ�룬��ֵ���ݸ�����WM_CREATE��Ϣ

		ShowWindow(m_hWnd, SW_SHOW);
		SetForegroundWindow(m_hWnd);
		SetFocus(m_hWnd);


		//������δ�����������������ƶ�����
		POINT lt, rb;
		GetClientRect(m_hWnd, &m_rect);  //ȡ�ô����ڲ�����
		//���������ϵ��������lt��
		lt.x = m_rect.left;
		lt.y = m_rect.top;
		//�����������������rb��
		rb.x = m_rect.right;
		rb.y = m_rect.bottom;
		//��lt��rb�Ĵ�������ת��Ϊ��Ļ����
		ClientToScreen(m_hWnd, &lt);
		ClientToScreen(m_hWnd, &rb);
		//����Ļ���������趨��������
		m_rect.left = lt.x;
		m_rect.top = lt.y;
		m_rect.right = rb.x;
		m_rect.bottom = rb.y;
		//����������ƶ�����
		ClipCursor(&m_rect);

		m_insideCentre.x = (m_rect.right - m_rect.left) / 2;
		m_insideCentre.y = (m_rect.bottom - m_rect.top) / 2;
		m_outsideCentre.x = m_rect.left + m_insideCentre.x;
		m_outsideCentre.y = m_rect.top + m_insideCentre.y;
		//ShowCursor(false);		//���������

		return;
	}

	//----------------------------------------------------------------------------------------------------
	void EESystem::ShutdownWindows()
	{
		//ShowCursor(true);     //��ʾ���

		if (m_isFullScreen)
		{
			ChangeDisplaySettingsW(NULL, 0);
		}

		DestroyWindow(m_hWnd);
		m_hWnd = NULL;

		UnregisterClassW(m_applicationName, m_hInstance);
		m_hInstance = NULL;

		return;
	}

	//----------------------------------------------------------------------------------------------------
	LRESULT CALLBACK EESystem::WndProc(HWND _hwnd, UINT _umessage, WPARAM _wparam, LPARAM _lparam)
	{
		switch (_umessage)
		{
		case WM_DESTROY:
		{
						   PostQuitMessage(0);
						   return 0;
		}
		case WM_CLOSE:
		{
						 PostQuitMessage(0);
						 return 0;
		}
		default:
		{
				   if (EECore::s_EECore->GetEEInput())
					   return (EECore::s_EECore->GetEEInput()->*EECore::s_EECore->GetInputPro())(_hwnd, _umessage, _wparam, _lparam);
				   else
					   return DefWindowProc(_hwnd, _umessage, _wparam, _lparam);
		}
		}
	}

	//EESystem_APIs
	//----------------------------------------------------------------------------------------------------
	HINSTANCE EEGetHInstance() { return EECore::s_EECore->GetEESystem()->GetHInstance(); }
	
	//----------------------------------------------------------------------------------------------------
	HWND EEGetHWnd() { return EECore::s_EECore->GetEESystem()->GetHWnd(); }
	
	//----------------------------------------------------------------------------------------------------
	LPCWSTR EEGetApplicationName() { return EECore::s_EECore->GetEESystem()->GetApplicationName(); }
	
	//----------------------------------------------------------------------------------------------------
	bool EEGetIsFullScreen() { return EECore::s_EECore->GetEESystem()->GetIsFullScreen(); }
	
	//----------------------------------------------------------------------------------------------------
	int EEGetWidth() { return EECore::s_EECore->GetEESystem()->GetWidth(); }
	
	//----------------------------------------------------------------------------------------------------
	int EEGetHeight() { return EECore::s_EECore->GetEESystem()->GetHeight(); }
	
	//----------------------------------------------------------------------------------------------------
	RECT EEGetRect() { return EECore::s_EECore->GetEESystem()->GetRect(); }
	
	//----------------------------------------------------------------------------------------------------
	INT2 EEGetInsideCentre() { return EECore::s_EECore->GetEESystem()->GetInsideCentre(); }
	
	//----------------------------------------------------------------------------------------------------
	INT2 EEGetOutsideCentre() { return EECore::s_EECore->GetEESystem()->GetOutsideCentre(); }
}