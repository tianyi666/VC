// ConsoleTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#include <Wininet.h>

#pragma comment(lib, "Wininet.lib")

BOOL HttpRequestGet(IN const CString& sHomeUrl, IN const CString& sPageUrl, OUT CString &sResult)
{
	LONG nPort = 80;
	HINTERNET hInternet;
	DWORD nGetSize;
	LPSTR lpszData = NULL;
	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;

	hInternet = InternetOpen(_T("Mozilla/4.0 (compatible; Indy Library)"),
		INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (NULL == hInternet)
	{
		sResult.Format(_T("Open link error. ErrCode=[%u]"), GetLastError());
		InternetCloseHandle(hInternet);
		return FALSE;
	}
	// 打开http session   
	HINTERNET hSession = InternetConnect(hInternet, sHomeUrl,
		(INTERNET_PORT)nPort, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);

	CString sHtmlHeader;
	sHtmlHeader = _T("Content-Type: application/x-www-form-urlencoded\r\n");
	sHtmlHeader += _T("Accept: text/html, */*\r\n");
	sHtmlHeader += _T("User-Agent: Mozilla/4.0 (compatible;Indy Library)\r\n");

	LPSTR pszResponse = new char[640 * 1024];
	memset(pszResponse, 0, 640 * 1024);

	HINTERNET hRequest = HttpOpenRequest(hSession, _T("GET"), sPageUrl,
		_T("HTTP/1.1"), _T(""), 0, INTERNET_FLAG_NO_AUTH |
		INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);

	int iTimeout = 10000;
	InternetSetOption(hRequest, INTERNET_OPTION_CONNECT_TIMEOUT,
		&iTimeout, sizeof(iTimeout));
	InternetSetOption(hRequest, INTERNET_OPTION_SEND_TIMEOUT,
		&iTimeout, sizeof(iTimeout));
	InternetSetOption(hRequest, INTERNET_OPTION_RECEIVE_TIMEOUT,
		&iTimeout, sizeof(iTimeout));
	InternetSetOption(hRequest, INTERNET_OPTION_DATA_SEND_TIMEOUT,
		&iTimeout, sizeof(iTimeout));
	InternetSetOption(hRequest, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT,
		&iTimeout, sizeof(iTimeout));
	InternetSetOption(hRequest, INTERNET_OPTION_LISTEN_TIMEOUT,
		&iTimeout, sizeof(iTimeout));

	BOOL bResult = HttpSendRequest(hRequest, sHtmlHeader.GetBuffer(),
		sHtmlHeader.GetLength(), _T(""), 0);
	sHtmlHeader.ReleaseBuffer();

	if (FALSE == bResult)
	{
		sResult.Format(_T("Send request error. ErrCode=[%u]"), GetLastError());

		InternetCloseHandle(hRequest);
		InternetCloseHandle(hSession);
		InternetCloseHandle(hInternet);

		delete[]pszResponse;

		return FALSE;
	}

	nGetSize = 0;
	// 循环读取数据    
	do
	{ // 检查在http response 还有多少字节可以读取  
		if (!InternetQueryDataAvailable(hRequest, &dwSize, 0, 0))
		{
			break;
		}
		// 读取数据  
		if (FALSE == InternetReadFile(hRequest,
			(LPVOID)&pszResponse[nGetSize], dwSize, &dwDownloaded))
		{
			nGetSize += dwSize;
			if (dwDownloaded == 0 || nGetSize > 600 * 1024)
			{// 没有剩余数据  
				break;
			}
		}
	} while (FALSE);

	//pszResponse[nGetSize] = 0;
	//sResult = ATL::CA2T(pszResponse);
	sResult = pszResponse;

	InternetCloseHandle(hRequest);
	InternetCloseHandle(hSession);
	InternetCloseHandle(hInternet);

	//delete[]pszResponse;

	if (sResult.Find(_T("<html>")) != -1)
	{
		sResult = _T("An unknown error occurred.");
		return FALSE;
	}

	return TRUE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//cout << 123 << endl;
	//system("PAUSE");

	//CString sHomeUrl(_T("tianyi666.top"));
	//CString sPageUrl(_T("index.php"));
	//CString sResult(_T(""));
	setlocale(LC_ALL, "chs");
	//HttpRequestGet(sHomeUrl, sPageUrl, sResult);
	//wcout << sResult.GetString() << endl;

	TCHAR msg[] = _T("你好地地道道的");
	//TCHAR str[sizeof(msg) / sizeof(msg[0])]; //= {0};
	TCHAR str[8]; //= {0};
	/*wcout << sizeof(msg)/sizeof(msg[0]) << endl;*/
	wcout << _countof(msg) << endl;
	_tcsncpy_s(str, msg, 8);
	
	wcout << str << endl;
	system("pause");
	return 0;
}

