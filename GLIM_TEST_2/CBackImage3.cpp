// CBackImage3.cpp: 구현 파일
//

#include "pch.h"
#include "GLIM_TEST_2.h"
#include "afxdialogex.h"
#include "CBackImage3.h"


// CBackImage3 대화 상자

IMPLEMENT_DYNAMIC(CBackImage3, CDialogEx)

CBackImage3::CBackImage3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CBackImage3, pParent)
{
	m_pParent = pParent;
}

CBackImage3::~CBackImage3()
{
}

void CBackImage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBackImage3, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CBackImage3 메시지 처리기


BOOL CBackImage3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	startBack_UnderLeft();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBackImage3::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (back_3)
	{
		back_3.Draw(dc, 0, 0);
	}
}

void CBackImage3::startBack_UnderLeft()
{
	int n_Width = 400;
	int n_Height = 240;
	int n_Bpp = 8;

	back_3.Create(n_Width, -n_Height, n_Bpp);

	if (n_Bpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
		{
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		back_3.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)back_3.GetBits();

	//fm 시작점 부터 n_Widht*n_Height 까지 0xff 로 초기화
	memset(fm, 0xff, n_Width * n_Height);
}