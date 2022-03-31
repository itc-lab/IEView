
// IEView.cpp : アプリケーションのクラス動作を定義します。
//

#include "pch.h"
#include "framework.h"
#include "IEView.h"
#include "IEViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIEViewApp

BEGIN_MESSAGE_MAP(CIEViewApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CIEViewApp の構築

CIEViewApp::CIEViewApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CIEViewApp オブジェクト

CIEViewApp theApp;


// CIEViewApp の初期化

BOOL CIEViewApp::InitInstance()
{
	CWinApp::InitInstance();


	// ダイアログにシェル ツリー ビューまたはシェル リスト ビュー コントロールが
	// 含まれている場合にシェル マネージャーを作成します。
	CShellManager* pShellManager = nullptr;
	//CShellManager* pShellManager = new CShellManager;

	// MFC コントロールでテーマを有効にするために、"Windows ネイティブ" のビジュアル マネージャーをアクティブ化
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	int dwArgc;
	LPTSTR* lpszArgv = CommandLineToArgvW(GetCommandLineW(), &dwArgc);
	CString url = lpszArgv[1];
	if (url.Find(_T(':'), 0) >= 0) {
		url = url.Mid(url.Find(_T(':'), 0) + 1);
	}

	CIEViewDlg dlg(url);
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	// 上で作成されたシェル マネージャーを削除します。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}

