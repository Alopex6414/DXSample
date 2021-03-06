/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CreasusUnit.h
* @brief	This File is CreasusUnit DLL Project.
* @author	Alopex/Helium
* @version	v1.07a
* @date		2018-07-04	v1.00a	alopex	Create Project.
* @date		2018-07-05	v1.01a	alopex	Add Get&Set Function.
* @date		2018-07-05	v1.02a	alopex	Add Translate Function.
* @date		2018-07-06	v1.03a	alopex	Modify Para.
* @date		2018-07-14	v1.04a	alopex	Modify Function.
* @date		2018-07-14	v1.05a	alopex	Add Texture Create In Memory Function.
* @date		2018-11-04	v1.06a	alopex	Add LostDevice ReCreate Method.
* @date		2018-11-23	v1.07a	alopex	Alter Call Method.
*/
#pragma once

#ifndef __CERASUSUNIT_H_
#define __CERASUSUNIT_H_

//Include Direct Common Header File
#include "DirectCommon.h"
#include "DirectGraphics3D.h"
#include "DirectThreadSafe.h"

//Macro Definition
#ifdef	CERASUS_EXPORTS
#define CERASUSUNIT_API	__declspec(dllexport)
#else
#define CERASUSUNIT_API	__declspec(dllimport)
#endif

#define CERASUSUNIT_CALLMETHOD	__stdcall

//Struct Definition
typedef struct
{
	UINT nScreenWidth;			//窗口宽度
	UINT nScreenHeight;			//窗口高度
	LPWSTR pTextureStr;			//纹理路径
	UINT nTextureWidth;			//纹理宽度
	UINT nTextureHeight;		//纹理高度
	RECT rcUnit;				//图元矩形
	RECT rcUnitTex;				//纹理矩形
	float fUnitAlpha;			//Alpha值
	DG3D_CoordsTransformPara sCoordsTransformPara;	//坐标变换
} CUUint, *LPCUUint;

typedef struct
{
	UINT nScreenWidth;			//窗口宽度
	UINT nScreenHeight;			//窗口高度
	LPVOID pTextureArr;			//纹理数组地址
	UINT nTextureArrSize;		//纹理数组长度
	UINT nTextureWidth;			//纹理宽度
	UINT nTextureHeight;		//纹理高度
	RECT rcUnit;				//图元矩形
	RECT rcUnitTex;				//纹理矩形
	float fUnitAlpha;			//Alpha值
	DG3D_CoordsTransformPara sCoordsTransformPara;	//坐标变换
} CUUintEx, *LPCUUintEx;

//Class Definition
class CERASUSUNIT_API CCerasusUnit
{
protected:
	DirectGraphics3D* m_pDirectGraphics3D;					//The DirectGraphics3D Class Interface(~CCerasusUnit 3D绘制单元)

private:
	CRITICAL_SECTION m_cs;									//Thread Safe(CriticalSection)
	bool m_bThreadSafe;										//Thread Safe Status

public:
	UINT m_nScreenWidth;									//CCerasusUnit Window Screen Width(~CCerasusUnit 窗口宽度)
	UINT m_nScreenHeight;									//CCerasusUnit Window Screen Height(~CCerasusUnit 窗口高度)
	LPWSTR m_pTextureStr;									//CCerasusUnit Texture String Path(~CCerasusUnit 纹理路径)
	LPVOID m_pTextureArr;									//CCerasusUnit Texture In Memory Array(~CCerasusUnit 纹理数组地址)
	UINT m_nTextureArrSize;									//CCerasusUnit Texture In Memory Array Size(~CCerasusUnit 纹理数组长度)
	UINT m_nTextureWidth;									//CCerasusUnit Texture Width(~CCerasusUnit 加载纹理宽度)
	UINT m_nTextureHeight;									//CCerasusUnit Texture Height(~CCerasusUnit 加载纹理高度)
	RECT m_rcUnit;											//CCerasusUnit Unit Rect(~CCerasusUnit 图元矩形位置)
	RECT m_rcUnitTex;										//CCerasusUnit Unit Texture Rect(~CCerasusUnit 纹理矩形位置)
	float m_fUnitAlpha;										//CCerasusUnit Unit Alpha(~CCerasusUnit 图元Alpha值)

