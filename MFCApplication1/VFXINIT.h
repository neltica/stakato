

class CVFX_Init
{

public:
	CVFX_Init(HWND hWnd);
	virtual ~CVFX_Init();


public:
	void init();
	HWND m_hWnd;
	HANDLE			m_hMapFile;			 //ĸ�ĵ� ���� ��Ʈ�� �����͸� ���� ������ �ڵ�.
	BITMAPINFO m_bmpInfo;
	HWND m_hwndCap;
	virtual BOOL InitSharedMemory();
	BOOL InitVideoWnd();
	void DLG_ON();
	int Graphing;
	void Graph();


protected:

};