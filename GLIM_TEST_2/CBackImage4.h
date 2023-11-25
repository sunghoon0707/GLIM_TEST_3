#pragma once
#include "afxdialogex.h"


// CBackImage4 대화 상자

class CBackImage4 : public CDialogEx
{
	DECLARE_DYNAMIC(CBackImage4)

public:
	CBackImage4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBackImage4();

	CImage back_4;
	CWnd* m_pParent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CBackImage4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void Start_Under_Right();
};
