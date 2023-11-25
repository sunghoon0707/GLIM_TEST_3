#pragma once
#include "afxdialogex.h"


// CBackImage2 대화 상자

class CBackImage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CBackImage2)

public:
	CBackImage2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBackImage2();

	CImage back_2;
	CWnd* m_pParent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CBackImage2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	void startbackRight();
};