	DG3D_CoordsTransformPara m_sCoordsTransformPara;		//CCerasusUnit Unit Coords Transform Para(~CCerasusUnit 图元坐标变换参数)

public:
	CCerasusUnit();											//CCerasusUnit Constructor Function(~CCerasusUnit 构造函数)
	~CCerasusUnit();										//CCerasusUnit Destructor Function(~CCerasusUnit 析构函数)

	//构造
	CCerasusUnit(const CCerasusUnit& Object);				//CCerasusUnit Constructor Function(~CCerasusUnit 构造函数)(重载+1)
	CCerasusUnit(IDirect3DDevice9* pD3D9Device);			//CCerasusUnit Constructor Function(~CCerasusUnit 构造函数)(重载+2)

	//访问
	virtual DirectGraphics3D* CERASUSUNIT_CALLMETHOD CCerasusUnitGetDirectGraphics3D() const;					//CCerasusUnit Get DirectGraphics3D(~CCerasusUnit 获取DirectGraphics3D接口指针)

	virtual UINT CERASUSUNIT_CALLMETHOD CCerasusUnitGetScreenWidth() const;										//CCerasusUnit Get Screen Width(~CCerasusUnit 获取屏幕宽度)
	virtual UINT CERASUSUNIT_CALLMETHOD CCerasusUnitGetScreenHeight() const;									//CCerasusUnit Get Screen Height(~CCerasusUnit 获取屏幕高度)
	virtual LPWSTR CERASUSUNIT_CALLMETHOD CCerasusUnitGetTextureStr() const;									//CCerasusUnit Get Texture Path(~CCerasusUnit 获取纹理路径)
	virtual UINT CERASUSUNIT_CALLMETHOD CCerasusUnitGetTextureWidth() const;									//CCerasusUnit Get Texture Width(~CCerasusUnit 获取纹理宽度)
	virtual UINT CERASUSUNIT_CALLMETHOD CCerasusUnitGetTextureHeight() const;									//CCerasusUnit Get Texture Height(~CCerasusUnit 获取纹理高度)
	virtual RECT CERASUSUNIT_CALLMETHOD CCerasusUnitGetUnitRect() const;										//CCerasusUnit Get Unit Rect(~CCerasusUnit 图元形状)
	virtual RECT CERASUSUNIT_CALLMETHOD CCerasusUnitGetUnitTextureRect() const;									//CCerasusUnit Get Unit Texture Rect(~CCerasusUnit 图元纹理形状)
	virtual float CERASUSUNIT_CALLMETHOD CCerasusUnitGetUnitAlpha() const;										//CCerasusUnit Get Unit Alpha(~CCerasusUnit 图元Alpha)
	virtual DG3D_CoordsTransformPara CERASUSUNIT_CALLMETHOD CCerasusUnitGetTransform() const;					//CCerasusUnit Get Transform(~CCerasusUnit 坐标变换矩阵)

