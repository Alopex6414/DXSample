/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		Cerasusfps.h
* @brief	This File is Cerasusfps Dynamic Link Library Project.
* @author	alopex
* @version	v1.03a
* @date		2018-06-09	v1.00a	alopex	Create This File.
* @date		2018-06-22	v1.01a	alopex	Add Version Information.
* @date		2018-06-26	v1.02a	alopex	Modify Call Mode.
* @date		2018-11-23	v1.03a	alopex	Alter Call Method.
*/
#pragma once

#ifndef __CERASUSFPS_H_
#define __CERASUSFPS_H_

//Include DirectX Common Header File
#include "DirectCommon.h"
#include "DirectFont.h"
#include "DirectThreadSafe.h"

//Macro Definition
#ifdef CERASUS_EXPORTS
#define CERASUSFPS_API	__declspec(dllexport)
#else
#define CERASUSFPS_API	__declspec(dllimport)
#endif

#define CERASUSFPS_CALLMETHOD	__stdcall

//Class Definition
class CERASUSFPS_API CCerasusfps
{
private:
	DirectFont* m_pFont;	//Cerasusfps DirectFont(字体样式)

	CRITICAL_SECTION m_cs;	//Cerasusfps Thread Safe(CriticalSection)
	bool m_bThreadSafe;		//Cerasusfps Thread Safe Status
	
private:
	float m_ffps;			//Cerasusfps Frame Per Second(帧速率)

public:
	CCerasusfps();			//Cerasusfps Constructor Function(构造函数)
	~CCerasusfps();			//Cerasusfps Destructor Function(析构函数)

	CCerasusfps(IDirect3DDevice9* pD3D9Device);	//Cerasusfps Constructor Function(构造函数)(重载+1)

	//访问
	DirectFont* CERASUSFPS_CALLMETHOD CCerasusfpsGetFont() const;		//Cerasusfps Get Font(获取字体类)
	float CERASUSFPS_CALLMETHOD CCerasusfpsGetFps() const;				//Cerasusfps Get Fps(获取fps值)

	//控制
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsSetFont(DirectFont* pFont);	//Cerasusfps Set Font(设置字体类)

	//重置
	HRESULT CERASUSFPS_CALLMETHOD CCerasusfpsReset();					//Cerasusfps Reset(D3D丢失设备Reset)

	//初始化
	HRESULT CERASUSFPS_CALLMETHOD CCerasusfpsInit(int nFontSize);							//Cerasusfps Initialize(初始化)
	HRESULT CERASUSFPS_CALLMETHOD CCerasusfpsInit(int nFontSize, LPWSTR lpszFontType);		//Cerasusfps Initialize(初始化)(重载+1)

	//计算
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsGetfps();											//Cerasusfps Calculate Fps(计算fps)
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsGetfpsEx(float fTimeDelta, float* pfps);			//Cerasusfps Calculate Fps Ex(计算fps)
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsGetfpsEx(float* pfps);							//Cerasusfps Calculate Fps Ex(计算fps)(重载+1)
	float CERASUSFPS_CALLMETHOD CCerasusfpsGetfpsEx(float fTimeDelta);						//Cerasusfps Calculate Fps Ex(计算fps)(重载+2)
	float CERASUSFPS_CALLMETHOD CCerasusfpsGetfpsEx();										//Cerasusfps Calculate Fps Ex(计算fps)(重载+3)

	//绘制
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsDrawfps(HWND hWnd);								//Cerasusfps Draw Fps(绘制fps)
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsDrawfps(HWND hWnd, DWORD Format);					//Cerasusfps Draw Fps(绘制fps)(重载+1)
	VOID CERASUSFPS_CALLMETHOD CCerasusfpsDrawfps(HWND hWnd, DWORD Format, D3DCOLOR Color);	//Cerasusfps Draw Fps(绘制fps)(重载+2)
};


#endif // !__CERASUSFPS_H_

