﻿
// MFCApplication5.h: MFCApplication5 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication5App:
// 有关此类的实现，请参阅 MFCApplication5.cpp
//

class CMFCApplication5App : public CWinAppEx
{
public:
	CMFCApplication5App() noexcept;
	// 特性

	

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication5App theApp;
