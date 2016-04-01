

class CVFX_Init
{

public:
	CVFX_Init(HWND hWnd);
	virtual ~CVFX_Init();


public:
	void init();
	HWND m_hWnd;
	HANDLE			m_hMapFile;			 //캡쳐된 실제 비트맵 데이터를 담을 맵파일 핸들.
	BITMAPINFO m_bmpInfo;
	HWND m_hwndCap;
	virtual BOOL InitSharedMemory();
	BOOL InitVideoWnd();
	void DLG_ON();
	int Graphing;
	void Graph();


protected:

};