	//控制
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitSetDirectGraphics3D(DirectGraphics3D* pDirectGraphics3D);	//CCerasusUnit Set DirectGraphics3D(~CCerasusUnit 设置DirectGraphics3D接口指针)

	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetScreenWidth(UINT);										//CCerasusUnit Set Screen Width(~CCerasusUnit 获取屏幕宽度)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetScreenHeight(UINT);										//CCerasusUnit Set Screen Height(~CCerasusUnit 获取屏幕高度)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetTextureStr(LPWSTR);										//CCerasusUnit Set Texture Path(~CCerasusUnit 获取纹理路径)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetTextureWidth(UINT);										//CCerasusUnit Set Texture Width(~CCerasusUnit 获取纹理宽度)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetTextureHeight(UINT);										//CCerasusUnit Set Texture Height(~CCerasusUnit 获取纹理高度)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetUnitRect(RECT);											//CCerasusUnit Set Unit Rect(~CCerasusUnit 图元形状)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetUnitTextureRect(RECT);									//CCerasusUnit Set Unit Texture Rect(~CCerasusUnit 图元纹理形状)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetUnitAlpha(float);										//CCerasusUnit Set Unit Alpha(~CCerasusUnit 图元Alpha)
	virtual VOID CERASUSUNIT_CALLMETHOD CCerasusUnitSetTransform(DG3D_CoordsTransformPara);						//CCerasusUnit Set Transform(~CCerasusUnit 坐标变换矩阵)

	//变换
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetScaleX();												//CCerasusUnit Get WorldTransform Scale(~CCerasusUnit 比例变换X)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetScaleY();												//CCerasusUnit Get WorldTransform Scale(~CCerasusUnit 比例变换Y)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetScaleZ();												//CCerasusUnit Get WorldTransform Scale(~CCerasusUnit 比例变换Z)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetRotateX();												//CCerasusUnit Get WorldTransform Rotate(~CCerasusUnit 旋转变换X)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetRotateY();												//CCerasusUnit Get WorldTransform Rotate(~CCerasusUnit 旋转变换Y)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetRotateZ();												//CCerasusUnit Get WorldTransform Rotate(~CCerasusUnit 旋转变换Z)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetTranslateX();											//CCerasusUnit Get WorldTransform Translate(~CCerasusUnit 位移变换X)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetTranslateY();											//CCerasusUnit Get WorldTransform Translate(~CCerasusUnit 位移变换Y)
	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetTranslateZ();											//CCerasusUnit Get WorldTransform Translate(~CCerasusUnit 位移变换Z)

	virtual float& CERASUSUNIT_CALLMETHOD CCerasusUnitGetAlpha();												//CCerasusUnit Get Unit Alpha(~CCerasusUnit Alpha)

	//重置
	virtual HRESULT CERASUSUNIT_CALLMETHOD CCerasusUnitReset();													//CCerasusUnit Reset(~CCerasusUnit 重置)
	virtual HRESULT CERASUSUNIT_CALLMETHOD CCerasusUnitReCreate();												//CCerasusUnit ReCreate(~CCerasusUnit 丢失设备重新初始化)

	//初始化
	virtual HRESULT CERASUSUNIT_CALLMETHOD CCerasusUnitInit(CUUint sUnit);										//CCerasusUnit Init(~CCerasusUnit 初始化)
	virtual HRESULT CERASUSUNIT_CALLMETHOD CCerasusUnitInit(CUUintEx sUnit);									//CCerasusUnit Init(~CCerasusUnit 初始化)

	//填充顶点索引
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitPaddingVertexAndIndex();									//CCerasusUnit PaddingVertexAndIndex(~CCerasusUnit 填充顶点索引)

	//矩阵变换
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitMatrixTransform();											//CCerasusUnit MatrixTransform(~CCerasusUnit 矩阵变换)

	//设置渲染状态
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitSetAlphaBlendEnable();										//CCerasusUnit Set Alpha Blend Enable(~CCerasusUnit 设置Alpha渲染开启)
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitSetAlphaBlendDisable();										//CCerasusUnit Set Alpha Blend Disable(~CCerasusUnit 设置Alpha渲染关闭)
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitSetRenderState();											//CCerasusUnit Set Render States(~CCerasusUnit 设置渲染状态)

	//绘制
	virtual void CERASUSUNIT_CALLMETHOD CCerasusUnitRender();													//CCerasusUnit Render(~CCerasusUnit 渲染)
};

#endif // !__CERASUSUNIT_H_

