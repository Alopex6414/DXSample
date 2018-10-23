/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CDXSampleCore.h
* @brief	This File is DXSample Core Class.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-23	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CDXSAMPLECORE_H_
#define __CDXSAMPLECORE_H_

//Include Windows Header File
#include <Windows.h>

//Include C/C++ Running Header File
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <mmreg.h>
#include <wchar.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>

#include <iostream>
#include <vector>
#include <map>

//Include DirectX Header File
#include "DirectCommon.h"
#include "DirectInput.h"
#include "DirectSound.h"
#include "DirectShow.h"
#include "DirectGraphics.h"
#include "DirectGraphics3D.h"
#include "DirectGraphics2D.h"
#include "DirectMesh.h"
#include "DirectTexture.h"
#include "DirectSurface.h"
#include "DirectSprite.h"
#include "DirectFont.h"

#include "CerasusUICommon.h"
#include "Cerasusfps.h"
#include "CerasusBlend.h"
#include "CerasusControl.h"
#include "CerasusElement.h"
#include "CerasusGrowArray.h"
#include "CerasusStatic.h"
#include "CerasusUnit.h"

//Include Window Basic Header File
#include "WinUtilities.h"

//Inlcude DirectX Dynamic Link Library
#pragma comment(lib, "Cerasus.lib")

//Class Definition
class CDXSampleCore
{
private:
	DirectGraphics* m_pDirectGraphicsMain;
	DirectGraphics3D* m_pDirectGraphics3DMain;

private:
	CCerasusfps* m_pCerasusfpsMain;

public:
	CDXSampleCore();		//构造函数
	~CDXSampleCore();		//析构函数

	BOOL DXSampleCoreInit();		//初始化
	void DXSampleCoreRelease();		//释放

	void DXSampleCoreUpdate();		//刷新
	void DXSampleCoreRender();		//渲染

};



#endif // !__CDXSAMPLECORE_H_

