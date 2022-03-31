
// IEViewDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "IEView.h"
#include "IEViewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIEViewDlg ダイアログ

BEGIN_DHTML_EVENT_MAP(CIEViewDlg)
END_DHTML_EVENT_MAP()


CIEViewDlg::CIEViewDlg(const CString& url, CWnd* pParent /*=nullptr*/)
	: CDHtmlDialog(IDD_IEVIEW_DIALOG, IDR_HTML_IEVIEW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_url = url;
}

void CIEViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIEViewDlg, CDHtmlDialog)
END_MESSAGE_MAP()


// CIEViewDlg メッセージ ハンドラー

BOOL CIEViewDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	int pos = m_url.ReverseFind(_T('/'));
	this->SetWindowTextW(m_url.Mid(pos + 1));
	this->Navigate(m_url);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CIEViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CIEViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CIEViewDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message) {
		switch (pMsg->wParam) {
		case VK_RETURN:
		case VK_ESCAPE:
			return FALSE;
		}
	}
	return CDHtmlDialog::PreTranslateMessage(pMsg);
}
