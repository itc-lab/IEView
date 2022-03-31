
// IEViewDlg.h : ヘッダー ファイル
//

#pragma once


// CIEViewDlg ダイアログ
class CIEViewDlg : public CDHtmlDialog
{
// コンストラクション
public:
	CIEViewDlg(const CString& url, CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IEVIEW_DIALOG, IDH = IDR_HTML_IEVIEW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

// 実装
protected:
	HICON m_hIcon;
	CString m_url;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
