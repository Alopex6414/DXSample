/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectSound.h
* @brief	This Program is DirectSound DLL Project.
* @author	Alopex/Helium
* @version	v1.24a
* @date		2017-10-31	v1.00a	alopex	Create Project
* @date		2017-12-03	v1.01a	alopex	Add Enum
* @date		2017-12-8	v1.11a	alopex	Code Do Not Rely On MSVCR Library
* @date		2018-01-10	v1.20a	alopex	Code Add dxerr & d3dcompiler Library and Modify Verify.
* @date		2018-01-10	v1.21a	alopex	Add Thread Safe File & Variable(DirectThreadSafe).
* @date		2018-04-12	v1.22a	alopex	Add Macro Call Mode.
* @date		2018-06-22	v1.23a	alopex	Add Get Members Function.
* @date		2018-11-23	v1.24a	alopex	Alter Call Method.
*/
#pragma once

#ifndef __DIRECTSOUND_H_
#define __DIRECTSOUND_H_

//Macro Definition
#ifdef  CERASUS_EXPORTS
#define DIRECTSOUND_API	__declspec(dllexport)
#else
#define DIRECTSOUND_API	__declspec(dllimport)
#endif

#define DIRECTSOUND_CALLMETHOD	__stdcall

//Class Definetion
#define DSVOLUME_DB(Volume)	((LONG)(-30*(100 - Volume)))	//音量(分贝)

//Enum Definetion
//DirectSound设备协作级别
enum DirectSoundCoopFlags
{
	DSCoopFlags_Normal = 0,			//DSSCL_NORMAL(正常)
	DSCoopFlags_Priority = 1,		//DSSCL_PRIORITY(优先)
	DSCoopFlags_Exclusive = 2,		//DSSCL_EXCLUSIVE(独占)
	DSCoopFlags_WritePrimary = 3,	//DSSCL_WRITEPRIMARY(完全控制)
};

//DirectSound播放状态
enum DirectSoundPlayState
{
	DSPlayState_Loop = 0,	//PlayState:Loop(循环播放)
	DSPlayState_Once = 1,	//PlayState:Once(单次播放)
};

//Class
class DIRECTSOUND_API DirectSound
{
private:
	LPDIRECTSOUND8 m_pDirectSound;								//IDirectSound8 Interface Pointer(IDirectSound8接口指针)
	LPDIRECTSOUNDBUFFER m_pDirectSoundBuffer;					//IDirectSoundBuffer Interface Pointer(IDirectSoundBuffer接口指针)
	LPDIRECTSOUNDBUFFER m_pDirectSoundPrimary;					//IDirectSoundBuffer Interface Pointer(IDirectSoundBuffer接口指针:主缓冲)
	LPDIRECTSOUND3DBUFFER m_pDirectSound3DBuffer;				//IDirectSound3DBuffer Interface Pointer(IDirectSound3DBuffer接口指针)
	LPDIRECTSOUND3DLISTENER m_pDirectSound3DListener;			//IDirectSound3DListener Interface Pointer(IDirectSound3DBuffer接口指针:收听缓冲)

	DSBUFFERDESC m_DSPrimaryDesc;	//DirectSount Wave Buffer(Main)(主缓冲)
	DSBUFFERDESC m_DSBufferDesc;	//DirectSount Wave Buffer(副缓冲)

	CRITICAL_SECTION m_cs;			//Thread Safe(CriticalSection)
	bool m_bThreadSafe;				//Thread Safe Status

public:
	DirectSound();	//DirectSound Constructor Function(构造函数)
	~DirectSound();	//DirectSound Destructor Function(析构函数)

