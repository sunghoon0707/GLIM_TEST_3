// CBackImage2.cpp: 구현 파일
//

#include "pch.h"
#include "GLIM_TEST_2.h"
#include "afxdialogex.h"
#include "CBackImage2.h"


// CBackImage2 대화 상자

IMPLEMENT_DYNAMIC(CBackImage2, CDialogEx)

CBackImage2::CBackImage2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CBackImage2, pParent)
{
	m_pParent = pParent;
}

CBackImage2::~CBackImage2()
{
}

void CBackImage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBackImage2, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CBackImage2 메시지 처리기


void CBackImage2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (back_2)
	{
		back_2.Draw(dc, 0, 0);
	}

}


BOOL CBackImage2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	startbackRight();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CBackImage2::startbackRight()
{
	int n_Width = 400;
	int n_Height = 240;
	int n_Bpp = 8;

	back_2.Create(n_Width, -n_Height, n_Bpp);

	if (n_Bpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
		{
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		back_2.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)back_2.GetBits();

	//fm 시작점 부터 n_Widht*n_Height 까지 0xff 로 초기화
	memset(fm, 0xff, n_Width * n_Height);
}