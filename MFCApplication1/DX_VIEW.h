#include "ddraw.h"
#include "bitmapoutput.h"
#include <list>
using namespace std;
#define PI 3.141592f
#define RESIZE_RATE 150
#define ROTATION_PARAM_COUNT 12
#define ROTATION_PARAM_COUNT_1 720
#define ROTATION_PARAM_R_INCRESE 4.5f
#define SAVING_FRAME_COUNT 1
#define CUT_ZOOM_PIXCEL_RATE 1.5f


class CDX_VIEW
{

public:
	CDX_VIEW(CRect *pRect,CWnd *dlg);
	virtual ~CDX_VIEW();
	void CDX_VIEW::DrumImage(long* pImage);
	void CDX_VIEW::DrumImage_Label(long* pImage);
	CWnd *dlg;
	bitmapoutput bmout;

	////////////////////////////////////////////////////////////////////////////

	typedef struct draw_data
	{
		long *pImage1;

	};

	typedef struct tagBITMAPINFO {
		BITMAPINFOHEADER bmiHeader;
		RGBQUAD bmiColors[1];
	} BITMAPINFO;

	typedef struct tagRGBQUAD { // 4
		BYTE rgbBlue;  // B���� (�Ķ�)
		BYTE rgbGreen; // G���� (�ʷ�)
		BYTE rgbRed;   // R���� (����)
		BYTE rgbReserved;
	} RGBQUAD;

	typedef struct tagBITMAPINFOHEADER {  // 40 = 4+4+4+2+2+4+4+4+4+4+4 (byte)
		DWORD biSize;  // ����ü�� ũ��
		LONG biWidth;  // ��Ʈ���� ���� ũ��
		LONG biHeight;  // ��Ʈ���� ���� ũ��
		WORD biPlanes;  // Plane��(1�� ������)
		WORD biBitCount;  // �� �ȼ��� ��Ʈ��
		DWORD biCompression;  // ���� ���� �÷���
		DWORD biSizeImage;  // �׸� �������� ũ��
		LONG biXPelsPerMeter;  // �� �ȼ��� ���� ����
		LONG biYPelsPerMeter;  // �� �ȼ��� ���� ����
		DWORD biClrUsed;  // �׸����� ���� ���Ǵ� �÷� ��
		DWORD biClrImportant;  // �߿��ϰ� ���Ǵ� �÷�
	} BITMAPINFOHEADER;

	typedef struct tagBITMAPFILEHEADER {    // 14 = 2+4+2+2+4 (byte)
		WORD    bfType;  // "BM"�̶�� ���ڰ� ������
		DWORD   bfSize;  // ��Ʈ�� ������ ��ü ũ��
		WORD    bfReserved1;  // ���ຯ��(0���� ������)
		WORD    bfReserved2;  // ���ຯ��(0���� ������)
		DWORD   bfOffBits;  // ���Ͽ��� ��Ʈ�� �����Ͱ� �ִ� ��ġ
	} BITMAPFILEHEADER;
	////////////////////////////////////////////////////////////////////////////

	int xx,yy;
	int xx2,yy2;
	list<int> Rqueuex;
	list<int> Rqueuey;
	list<int> Yqueuex;
	list<int> Yqueuey;
	list<int> Bqueuex;
	list<int> Bqueuey;

	int flexflag;   //unset:0 set:1

	list <int> tempRx,tempRy,tempYx,tempYy,tempBx,tempBy;

	int flag,flag2;

	char x[20],y[20];

	int rc,yc,bc;
	int rcx,rcy,ycx,ycy,bcx,bcy;


	list<int> ::iterator Rx,Ry,Yx,Yy,Bx,By;
	list<int> ::iterator tempx,tempy;
	list<int>::iterator px,py;

	//CString *,*chary;

	double device_Speed_x,device_Speed_y,device_Speed_z,device_Angle_center,device_flex,device_Range_x,device_Range_y,device_Range_z;
	double device_Angle_x,device_Angle_y,device_Angle_z;
public:
	HWND main_hWnd;
	void Init(HWND phWnd);
	void DisplayDD(int Quadrant);

	long OneDisplayGroundArray[V_WIDTH*V_HEIGHT];
	long OneDisplayGroundArray1[V_WIDTH*V_HEIGHT];
	long *drawing_Image;
	long *drawing_Image2;


	void ConvertRGB24to32(unsigned char *pImage,long *poriImg_Array);


protected:
	///////////////////////////////Draw�Լ�//////////////////////////////
	int InitDD(HWND phWnd,DWORD szwidth, DWORD szheight);
	CRect mainRect;
	LPDIRECTDRAW		m_lpDD;				// Pointer to DirectDraw object
	LPDIRECTDRAWSURFACE	m_lpFrontBuffer;	// Pointer to front buffer
	LPDIRECTDRAWSURFACE	m_lpBackBuffer;		// Pointer to back buffer
	LPDIRECTDRAWCLIPPER	m_lpClipper;		// Pointer to clipper
	int		m_DataFormat;
	HWND MainHWND;

	//////////////////////////////////////////////////////////////////////

public:
	void Thresholding(long* pImage1,long* pImage4, int rmin, int rmax, int gmin, int gmax, int bmin, int bmax);
	void Binary_Image(long *pImage);
	void Binary_Image(long *pImage,int Binary);
	void Open_Image(long *pImage);
	void BlobColoring(long* pImage);
	void BlobColoring_Label(long* pImage);
	void BlobColoring_Label2(long* pImage);
	int CDX_VIEW::push(short *stackx, short *stacky, int arr_size, short vx, short vy, int *top);
	int CDX_VIEW::pop(short *stackx, short *stacky, short *vx, short *vy, int *top);
	void Thresholding2(long *pImage,long* pImage5, int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX, int rmin, int rmax, int gmin, int gmax, int bmin, int bmax);
	//	void Open2();

	void reverse_Image(long* pImage);
	void red_scale(long *pImage1,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX , int RMIN, int RMAX, int GMIN, int GMAX, int BMIN, int BMAX);

	void draw_orbit(long *pImage1,LPVIDEOHDR lpVHDR);


	void Thresholding_Red(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX );
	void Thresholding_Green(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX );
	void Thresholding_Yellow(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX );
	void Thresholding_Blue(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX );

	void Morphology(long * pImage);

	void edge_extract(long * pImage);

	void grass_fire(long* pImage);


	void parsing(char * data,int length);

	void output_conduction(long * pImage);

	void draw_draw(long* pImage);

};