	//DirectSound访问
	LPDIRECTSOUND8 DIRECTSOUND_CALLMETHOD DirectSoundGetSound(void) const;						//DirectSound Get Sound(DirectSound获取IDirectSound8接口指针)
	LPDIRECTSOUNDBUFFER DIRECTSOUND_CALLMETHOD DirectSoundGetSoundBuffer(void) const;			//DirectSound Get SoundBuffer(DirectSound获取IDirectSoundBuffer接口指针)
	LPDIRECTSOUNDBUFFER DIRECTSOUND_CALLMETHOD DirectSoundGetSoundPrimary(void) const;			//DirectSound Get SoundBuffer(DirectSound获取IDirectSoundBuffer接口指针:主缓冲)
	LPDIRECTSOUND3DBUFFER DIRECTSOUND_CALLMETHOD DirectSoundGetSound3DBuffer(void) const;		//DirectSound Get Sound3DBuffer(DirectSound获取IDirectSound3DBuffer接口指针)
	LPDIRECTSOUND3DLISTENER DIRECTSOUND_CALLMETHOD DirectSoundGetSound3DListener(void) const;	//DirectSound Get Sound3DListener(DirectSound获取IDirectSound3DBuffer接口指针:收听缓冲)
	
	//DirectSound控制
	void DIRECTSOUND_CALLMETHOD DirectSoundSetSound(LPDIRECTSOUND8 pDirectSound);									//DirectSound Set Sound(DirectSound设置IDirectSound8接口指针)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetSoundBuffer(LPDIRECTSOUNDBUFFER pDirectSoundBuffer);					//DirectSound Set SoundBuffer(DirectSound设置IDirectSoundBuffer接口指针)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetSoundPrimary(LPDIRECTSOUNDBUFFER pDirectSoundPrimary);				//DirectSound Set SoundBuffer(DirectSound设置IDirectSoundBuffer接口指针:主缓冲)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetSound3DBuffer(LPDIRECTSOUND3DBUFFER pDirectSound3DBuffer);			//DirectSound Set Sound3DBuffer(DirectSound设置IDirectSound3DBuffer接口指针)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetSound3DListener(LPDIRECTSOUND3DLISTENER pDirectSound3DListener);		//DirectSound Set Sound3DListener(DirectSound设置IDirectSound3DBuffer接口指针:收听缓冲)

	//DirectSound初始化
	HRESULT DIRECTSOUND_CALLMETHOD DirectSoundInit(HWND hWnd);													//DirectSound Initialize(SoundCoopFlags:Normal)
	HRESULT DIRECTSOUND_CALLMETHOD DirectSoundInit(HWND hWnd, DWORD dwSoundCoopFlags);							//DirectSound Initialize(重载+1)
	HRESULT DIRECTSOUND_CALLMETHOD DirectSoundInit(HWND hWnd, DirectSoundCoopFlags eDirectSoundCoopFlags);		//DirectSound Initialize(重载+2)
	HRESULT DIRECTSOUND_CALLMETHOD DirectSound3DInit(HWND hWnd);												//DirectSound3D Initialize(SoundCoopFlags:Priority)

	//DirectSound加载
	HRESULT DIRECTSOUND_CALLMETHOD DirectSoundLoadWave(LPWSTR lpszFileName);			//DirectSound Load Wave(加载Wav)
	HRESULT DIRECTSOUND_CALLMETHOD DirectSoundLoad3DWave(LPWSTR lpszFileName);			//DirectSound Load 3D Wave(加载Wav:3D)

	//DirectSound控制
	void DIRECTSOUND_CALLMETHOD DirectSoundPlay(void);															//DirectSound Play Wave(Once)(单次播放)
	void DIRECTSOUND_CALLMETHOD DirectSoundPlay(DirectSoundPlayState eDSPlayState_X);							//DirectSound Play Wave(单次播放/循环播放)(重载+1)
	void DIRECTSOUND_CALLMETHOD DirectSoundPlayOnce(void);														//DirectSound Play Wave(Once)(单次播放)
	void DIRECTSOUND_CALLMETHOD DirectSoundPlayLoop(void);														//DirectSound Play Wave(Loop)(循环播放)
	void DIRECTSOUND_CALLMETHOD DirectSoundStop(void);															//DirectSound Stop Play(停止播放)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetVolume(LONG lVolume);												//DirectSound SetVolume(设置音量)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetFrequency(DWORD dwFrequency);										//DirectSound SetFrequency(设置频率)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetPan(LONG lPan);													//DirectSound SetPan(No 3D Voice)(设置声道平衡:不支持3D)
	void DIRECTSOUND_CALLMETHOD DirectSoundSetCurrentPosition(DWORD dwNewPositon);								//DirectSound SetCurrentPosition(设置播放进度)
};

#endif