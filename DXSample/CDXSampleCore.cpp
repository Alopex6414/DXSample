/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CDXSampleCore.cpp
* @brief	This File is DXSample Core Class.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-23	v1.00a	alopex	Create Project.
*/
#include "CDXSampleCore.h"

//CDXSampleCore ���캯��
CDXSampleCore::CDXSampleCore()
{
	m_pDirectGraphicsMain = NULL;
	m_pDirectGraphics3DMain = NULL;
	m_pCerasusfpsMain = NULL;
	m_pCerasusStatic = NULL;
}

//CDXSampleCore ��������
CDXSampleCore::~CDXSampleCore()
{
	SAFE_DELETE(m_pCerasusStatic);
	SAFE_DELETE(m_pCerasusfpsMain);
	SAFE_DELETE(m_pDirectGraphics3DMain);
	SAFE_DELETE(m_pDirectGraphicsMain);
}

//CDXSampleCore ��ʼ��
BOOL CDXSampleCore::DXSampleCoreInit()
{
	HRESULT hr;
	IDirect3DDevice9* pD3D9Device = NULL;

	//DirectGraphics ��ʼ��
	m_pDirectGraphicsMain = new DirectGraphics;
	hr = m_pDirectGraphicsMain->DirectGraphicsInit(g_hWnd, true, USER_SCREENWIDTH, USER_SCREENHEIGHT);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("Direct3D��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	hr = m_pDirectGraphicsMain->DirectGraphicsFontInit(20);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("DirectFont��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	pD3D9Device = m_pDirectGraphicsMain->DirectGraphicsGetDevice();

	//DirectGraphics3D ��ʼ��
	m_pDirectGraphics3DMain = new DirectGraphics3D(pD3D9Device);
	hr = m_pDirectGraphics3DMain->DirectGraphics3DInitVertex3DBase(6);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("DirectGraphics3D��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	//Cerasusfps��ʼ��
	m_pCerasusfpsMain = new CCerasusfps(pD3D9Device);
	hr = m_pCerasusfpsMain->CCerasusfpsInit(20);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("Cerasusfps��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	//CerasusStatic��ʼ��

	return TRUE;
}

//CDXSampleCore �ͷ�
void CDXSampleCore::DXSampleCoreRelease()
{
	SAFE_DELETE(m_pCerasusStatic);
	SAFE_DELETE(m_pCerasusfpsMain);
	SAFE_DELETE(m_pDirectGraphics3DMain);
	SAFE_DELETE(m_pDirectGraphicsMain);
}

//CDXSampleCore ˢ��
void CDXSampleCore::DXSampleCoreUpdate()
{
	HRESULT hr;
	IDirect3DSurface9* pD3D9Surface = NULL;

	hr = m_pDirectGraphicsMain->DirectGraphicsTestCooperativeLevel();
	if (hr != S_OK)
	{
		if (hr == D3DERR_DEVICELOST)
		{
			return;
		}

		if (hr == D3DERR_DEVICENOTRESET)
		{
			m_pCerasusfpsMain->CCerasusfpsReset();
			m_pDirectGraphics3DMain->DirectGraphics3DReset();

			m_pDirectGraphicsMain->DirectGraphicsReset();

			m_pDirectGraphics3DMain->DirectGraphics3DInitVertex3DBase(6);
		}

	}
}

//CDXSampleCore ��Ⱦ
void CDXSampleCore::DXSampleCoreRender()
{
	IDirect3DDevice9* pD3D9Device = NULL;
	RECT Rect;

	GetClientRect(g_hWnd, &Rect);
	pD3D9Device = m_pDirectGraphicsMain->DirectGraphicsGetDevice();

	m_pDirectGraphicsMain->DirectGraphicsBegin();

	//��Ⱦģʽ:Alpha�������
	pD3D9Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);					//Alpha��Ͽ���

	//��Ⱦģʽ:����������
	pD3D9Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_DISABLE);

	m_pDirectGraphics3DMain->DirectGraphics3DRenderStateLightDisable();
	m_pDirectGraphics3DMain->DirectGraphics3DRenderStateSetting();
	m_pDirectGraphics3DMain->DirectGraphics3DRenderStateAlphaDisable();

	DXSampleCoreDrawStatic();
	DXSampleCoreDrawFPS();

	m_pDirectGraphicsMain->DirectGraphicsEnd();
}

//CDXSampleCore ���ƾ�̬�ı�
void CDXSampleCore::DXSampleCoreDrawStatic()
{
	RECT Rect;

	GetClientRect(g_hWnd, &Rect);

	//Direct3D �����Կ���Ϣ
	Rect.top += 0;
	m_pDirectGraphicsMain->DirectGraphicsFontDrawTextAdapterType(&Rect, DT_TOP | DT_LEFT, D3DXCOLOR(1.0f, 0.5f, 0.5f, 1.0f));

	//Direct3D ������Ļ�ֱ���
	Rect.top += 20;
	m_pDirectGraphicsMain->DirectGraphicsFontDrawTextScreen(&Rect, DT_TOP | DT_LEFT, D3DXCOLOR(1.0f, 1.0f, 0.5f, 1.0f));

	//Direct3D ���ƻ���ģ��
	Rect.top += 20;
	m_pDirectGraphicsMain->DirectGraphicsFontDrawTextFormat(&Rect, DT_TOP | DT_LEFT, D3DXCOLOR(1.0f, 1.0f, 0.5f, 1.0f));

}

//CDXSampleCore ����fps
void CDXSampleCore::DXSampleCoreDrawFPS()
{
	m_pCerasusfpsMain->CCerasusfpsGetfps();				//Direct3D���ƾ�̬��Ϣ
	m_pCerasusfpsMain->CCerasusfpsDrawfps(g_hWnd);		//Direct3D����fps
}

