#pragma once
#include "afxdialogex.h"


// CBackImage 대화 상자

class CBackImage : public CDialogEx
{
	DECLARE_DYNAMIC(CBackImage)

public:
	CBackImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBackImage();

	CImage back;
	CWnd* m_pParent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CBackImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void startDraw();
};
