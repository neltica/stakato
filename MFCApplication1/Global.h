
#include "DX_VIEW.h"
extern BITMAPINFO			g_BitInfo;	 		 // 캡쳐된 이미지 정보
extern unsigned char				*g_pMapMemory;	 	 // 캡쳐된 이미지 DIB정보를 저장할 공간
extern BOOL m_IsCapture;
extern CDX_VIEW *pCView;
extern BOOL DisplayOn;
extern LRESULT CALLBACK VideoStreamCallbackProc(HWND hwnd, LPVIDEOHDR lpVHDR);
extern int ViewMode;
extern float fps;

extern int YHMIN, YHMAX, YSMIN, YSMAX, YVMIN, YVMAX,RMIN, RMAX, GMIN, GMAX, BMIN, BMAX,RHMIN, RHMAX, RSMIN, RSMAX, RVMIN, RVMAX,BHMIN, BHMAX, BSMIN, BSMAX, BVMIN, BVMAX;

extern BOOL bTHRES, bBINARY, bOPEN, bLABELING, bTHRES2,bDrum,bOpen2,TEST,RED,GREEN,YELLOW,BLUE;
//extern void Open2();

//pCView->OneDisplayGroundArray,YHMIN,YHMAX,YSMIN,YSMAX,YVMIN,YVMAX
