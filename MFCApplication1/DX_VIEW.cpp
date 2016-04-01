#include "stdafx.h"
#include "DX_VIEW.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
//#define PI 3.141592653589793238





long pImage4[V_HEIGHT*V_WIDTH];
long pImage5[V_HEIGHT*V_WIDTH];
long pImage6[V_HEIGHT*V_WIDTH];
long pImage7[V_HEIGHT*V_WIDTH];
long pImage77[320*240];
long pImage88[320*240];

CDX_VIEW::CDX_VIEW(CRect *pRect,CWnd *dlg)
{

	mainRect = pRect;
	this->dlg=dlg;
	flag=0;
	flag2=0;
	flexflag=0;
}
CDX_VIEW::~CDX_VIEW()
{



}

int CDX_VIEW::InitDD(HWND phWnd,DWORD szwidth, DWORD szheight)
{
	HRESULT hr;
	DDSURFACEDESC  f_ddsd, b_ddsd;
	int data_format;

	// Create Direct Draw Object
	hr = DirectDrawCreate( NULL, &m_lpDD, NULL );
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't create DirectDraw");
		return 0;
	}

	// Set Cooperative Level
	hr = m_lpDD->SetCooperativeLevel(phWnd, DDSCL_NORMAL);
	//hr = m_lpDD->SetCooperativeLevel(AfxGetMainWnd()->GetSafeHwnd(), DDSCL_FULLSCREEN | DDSCL_ALLOWMODEX | DDSCL_EXCLUSIVE | DDSCL_ALLOWREBOOT | DDSCL_NOWINDOWCHANGES );
	if (hr != DD_OK) 
	{
		AfxMessageBox("Problem in SetCooperativeLevel");
		return 0;
	}

	//hr = m_lpDD->SetDisplayMode(1024, 768, 32);
	// Create Front Buffer
	memset( (VOID *)&f_ddsd, 0, sizeof( f_ddsd ) );
	f_ddsd.dwSize = sizeof( f_ddsd );
	f_ddsd.dwFlags = DDSD_CAPS;
	f_ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;


	hr = m_lpDD->CreateSurface( &f_ddsd, &m_lpFrontBuffer, NULL );
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't create FrontBuffer");
		return 0;
	}

	hr = m_lpFrontBuffer->Lock(NULL, &f_ddsd, DDLOCK_WAIT, NULL);
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't lock FrontBuffer");
		return 0;
	}
	hr = m_lpFrontBuffer->Unlock(NULL);

	// Create Clipper
	hr = m_lpDD->CreateClipper(0, &m_lpClipper, NULL );
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't create Clipper");
		return 0;
	}

	// Set HWnd in Clipper
	hr = m_lpClipper->SetHWnd(0, phWnd);
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't Set Window Handle of Clipper");
		return 0;
	}

	hr = m_lpFrontBuffer->SetClipper(m_lpClipper);
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't create Clipper");
		return 0;
	}

	/////////////////////////////////////////////////////////
	// Create Back surface
	memset( &b_ddsd, 0, sizeof( b_ddsd ) );
	b_ddsd.dwSize = sizeof( b_ddsd );
	b_ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT |DDSD_WIDTH|DDSD_PIXELFORMAT;
	b_ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;



	b_ddsd.dwHeight = szheight;
	b_ddsd.dwWidth  = szwidth;
	b_ddsd.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
	b_ddsd.ddpfPixelFormat.dwFlags = DDPF_RGB;   
	b_ddsd.ddpfPixelFormat.dwRGBBitCount 
		= f_ddsd.ddpfPixelFormat.dwRGBBitCount;   
	b_ddsd.ddpfPixelFormat.dwRBitMask
		= f_ddsd.ddpfPixelFormat.dwRBitMask;   
	b_ddsd.ddpfPixelFormat.dwGBitMask
		= f_ddsd.ddpfPixelFormat.dwGBitMask;   
	b_ddsd.ddpfPixelFormat.dwBBitMask
		= f_ddsd.ddpfPixelFormat.dwBBitMask;
	b_ddsd.ddpfPixelFormat.dwRGBAlphaBitMask = 0x0000;   

	hr = m_lpDD->CreateSurface( &b_ddsd, &m_lpBackBuffer, NULL );
	if (hr != DD_OK) 
	{
		AfxMessageBox("Can't create BackBuffer");
		return 0;
	}	

	switch (f_ddsd.ddpfPixelFormat.dwRGBBitCount) 
	{
	case 32 :
		data_format = 32;

		break;
	case 24 :
		data_format = 24;
		break;

	case 16 :
		data_format = 16;

		break;

	case 15 :
		data_format = 15;

		break;

	default:
		data_format = 15;

		break;
	}

	return data_format;
}

void CDX_VIEW::DisplayDD(int Quadrant)
{


	HRESULT hr;
	DDSURFACEDESC ddsd;
	RECT rect;
	PVOID p_surf;

	switch(Quadrant)
	{
	case 0:
		rect.left = /*12*/33+mainRect.left;   //영상 출력 위치 
		rect.top  = /*27*/54+mainRect.top;  //영상 출력 위치
		rect.right  = mainRect.right+/*10*/31;    //left-2
		rect.bottom = mainRect.bottom+/*25*/52;   //top-2
		break;
	case 1:
		rect.left = 0;
		rect.top  = 0;
		rect.right  = mainRect.Width()/2;
		rect.bottom = mainRect.Height()/2;
		break;
	case 2:
		rect.left = mainRect.Width()/2;
		rect.top  = 0;
		rect.right  = mainRect.Width();
		rect.bottom = mainRect.Height()/2;
		break;
	case 3:
		rect.left = 0;
		rect.top  = mainRect.Height()/2;
		rect.right  = mainRect.Width()/2;
		rect.bottom = mainRect.Height();
		break;
	case 4:
		rect.left = mainRect.Width()/2;	
		rect.top  = mainRect.Height()/2;
		rect.right  = mainRect.Width();
		rect.bottom = mainRect.Height();
		break;
	}

	ClientToScreen(MainHWND,(LPPOINT)&rect);
	ClientToScreen(MainHWND,(LPPOINT)&rect+1);


	memset( (VOID *)&ddsd, 0, sizeof( ddsd ) );
	ddsd.dwSize = sizeof(ddsd);
	hr = m_lpBackBuffer->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL);
	if (hr != DD_OK) 
	{
		//AfxMessageBox(L"Can't Lock");
		return;
	}	
	p_surf = ddsd.lpSurface;

	if (m_DataFormat == 32)
	{

		long *ptr  = (long *)p_surf; 
		long *ptr1;
		ptr1 = OneDisplayGroundArray;


		memcpy((long *)ptr,(long*)ptr1,sizeof(OneDisplayGroundArray));
	} 

	hr = m_lpBackBuffer->Unlock(NULL);

	hr = m_lpFrontBuffer->Blt(
		&rect,				// dest rect
		m_lpBackBuffer,		// src surface
		NULL,				// src rect (all of it)
		DDBLT_WAIT,
		NULL);


}



void CDX_VIEW::Init(HWND phWnd)
{	
	MainHWND = phWnd;
	drawing_Image=NULL;
	drawing_Image2=NULL;
	m_DataFormat=InitDD(phWnd,V_WIDTH,V_HEIGHT);  //DirectX Initial 


}

void CDX_VIEW::ConvertRGB24to32(unsigned char *pImage,long *poriImg_Array)
{
	int i,j,x,y;
	long pix;
	char *a;
	BYTE R,G,B,GRAY;



	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH*3 ; i+=3)
		{
			a = (char*)&pix;
			pix = 0;
			*a = pImage[j*V_WIDTH*3 + i];
			*(a + 1) = pImage[j*V_WIDTH*3 + i + 1];
			*(a + 2) = pImage[j*V_WIDTH*3 + i + 2];
			*(a + 3) = 0;

			B = (BYTE)*(a);
			G = (BYTE)*(a + 1);
			R = (BYTE)*(a + 2);

			GRAY = ((int)R + B + G) / 3;
			*a = GRAY;
			*(a + 1) = GRAY;
			*(a + 2) = GRAY;


			x = i / 3;
			y = V_HEIGHT - 1-j;

			poriImg_Array[y * V_WIDTH + x] = (R<<16)|(G<<8)|B;

		}


	}


}



void CDX_VIEW::Binary_Image(long *pImage)
{
	int i,j;

	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{

			if(pImage[j*V_WIDTH + i] != 0)
			{

				pImage[j*V_WIDTH + i] = 0xFFFFFF;
			}
		}

	}
}


void CDX_VIEW::Binary_Image(long *pImage,int Binary_bar)
{
	int i,j;

	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{

			/*if(pImage[j*V_WIDTH + i] != 0)*/
			if(pImage[j*V_WIDTH + i]<Binary_bar )
			{

				pImage[j*V_WIDTH + i] = 0xFFFFFF;
			}
		}

	}
}

void CDX_VIEW::Open_Image(long *pImage)
{
	int i,j,x;
	long Mask[9];
	long M_MAX, M_MIN;
	long pImage2[V_HEIGHT*V_WIDTH];
	long pImage3[V_HEIGHT*V_WIDTH];




	for(j = 1 ; j < V_HEIGHT-1 ; j++)
	{
		for(i = 1 ; i < V_WIDTH-1 ; i++)
		{
			Mask[0]=pImage[(j-1)*V_WIDTH + (i-1)];
			Mask[1]=pImage[j*V_WIDTH + (i-1)];
			Mask[2]=pImage[(j+1)*V_WIDTH + (i-1)];
			Mask[3]=pImage[(j-1)*V_WIDTH + i];
			Mask[4]=pImage[j*V_WIDTH + i];
			Mask[5]=pImage[(j+1)*V_WIDTH + i];
			Mask[6]=pImage[(j-1)*V_WIDTH + (i+1)];
			Mask[7]=pImage[j*V_WIDTH + (i+1)];
			Mask[8]=pImage[(j+1)*V_WIDTH + (i+1)];

			M_MIN=Mask[0];
			for(x=1; x<9; x++)	if(M_MIN>Mask[x])	M_MIN = Mask[x];
			pImage2[j*V_WIDTH + i] = M_MIN;

		}
	}


	//pimage2에 침식된거 저장
	//pimage2를 읽어와서 팽창해서 pimage3에 저장
	// 침식팽창다된거 다시 원이미지 pimage에 덮어씀
	for(j = 1 ; j < V_HEIGHT-1 ; j++)
	{
		for(i = 1 ; i < V_WIDTH-1 ; i++)
		{
			Mask[0]=pImage2[(j-1)*V_WIDTH + (i-1)];
			Mask[1]=pImage2[j*V_WIDTH + (i-1)];
			Mask[2]=pImage2[(j+1)*V_WIDTH + (i-1)];
			Mask[3]=pImage2[(j-1)*V_WIDTH + i];
			Mask[4]=pImage2[j*V_WIDTH + i];
			Mask[5]=pImage2[(j+1)*V_WIDTH + i];
			Mask[6]=pImage2[(j-1)*V_WIDTH + (i+1)];
			Mask[7]=pImage2[j*V_WIDTH + (i+1)];
			Mask[8]=pImage2[(j+1)*V_WIDTH + (i+1)];

			M_MAX=Mask[0];
			for(x=1; x<9; x++)	if(M_MAX<Mask[x])	M_MAX = Mask[x];
			pImage3[j*V_WIDTH + i] = M_MAX;


		}
	}

	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{
			pImage[j*V_WIDTH + i] = pImage3[j*V_WIDTH + i];
		}
	}

}

FILE *fp10=fopen("output.txt","w");
FILE *fp20=fopen("queue.txt","w");
FILE *fp30=fopen("number.txt","w");
FILE *fp40=fopen("center_y.txt","w");
FILE *fp50=fopen("num_y.txt","w");

int CDX_VIEW::push(short *stackx, short *stacky, int arr_size, short vx, short vy, int *top)
{
	if(*top>=arr_size) return (-1);
	(*top)++;
	stackx[*top]=vx;
	stacky[*top]=vy;
	return 1;
}

int CDX_VIEW::pop(short *stackx, short *stacky,  short *vx, short *vy, int *top)
{
	if(*top==0) return (-1);
	*vx=stackx[*top];
	*vy=stacky[*top];
	(*top)--;
	return 1;
}


////////////////////queue 구현 위한 부분//////////////////////////
typedef struct _dnode
{
	int key;
	struct _dnode *prev;
	struct _dnode *next;
} dnode;

dnode *head, *tail;
dnode *head2, *tail2;
void init_queue(void)
{
	head = (dnode*)malloc(sizeof(dnode));
	tail = (dnode*)malloc(sizeof(dnode));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
}

void clear_queue(void)
{
	dnode *t;
	dnode *s;
	t = head->next;
	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}
	head->next = tail;
	tail->prev = head;
}

int put(int k)
{
	dnode *t;
	if ((t = (dnode*)malloc(sizeof(dnode))) == NULL)
	{
		fprintf(fp20,"\n not enough memory ");
		return -1;
	}
	t->key = k;
	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
	t->next = tail;
	return k;
}

int get(void)
{
	dnode *t;
	int i;
	t = head->next;
	if (t == tail)
	{
		fprintf(fp20,"\n    Queue underflow.");
		return -1;
	}
	i = t->key;
	head->next = t->next;
	t->next->prev = head;
	free(t);
	return i;
}
int get_value(void)
{
	dnode *t;
	int i;
	t = head->next;
	if (t == tail)
	{
		fprintf(fp20,"\n    Queue underflow.");
		return -1;
	}
	i = t->key;
	//head->next = t->next;
	//t->next->prev = head;
	free(t);
	return i;
}

void print_queue(void)
{
	dnode *t;
	t = head->next;
	fprintf(fp20,"\n  Queue contents : Front ----> Rear\n");
	while (t != tail)
	{
		fprintf(fp20,"%-6d", t->key);
		t = t->next;
	}
}
////////////////////////////////////

void init_queue2(void)
{
	head2 = (dnode*)malloc(sizeof(dnode));
	tail2 = (dnode*)malloc(sizeof(dnode));
	head2->prev = head2;
	head2->next = tail2;
	tail2->prev = head2;
	tail2->next = tail2;
}

void clear_queue2(void)
{
	dnode *t2;
	dnode *s2;
	t2 = head2->next;
	while (t2 != tail2)
	{
		s2 = t2;
		t2 = t2->next;
		free(s2);
	}
	head2->next = tail2;
	tail2->prev = head2;
}

int put2(int k)
{
	dnode *t2;
	if ((t2 = (dnode*)malloc(sizeof(dnode))) == NULL)
	{
		fprintf(fp40,"\n not enough memory ");
		return -1;
	}
	t2->key = k;
	tail2->prev->next = t2;
	t2->prev = tail2->prev;
	tail2->prev = t2;
	t2->next = tail2;
	return k;
}

int get2(void)
{
	dnode *t2;
	int i;
	t2 = head2->next;
	if (t2 == tail2)
	{
		fprintf(fp40,"\n    Queue underflow.");
		return -1;
	}
	i = t2->key;
	head2->next = t2->next;
	t2->next->prev = head2;
	free(t2);
	return i;
}
int get_value2(void)
{
	dnode *t2;
	int i;
	t2 = head2->next;
	if (t2 == tail2)
	{
		fprintf(fp40,"\n    Queue underflow.");
		return -1;
	}
	i = t2->key;
	//head2->next = t->next;
	//t->next->prev = head2;
	free(t2);
	return i;
}

void print_queue2(void)
{
	dnode *t2;
	t2 = head2->next;
	fprintf(fp40,"\n  Queue contents : Front ----> Rear\n");
	while (t2 != tail2)
	{
		fprintf(fp40,"%-6d", t2->key);
		t2 = t2->next;
	}
}

/////////////////////////////////////////////////////




unsigned int setRGB(BYTE R, BYTE G, BYTE B)//R,G,B값을 받아 합줌
{
	//return (B << 16) | (G << 8) | (R);
	return (R << 16) | (G << 8) | (B);
}

//int flag_drumimage=0;
//
//void CDX_VIEW::DrumImage(long* pImage)
//{
//	int i,j;
//
//	unsigned char pImage33[320*240*3];
//	//long pImage77[320*240];
//	for(j=0;j<V_HEIGHT;j++)
//	{
//		for(i=0;i<V_WIDTH;i++)
//		{
//			pImage33[j*V_WIDTH+i]=0;
//		}
//	}
//
//	FILE *fp = fopen("input.raw","r"); //화면에 띄울 드럼 이미지
//	if(fp!=NULL)
//	{
//		fread(pImage33,sizeof(char),320*240*3,fp);
//		fclose(fp);
//	}
//	else
//		perror("can't file open");
//	ConvertRGB24to32(pImage33,pImage77);
//
//	//	flag_drumimage=1;
//
//
//	for(j=0;j<V_HEIGHT;j++)
//	{
//		for(i=0;i<V_WIDTH;i++)
//		{
//			if(pImage[j*V_WIDTH+i]!=0)
//			{
//				pImage77[j*V_WIDTH+i]=pImage[j*V_WIDTH+i];
//			}
//		}
//	}
//
//	for(j=0;j<V_HEIGHT;j++)
//	{
//		for(i=0;i<V_WIDTH;i++)
//		{
//			pImage[j*V_WIDTH+i]=pImage77[j*V_WIDTH+i];
//		}
//	}
//}

int flag_drum_label=0;
void CDX_VIEW::DrumImage_Label(long* pImage)
{
	int i,j;

	if (flag_drum_label==0)
	{
		unsigned char pImage3[320*240*3];
		//long pImage88[320*240];
		for(j=0;j<V_HEIGHT;j++)
		{
			for(i=0;i<V_WIDTH;i++)
			{
				pImage3[j*V_WIDTH+i]=0;
			}
		}

		FILE *fp = fopen("input2.raw","r"); //포토샵으로 작업된 라벨링할 드럼이미지
		if(fp!=NULL)
		{
			fread(pImage3,sizeof(char),320*240*3,fp);
			fclose(fp);   
		}
		else
			perror("can't FIle open");
		ConvertRGB24to32(pImage3,pImage88);

		BlobColoring_Label2(pImage88);
		flag_drum_label=1;
	}





	/*
	for(j=0;j<V_HEIGHT;j++)
	{
	for(i=0;i<V_WIDTH;i++)
	{
	if(pImage[j*V_WIDTH+i]!=0)
	{
	pImage7[j*V_WIDTH+i]=pImage[j*V_WIDTH+i];
	}
	}
	}

	for(j=0;j<V_HEIGHT;j++)
	{
	for(i=0;i<V_WIDTH;i++)
	{
	pImage[j*V_WIDTH+i]=pImage7[j*V_WIDTH+i];
	}
	}
	*/

}



//이거 고칠차례임 - 이학주
void CDX_VIEW::BlobColoring_Label2(long* pImage)
{
	int i,j,m,n,top;
	int ic=1;

	short r,c;
	int cnt = 0;
	unsigned int temp[10];//임시 색 저장공간
	temp[0] = setRGB(0, 0, 255);
	temp[1] = setRGB(100,50,0);
	temp[2] = setRGB(200,200,0);
	temp[3] = setRGB(255,255,200);
	temp[4] = setRGB(0,100,250);
	temp[5] = setRGB(0,255,0);
	temp[6] = setRGB(50,0,0);
	temp[7] = setRGB(255,0,0);
	temp[8] = setRGB(200,0,200);
	temp[9] = setRGB(0,200,200);

	short* stackx;
	short* stacky;
	stackx = (short *)malloc(320*240*4);
	stacky = (short *)malloc(320*240*4);
	int arr_size = 320*240;

	long* coloring;
	coloring = (long *)malloc(320*240*4);


	long* icb;
	icb = (long *)malloc(320*240*4);

	long* icc;
	icc = (long *)malloc(320*240*4);


	for(i=0;i<V_HEIGHT*V_WIDTH;i++)
	{
		coloring[i]=0;
		icb[i]=0;
		icc[i]=0;


	}

	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{
			if(coloring[i*V_WIDTH+j] != 0 || pImage[i*V_WIDTH+j] != 0xFFFFFF)
				continue;
			r=i; c=j; top=0;
			cnt++;
			if(cnt > 10)
				cnt=0;

			while(1)
			{

				//GRASSFIRE:

				for(m=r-1;m<=r+1;m++)
				{
					for(n=c-1;n<=c+1;n++)
					{
						if(m<0 || m>=V_HEIGHT || n<0 || n>=V_WIDTH)
							continue;
						if(pImage[m*V_WIDTH+n]==0xFFFFFF && coloring[m*V_WIDTH+n]==0)
						{
							coloring[m*V_WIDTH+n] = temp[cnt%10];
							icb[m*V_WIDTH+n]=ic;
							icc[ic]++;

							pImage6[m*V_WIDTH+n]=ic;
							//한색깔만 쓸거라서 cnt%10대신 빨간색temp[0]넣음
							if(push(stackx,stacky,arr_size,(short)m,(short)n,&top)==-1)
								continue;
							r=m;
							c=n;
							//	goto GRASSFIRE;

						}
					}
				}
				if(pop(stackx,stacky,&r,&c,&top)==-1) {
					ic++;
					break;
				}
			}
		}
	}
	/*
	FILE *fp7 = fopen("output1.txt","w");

	for(j = 0 ; j < V_HEIGHT ; j++)
	{
	for(i = 0 ; i < V_WIDTH ; i++)
	{
	fprintf(fp7,"%d ",pImage6[j*V_WIDTH + i]);
	}
	fprintf(fp7,"\n");

	}

	fclose(fp7);

	*/
	free(coloring);
	free(icc);
	free(icb);
	free(stackx);
	free(stacky);



}


void CDX_VIEW::BlobColoring_Label(long* pImage)
{

	int i,j,m,n,top;
	int ic=1;
	int k;
	int cent1=0;
	int cent2=0;
	int centc=0;
	int centx=0;
	int centy=0;
	int centcc=0;

	int centx2=0;
	int centy2=0;
	int centcc2=0;

	short r,c;
	int cnt = 0;
	unsigned int temp[10];//임시 색 저장공간
	temp[0] = setRGB(0, 0, 255);
	temp[1] = setRGB(100,50,0);
	temp[2] = setRGB(200,200,0);
	temp[3] = setRGB(255,255,200);
	temp[4] = setRGB(0,100,250);
	temp[5] = setRGB(0,255,0);
	temp[6] = setRGB(50,0,0);
	temp[7] = setRGB(255,0,0);
	temp[8] = setRGB(200,0,200);
	temp[9] = setRGB(0,200,200);

	short* stackx;
	short* stacky;
	stackx = (short *)malloc(320*240*4);
	stacky = (short *)malloc(320*240*4);
	int arr_size = 320*240;




	long* coloring;
	coloring = (long *)malloc(320*240*4);


	long* icb;
	icb = (long *)malloc(320*240*4);

	long* icc;
	icc = (long *)malloc(320*240*4);


	for(i=0;i<V_HEIGHT*V_WIDTH;i++)
	{
		coloring[i]=0;
		icb[i]=0;
		icc[i]=0;


	}

	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{
			if(coloring[i*V_WIDTH+j] != 0 || pImage[i*V_WIDTH+j] != 0xFFFFFF)
				continue;
			r=i; c=j; top=0;
			cnt++;
			if(cnt > 10)
				cnt=0;

			while(1)
			{

				//GRASSFIRE:

				for(m=r-1;m<=r+1;m++)
				{
					for(n=c-1;n<=c+1;n++)
					{
						if(m<0 || m>=V_HEIGHT || n<0 || n>=V_WIDTH)
							continue;
						if(pImage[m*V_WIDTH+n]==0xFFFFFF && coloring[m*V_WIDTH+n]==0)
						{
							coloring[m*V_WIDTH+n] = temp[cnt%10];
							icb[m*V_WIDTH+n]=ic;
							icc[ic]++;
							//한색깔만 쓸거라서 cnt%10대신 빨간색temp[0]넣음

							if(push(stackx,stacky,arr_size,(short)m,(short)n,&top)==-1)
								continue;
							r=m;
							c=n;
							//	goto GRASSFIRE;

						}
					}
				}
				if(pop(stackx,stacky,&r,&c,&top)==-1) {
					ic++;
					break;
				}
			}
		}
	}



	///////////////노이즈 제거
	for (k=1;k<100;k++)
	{
		if(icc[k]<100 && icc[k]>0)

			for(i=0;i<V_HEIGHT;i++)
			{
				for(j=0;j<V_WIDTH;j++)
				{
					if (icb[i*V_WIDTH+j]==k)
						icb[i*V_WIDTH+j]=0;


				}
			}
			if(icc[k]>100){
				cent1=k;
				centc++;
			}
			if(icc[k]>100 && centc==1){
				cent2=k;
			}

	}



	//////////////////////중점잡기
	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{
			if(icb[i*V_WIDTH+j]==0)

				coloring[i*V_WIDTH+j]=0;

			if(icb[i*V_WIDTH+j]==cent1)
			{
				centx+=j;
				centy+=i;
				centcc++;
			}

			if(icb[i*V_WIDTH+j]==cent2)
			{
				centx2+=j;
				centy2+=i;
				centcc2++;
			}



		}
	}
	int xx,yy;
	int xx2,yy2;
	xx=0; 
	yy=0;

	xx2=0; 
	yy2=0; 

	xx= centx/centcc;
	yy= centy/centcc;

	xx2= centx2/centcc2;
	yy2= centy2/centcc2;




	///노이즈 삭제


	//float grayGap = 250.0f/(float)curColor;


	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{


			pImage[i*V_WIDTH+j]=coloring[i*V_WIDTH+j];


		}
	}




	pImage[(yy-1)*V_WIDTH+xx-1]=setRGB(0,255,0);
	pImage[(yy-1)*V_WIDTH+xx]=setRGB(0,255,0);
	pImage[(yy-1)*V_WIDTH+xx+1]=setRGB(0,255,0);

	pImage[yy*V_WIDTH+xx-1]=setRGB(0,255,0);
	pImage[yy*V_WIDTH+xx]=setRGB(0,255,0);
	pImage[yy*V_WIDTH+xx+1]=setRGB(0,255,0);

	pImage[(yy+1)*V_WIDTH+xx-1]=setRGB(0,255,0);
	pImage[(yy+1)*V_WIDTH+xx]=setRGB(0,255,0);
	pImage[(yy+1)*V_WIDTH+xx+1]=setRGB(0,255,0);

	////////////////////////////////////////////
	pImage[(yy2-1)*V_WIDTH+xx2-1]=setRGB(255,0,0);
	pImage[(yy2-1)*V_WIDTH+xx2]=setRGB(255,0,0);
	pImage[(yy2-1)*V_WIDTH+xx2+1]=setRGB(255,0,0);

	pImage[yy2*V_WIDTH+xx2-1]=setRGB(255,0,0);
	pImage[yy2*V_WIDTH+xx2]=setRGB(255,0,0);
	pImage[yy2*V_WIDTH+xx2+1]=setRGB(255,0,0);

	pImage[(yy2+1)*V_WIDTH+xx2-1]=setRGB(255,0,0);
	pImage[(yy2+1)*V_WIDTH+xx2]=setRGB(255,0,0);
	pImage[(yy2+1)*V_WIDTH+xx2+1]=setRGB(255,0,0);
	////////////////////////////////////////////




	free(coloring);
	free(icc);
	free(icb);
	free(stackx);
	free(stacky);


	//	CString str;
	//	str.Format("%d",icc[10]);
	//	AfxMessageBox(str);


}
int init_q=0;
int f=0;
void drum_sound(int xx, int yy)
{
	int ch1=0;
	int ch2=0;
	int ch3=0;
	int ch4=0;
	int ch5=0;
	int ch6=0;
	int ch7=0;
	int ch8=0;
	int ch9=0;

	if(pImage6[yy*V_WIDTH+xx]==1)
	{
		if(ch1==0)//good
		{
			ch1=1;
			ch2=0;
			ch3=0;
			ch4=0;
			ch5=0;
			ch6=0;
			ch7=0;
			ch8=0;
			ch9=0;

			//mciSendString("play E:\\music\\SNARE2.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\SNARE2.wav",NULL,0,NULL);
		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==2)
	{
		if(ch2==0)
		{
			ch1=0;
			ch2=1;
			ch3=0;
			ch4=0;
			ch5=0;
			ch6=0;
			ch7=0;
			ch8=0;
			ch9=0;


			//mciSendString("play E:\\music\\HIHAT1.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\HIHAT1.wav",NULL,0,NULL);


		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==3)
	{
		if(ch3==0)
		{
			ch1=0;
			ch2=0;
			ch3=1;
			ch4=0;
			ch5=0;
			ch6=0;
			ch7=0;
			ch8=0;
			ch9=0;


			//mciSendString("play E:\\music\\CYM4.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\CYM4.wav",NULL,0,NULL);

		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==4)
	{
		if(ch4==0)
		{
			ch1=0;
			ch2=0;
			ch3=0;
			ch4=1;
			ch5=0;
			ch6=0;
			ch7=0;
			ch8=0;
			ch9=0;

			//mciSendString("play E:\\music\\CYM3.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\CYM3.wav",NULL,0,NULL);
		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==5)
	{
		if(ch5==0)
		{
			ch1=1;
			ch2=0;
			ch3=0;
			ch4=0;
			ch5=1;
			ch6=0;
			ch7=0;
			ch8=0;
			ch9=0;

			//mciSendString("play E:\\music\\TOM.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\TOM.wav",NULL,0,NULL);
		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==6)
	{
		if(ch6==0)
		{
			ch1=0;
			ch2=0;
			ch3=0;
			ch4=0;
			ch5=0;
			ch6=1;
			ch7=0;
			ch8=0;
			ch9=0;



			//mciSendString("play E:\\music\\HIHAT2.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\HIHAT2.wav",NULL,0,NULL);

		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==7)
	{
		if(ch7==0)
		{
			ch1=0;
			ch2=0;
			ch3=0;
			ch4=0;
			ch5=0;
			ch6=0;
			ch7=1;
			ch8=0;
			ch9=0;

			//mciSendString("play E:\\music\\SNARE1.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\SNARE1.wav",NULL,0,NULL);



		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==8)
	{
		if(ch8==0)
		{
			ch1=1;
			ch2=0;
			ch3=0;
			ch4=0;
			ch5=0;
			ch6=0;
			ch7=0;
			ch8=1;
			ch9=0;


			//mciSendString("play E:\\music\\CYM1.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\CYM1.wav",NULL,0,NULL);
		}


	}
	else if(pImage6[yy*V_WIDTH+xx]==9)
	{
		if(ch9==0)
		{
			ch1=0;
			ch2=0;
			ch3=0;
			ch4=0;
			ch5=0;
			ch6=0;
			ch7=0;
			ch8=0;
			ch9=1;

			//mciSendString("play E:\\music\\CYM2.wav",NULL,0,NULL);
			mciSendString("play C:\\music\\CYM2.wav",NULL,0,NULL);

		}


	}




}
void CDX_VIEW::BlobColoring(long* pImage)
{
	int num=0;
	int num_y=0;	
	int i,j,m,n,top;
	int ic=1;
	int k;
	int cent1=0;
	int cent2=0;
	int centc=0;
	int centx=0;
	int centy=0;
	int centcc=0;
	int count=0;
	int centx2=0;
	int centy2=0;
	int centcc2=0;

	short r,c;
	int cnt = 0;
	unsigned int temp[11];//임시 색 저장공간
	temp[0] = setRGB(0, 0, 255);   //색 세팅
	temp[1] = setRGB(100,50,0);
	temp[2] = setRGB(200,200,0);
	temp[3] = setRGB(255,255,200);
	temp[4] = setRGB(0,100,250);
	temp[5] = setRGB(0,255,0);
	temp[6] = setRGB(50,0,0);
	temp[7] = setRGB(255,0,0);
	temp[8] = setRGB(200,0,200);
	temp[9] = setRGB(0,200,200);   //색 세팅
	temp[10]=setRGB(255,255,0);
	short* stackx;    //포인터 
	short* stacky;   //포인터
	stackx = (short *)malloc(320*240*4);     //이미지 사이즈만큼 malloc
	stacky = (short *)malloc(320*240*4);        //이미지 사이즈만큼 malloc
	int arr_size = 320*240;       //stackx,y 사이즈


	if(init_q==0){  ///queue 초기화  
		init_queue();    //1 번 큐
		init_queue2();    //2번 큐
		init_q=1;     //큐 rear ++
	}


	long* coloring;    
	coloring = (long *)malloc(320*240*4);    //뭐하는 포인터?

	long* icb;       
	icb = (long *)malloc(320*240*4);

	long* icc;
	icc = (long *)malloc(320*240*4);


	for(i=0;i<V_HEIGHT*V_WIDTH;i++)
	{
		coloring[i]=0;
		icb[i]=0;
		icc[i]=0;


	}


	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{
			//	if(coloring[i*V_WIDTH+j] != 0 || pImage[i*V_WIDTH+j] != /*0xFFFFFF*/ setRGB(255,255,0)/*( pImage[i*V_WIDTH+j] != setRGB(255,255,0)  || pImage[i*V_WIDTH+j] != setRGB(255,0,0) || pImage[i*V_WIDTH+j] != setRGB(0,0,255) )*/)
			if(coloring[i*V_WIDTH+j]!=0 || (pImage[i*V_WIDTH+j]!=setRGB(255,0,0) && pImage[i*V_WIDTH+j]!=setRGB(255,255,0) && pImage[i*V_WIDTH+j]!=setRGB(0,0,255)) )
				continue;
			r=i; c=j; top=0;
			cnt++;
			if(cnt > 10)
				cnt=0;

			while(1)
			{

				//GRASSFIRE:

				for(m=r-1;m<=r+1;m++)
				{
					for(n=c-1;n<=c+1;n++)
					{
						if(m<0 || m>=V_HEIGHT || n<0 || n>=V_WIDTH)
							continue;
						if(pImage[m*V_WIDTH+n]==/*0xFFFFFF*/ setRGB(255,255,0)&& coloring[m*V_WIDTH+n]==0)
						{
							coloring[m*V_WIDTH+n] = temp[10];
							icb[m*V_WIDTH+n]=ic;
							icc[ic]++;
							//한색깔만 쓸거라서 cnt%10대신 빨간색temp[0]넣음
							if(push(stackx,stacky,arr_size,(short)m,(short)n,&top)==-1)
								continue;
							r=m;
							c=n;
							//	goto GRASSFIRE;

						}
						else if(pImage[m*V_WIDTH+n]==/*0xFFFFFF*/ setRGB(255,0,0)&& coloring[m*V_WIDTH+n]==0)
						{
							coloring[m*V_WIDTH+n] = temp[7];
							icb[m*V_WIDTH+n]=ic;
							icc[ic]++;
							//한색깔만 쓸거라서 cnt%10대신 빨간색temp[0]넣음
							if(push(stackx,stacky,arr_size,(short)m,(short)n,&top)==-1)
								continue;
							r=m;
							c=n;
							//	goto GRASSFIRE;

						}
						else if(pImage[m*V_WIDTH+n]==/*0xFFFFFF*/ setRGB(0,0,255)&& coloring[m*V_WIDTH+n]==0)
						{
							coloring[m*V_WIDTH+n] = temp[0];
							icb[m*V_WIDTH+n]=ic;
							icc[ic]++;
							//한색깔만 쓸거라서 cnt%10대신 빨간색temp[0]넣음
							if(push(stackx,stacky,arr_size,(short)m,(short)n,&top)==-1)
								continue;
							r=m;
							c=n;
							//	goto GRASSFIRE;

						}
					}
				}
				if(pop(stackx,stacky,&r,&c,&top)==-1) {
					ic++;
					break;
				}
			}
		}
	}
	///////////////노이즈 제거
	for (k=1;k<100;k++)
	{
		if(icc[k]<100 && icc[k]>0)
		{		
			for(i=0;i<V_HEIGHT;i++)
			{
				for(j=0;j<V_WIDTH;j++)
				{
					if (icb[i*V_WIDTH+j]==k)
						icb[i*V_WIDTH+j]=0;


				}
			}
		}
		if(icc[k]>100){
			cent1=k;
			centc++;
		}
		if(icc[k]>100 && centc==1){
			cent2=k;
		}

	}



	//////////////////////중점잡기
	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{
			if(icb[i*V_WIDTH+j]==0)
			{
				coloring[i*V_WIDTH+j]=0;
			}
			if(icb[i*V_WIDTH+j]==cent1)
			{
				centx+=j;
				centy+=i;
				centcc++;
			}

			if(icb[i*V_WIDTH+j]==cent2)
			{
				centx2+=j;
				centy2+=i;
				centcc2++;
			}
		}
	}
	/*int xx,yy;
	int xx2,yy2;*/


	xx= centx/centcc;
	yy= centy/centcc;

	xx2= centx2/centcc2;
	yy2= centy2/centcc2;


	///노이즈 삭제




	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{


			pImage[i*V_WIDTH+j]=coloring[i*V_WIDTH+j];
			if(coloring[i*V_WIDTH+j]!=0)//count는 라벨링된 픽셀의 크기를 나타냄
				count++;


		}
	}

	///////////////////queue내용///////////////



	int maxnum=0;
	int minnum=0;
	int maxy=0;
	int miny=0;
	int maxnum_index=0;
	int minnum_index=0;
	int maxy_index=0;
	int miny_index=0;
	int tem_num[3];
	int tem_y[3];

	put(count);
	print_queue();

	put2(yy);
	print_queue2();

	f++;
	if(f%3==0)
	{
		for(i=0;i<3;i++)
		{	tem_num[i]=get();
		tem_y[i]=get2();
		print_queue();
		print_queue2();
		f=0;
		}
	}

	maxnum=tem_num[0];
	minnum=tem_num[0];
	maxy=tem_y[0];
	miny=tem_y[0];

	for(i=0; i<3; i++)
	{
		if (maxnum<tem_num[i]){
			maxnum=tem_num[i];
			maxnum_index=i;
		}
		if (minnum>tem_num[i]){
			minnum=tem_num[i];
			minnum_index=i;
		}
		if (maxy<tem_y[i]){
			maxy=tem_y[i];
			maxy_index=i;
		}
		if (miny>tem_y[i]){
			miny=tem_y[i];
			miny_index=i;
		}

	}

	if(maxnum_index>minnum_index) 
		num=maxnum-minnum;
	else if(maxnum_index<minnum_index) 
		num=minnum-maxnum;
	if(maxy_index>miny_index) 
		num_y=miny-maxy;
	else if(maxy_index<miny_index) 
		num_y=maxy-miny;





	//////////////////////////////////////////





	if(count<10)
	{
		xx=0;
		yy=0;

	}
	else
	{
		//pImage[(yy-1)*V_WIDTH+xx-1]=setRGB(0,255,0);
		//pImage[(yy-1)*V_WIDTH+xx]=setRGB(0,255,0);
		//pImage[(yy-1)*V_WIDTH+xx+1]=setRGB(0,255,0);

		//pImage[yy*V_WIDTH+xx-1]=setRGB(0,255,0);
		//pImage[yy*V_WIDTH+xx]=setRGB(0,255,0);
		//pImage[yy*V_WIDTH+xx+1]=setRGB(0,255,0);

		//pImage[(yy+1)*V_WIDTH+xx-1]=setRGB(0,255,0);
		//pImage[(yy+1)*V_WIDTH+xx]=setRGB(0,255,0);
		//pImage[(yy+1)*V_WIDTH+xx+1]=setRGB(0,255,0);

		//////////////////////////////////////////////
		//pImage[(yy2-1)*V_WIDTH+xx2-1]=setRGB(255,0,0);
		//pImage[(yy2-1)*V_WIDTH+xx2]=setRGB(255,0,0);
		//pImage[(yy2-1)*V_WIDTH+xx2+1]=setRGB(255,0,0);

		//pImage[yy2*V_WIDTH+xx2-1]=setRGB(255,0,0);
		//pImage[yy2*V_WIDTH+xx2]=setRGB(255,0,0);
		//pImage[yy2*V_WIDTH+xx2+1]=setRGB(255,0,0);

		//pImage[(yy2+1)*V_WIDTH+xx2-1]=setRGB(255,0,0);
		//pImage[(yy2+1)*V_WIDTH+xx2]=setRGB(255,0,0);
		//pImage[(yy2+1)*V_WIDTH+xx2+1]=setRGB(255,0,0);
		//////////////////////////////////////////////


		if(pImage[(yy2)*V_WIDTH+xx2]==temp[7])
		{
			rcx=xx2;
			rcy=yy2;


			/*pImage[(rcy-1)*V_WIDTH+rcx-1]=setRGB(0,255,0);
			pImage[(rcy-1)*V_WIDTH+rcx]=setRGB(0,255,0);
			pImage[(rcy-1)*V_WIDTH+rcx+1]=setRGB(0,255,0);

			pImage[rcy*V_WIDTH+rcx-1]=setRGB(0,255,0);
			pImage[rcy*V_WIDTH+rcx]=setRGB(0,255,0);
			pImage[rcy*V_WIDTH+rcx+1]=setRGB(0,255,0);

			pImage[(rcy+1)*V_WIDTH+rcx-1]=setRGB(0,255,0);
			pImage[(rcy+1)*V_WIDTH+rcx]=setRGB(0,255,0);
			pImage[(rcy+1)*V_WIDTH+rcx+1]=setRGB(0,255,0);*/

			/*Rqueuex.push_back(rcx);
			Rqueuey.push_back(rcy);*/
			/*if(flag==1)
			{
			list<int>::iterator ix,iy;
			for( ix=tempRx.begin(),iy=tempRy.begin() ; ix!=tempRx.end(),iy!=tempRy.end() ; ix++,iy++ )
			{*/
			/*Rqueuex.push_back(*ix);
			Rqueuey.push_back(*iy);*/
			Rqueuex.push_back(rcx);
			Rqueuey.push_back(rcy);
			/*	}
			flag2=1;
			}
			else
			{*/
			/*	tempRx.push_back(rcx);
			tempRy.push_back(rcy);
			flag2=0;*/
			/*}*/
		}
		else if(pImage[(yy2)*V_WIDTH+xx2]==temp[10])
		{
			ycx=xx2;
			ycy=yy2;

			/*pImage[(ycy-1)*V_WIDTH+ycx-1]=setRGB(0,0,255);
			pImage[(ycy-1)*V_WIDTH+ycx]=setRGB(0,0,255);
			pImage[(ycy-1)*V_WIDTH+ycx+1]=setRGB(0,0,255);

			pImage[ycy*V_WIDTH+ycx-1]=setRGB(0,0,255);
			pImage[ycy*V_WIDTH+ycx]=setRGB(0,0,255);
			pImage[ycy*V_WIDTH+ycx+1]=setRGB(0,0,255);

			pImage[(ycy+1)*V_WIDTH+ycx-1]=setRGB(0,0,255);
			pImage[(ycy+1)*V_WIDTH+ycx]=setRGB(0,0,255);
			pImage[(ycy+1)*V_WIDTH+ycx+1]=setRGB(0,0,255);*/
			/*Yqueuex.push_back(ycx);
			Yqueuey.push_back(ycy);*/

			/*	if(flag==1)
			{
			list<int>::iterator ix,iy;
			for( ix=tempYx.begin(),iy=tempYy.begin() ; ix!=tempYx.end(),iy!=tempYy.end() ; ix++,iy++ )
			{*/
			Yqueuex.push_back(ycx);
			Yqueuey.push_back(ycy);
			/*	}
			flag2=1;
			}
			else
			{*/
			/*tempYx.push_back(rcx);
			tempYy.push_back(rcy);
			flag2=0;*/
			//}

		}
		else if(pImage[(yy2)*V_WIDTH+xx2]==temp[0])
		{
			bcx=xx2;
			bcy=yy2;

			//pImage[(bcy-1)*V_WIDTH+bcx-1]=setRGB(255,0,0);
			//pImage[(bcy-1)*V_WIDTH+bcx]=setRGB(255,0,0);
			//pImage[(bcy-1)*V_WIDTH+bcx+1]=setRGB(255,0,0);

			//pImage[bcy*V_WIDTH+bcx-1]=setRGB(255,0,0);
			//pImage[bcy*V_WIDTH+bcx]=setRGB(255,0,0);
			//pImage[bcy*V_WIDTH+bcx+1]=setRGB(255,0,0);

			//pImage[(bcy+1)*V_WIDTH+bcx-1]=setRGB(255,0,0);
			//pImage[(bcy+1)*V_WIDTH+bcx]=setRGB(255,0,0);
			//pImage[(bcy+1)*V_WIDTH+bcx+1]=setRGB(255,0,0);
			/*Bqueuex.push_back(bcx);
			Bqueuey.push_back(bcy);*/
			/*	if(flag==1)
			{
			list<int>::iterator ix,iy;
			for( ix=tempBx.begin(),iy=tempBy.begin() ; ix!=tempBx.end(),iy!=tempBy.end() ; ix++,iy++ )
			{*/
			/*Bqueuex.push_back(*ix);
			Bqueuey.push_back(*iy);*/
			Bqueuex.push_back(bcx);
			Bqueuey.push_back(bcy);
			/*		}
			flag2=1;
			}
			else
			{*/
			/*tempBx.push_back(rcx);
			tempBy.push_back(rcy);
			flag2=0;*/
			//	}
		}

		if(xx!=xx2 && yy!=yy2)
		{
			if(pImage[(yy)*V_WIDTH+xx]==temp[7])
			{
				rcx=xx;
				rcy=yy;

				/*pImage[(rcy-1)*V_WIDTH+rcx-1]=setRGB(0,255,0);
				pImage[(rcy-1)*V_WIDTH+rcx]=setRGB(0,255,0);
				pImage[(rcy-1)*V_WIDTH+rcx+1]=setRGB(0,255,0);

				pImage[rcy*V_WIDTH+rcx-1]=setRGB(0,255,0);
				pImage[rcy*V_WIDTH+rcx]=setRGB(0,255,0);
				pImage[rcy*V_WIDTH+rcx+1]=setRGB(0,255,0);

				pImage[(rcy+1)*V_WIDTH+rcx-1]=setRGB(0,255,0);
				pImage[(rcy+1)*V_WIDTH+rcx]=setRGB(0,255,0);
				pImage[(rcy+1)*V_WIDTH+rcx+1]=setRGB(0,255,0);*/

				/*Rqueuex.push_back(rcx);
				Rqueuey.push_back(rcy);*/


				/*	if(flag==1)
				{
				list<int>::iterator ix,iy;
				for( ix=tempRx.begin(),iy=tempRy.begin() ; ix!=tempRx.end(),iy!=tempRy.end() ; ix++,iy++ )
				{*/
				Rqueuex.push_back(rcx);
				Rqueuey.push_back(rcy);
				/*	}
				flag2=1;
				}
				else
				{*/
				//	tempRx.push_back(rcx);
				//tempRy.push_back(rcy);
				//flag2=0;
				//	}

			}
			else if(pImage[(yy)*V_WIDTH+xx]==temp[10])
			{
				ycx=xx;
				ycy=yy;

				/*pImage[(ycy-1)*V_WIDTH+ycx-1]=setRGB(0,0,255);
				pImage[(ycy-1)*V_WIDTH+ycx]=setRGB(0,0,255);
				pImage[(ycy-1)*V_WIDTH+ycx+1]=setRGB(0,0,255);

				pImage[ycy*V_WIDTH+ycx-1]=setRGB(0,0,255);
				pImage[ycy*V_WIDTH+ycx]=setRGB(0,0,255);
				pImage[ycy*V_WIDTH+ycx+1]=setRGB(0,0,255);

				pImage[(ycy+1)*V_WIDTH+ycx-1]=setRGB(0,0,255);
				pImage[(ycy+1)*V_WIDTH+ycx]=setRGB(0,0,255);
				pImage[(ycy+1)*V_WIDTH+ycx+1]=setRGB(0,0,255);*/
				/*Yqueuex.push_back(ycx);
				Yqueuey.push_back(ycy);*/



				/*	if(flag==1)
				{
				list<int>::iterator ix,iy;
				for( ix=tempYx.begin(),iy=tempYy.begin() ; ix!=tempYx.end(),iy!=tempYy.end() ; ix++,iy++ )
				{*/
				Yqueuex.push_back(ycx);
				Yqueuey.push_back(ycy);
				/*	}
				flag2=1;
				}
				else
				{*/
				/*tempYx.push_back(rcx);
				tempYy.push_back(rcy);
				flag2=0;*/
				//	}
			}
			else if(pImage[(yy)*V_WIDTH+xx]==temp[0])
			{
				bcx=xx;
				bcy=yy;

				/*pImage[(bcy-1)*V_WIDTH+bcx-1]=setRGB(255,0,0);
				pImage[(bcy-1)*V_WIDTH+bcx]=setRGB(255,0,0);
				pImage[(bcy-1)*V_WIDTH+bcx+1]=setRGB(255,0,0);

				pImage[bcy*V_WIDTH+bcx-1]=setRGB(255,0,0);
				pImage[bcy*V_WIDTH+bcx]=setRGB(255,0,0);
				pImage[bcy*V_WIDTH+bcx+1]=setRGB(255,0,0);

				pImage[(bcy+1)*V_WIDTH+bcx-1]=setRGB(255,0,0);
				pImage[(bcy+1)*V_WIDTH+bcx]=setRGB(255,0,0);
				pImage[(bcy+1)*V_WIDTH+bcx+1]=setRGB(255,0,0);*/
				/*Bqueuex.push_back(bcx);
				Bqueuey.push_back(bcy);*/


				/*if(flag==1)
				{
				list<int>::iterator ix,iy;
				for( ix=tempBx.begin(),iy=tempBy.begin() ; ix!=tempBx.end(),iy!=tempBy.end() ; ix++,iy++ )
				{*/
				Bqueuex.push_back(bcx);
				Bqueuey.push_back(bcy);
				/*		}
				flag2=1;
				}
				else
				{*/
				/*	tempBx.push_back(rcx);
				tempBy.push_back(rcy);
				flag2=0;*/
				//	}
			}
		}


		/////////////////////////////////


		////////////////////////////////////////////

		////////////////////////////////////////////

		/////////////////////////////////









	}

	count=0;	



	free(coloring);
	free(icc);
	free(icb);
	free(stackx);
	free(stacky);




}



// RGB -> HSV
void RGB2HSV(BYTE R, BYTE G, BYTE B, double *H, double *S, double *V)
{
	double var_R = (double)R / 255.0;
	double var_G = (double)G / 255.0;
	double var_B = (double)B / 255.0;

	double var_Min = min( min( var_R, var_G ), var_B );	// Min. value of RGB
	double var_Max = max( max( var_R, var_G ), var_B );	// Max. value of RGB

	*V = var_Max;

	if ( var_Min == var_Max )
	{	// This is a gray, no chroma...
		*H = 0;	// HSV results = 0 ÷ 1
		*S = 0;
	}
	else
	{	// Chromatic data...
		*S = ( var_Max - var_Min ) / var_Max;

		// Optimized
		//	delta = var_Max - var_Min
		//	del_R = ( ( ( var_Max - var_R ) / 6.0 ) + ( delta / 2.0 ) ) / delta
		//	      = ( var_Max - var_R ) / ( 6.0 * delta ) + 1.0 / 2.0
		//	del_R - del_G = ( ( var_Max - var_R ) / ( 6.0 * delta ) + 1.0 / 2.0 ) - ( ( var_Max - var_G ) / ( 6.0 * delta ) + 1.0 / 2.0 )
		//	              = ( var_Max - var_R - var_Max + var_G ) / ( 6.0 * delta ) + ( 1.0 / 2.0 ) - ( 1.0 / 2.0 )
		//	              = ( var_G - var_R ) / ( 6.0 * delta)
		//	              = ( var_G - var_R ) / 6.0 / delta

		if      ( var_R == var_Max ) *H = ( var_G - var_B ) / 6.0 / ( var_Max - var_Min );					// = ( del_B - del_G )
		else if ( var_G == var_Max ) *H = ( 1.0 / 3.0 ) + ( var_B - var_R ) / 6.0 / ( var_Max - var_Min );	// ( 1.0 / 3.0 ) + ( del_R - del_B )
		else if ( var_B == var_Max ) *H = ( 2.0 / 3.0 ) + ( var_R - var_G ) / 6.0 / ( var_Max - var_Min );	// ( 2.0 / 3.0 ) + ( del_G - del_R )

		if ( *H < 0.0 )	*H += 1.0;
		if ( *H > 1.0 )	*H -= 1.0;
	}
}

// HSV -> RGB
void HSV2RGB(double H, double S, double V, BYTE R, BYTE G, BYTE B)
{
	if ( S == 0.0 )	// HSV values = 0 ÷ 1
	{
		R = (unsigned char)(V * 255.0);
		G = R;
		B = R;
	}
	else
	{
		H *= 6.0;
		if ( H >= 6.0 ) H = 0.0;	// H must be < 1
		int var_h = int( H );		// Or ... var_i = floor( var_h )

		H -= double(var_h);
		V *= 255.0;

		unsigned char var_1 = (unsigned char)( V * ( 1.0 - S ) );
		unsigned char var_2 = (unsigned char)( V * ( 1.0 - S * H ) );
		unsigned char var_3 = (unsigned char)( V * ( 1.0 - S * ( 1.0 - H ) ) );
		unsigned char var_4 = (unsigned char)( V );

		if      ( var_h == 0 ) { R = var_4; G = var_3; B = var_1; }
		else if ( var_h == 1 ) { R = var_2; G = var_4; B = var_1; }
		else if ( var_h == 2 ) { R = var_1; G = var_4; B = var_3; }
		else if ( var_h == 3 ) { R = var_1; G = var_2; B = var_4; }
		else if ( var_h == 4 ) { R = var_3; G = var_1; B = var_4; }
		else                   { R = var_4; G = var_1; B = var_2; }
	}
}


void CDX_VIEW::Thresholding(long *pImage1,long* pImage4,  int RMIN, int RMAX, int GMIN, int GMAX, int BMIN, int BMAX)
{
	int i,j;
	BYTE R,G,B;
	double H,S,V;
	double min_h,max_h,min_s,max_s,min_v,max_v;
	min_h=((double)RMIN)/360;
	max_h=((double)RMAX)/360;
	min_s=((double)GMIN)/100;
	max_s=((double)GMAX)/100;
	min_v=((double)BMIN)/100;
	max_v=((double)BMAX)/100;

	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{
			R = pImage1[j*V_WIDTH + i] & 0xFF;
			G = (pImage1[j*V_WIDTH + i]>>8) & 0xFF;
			B = (pImage1[j*V_WIDTH + i]>>16) & 0xFF;

			/*B=pImage1[j*V_WIDTH+i]*0.114;
			G=pImage1[j*V_WIDTH+i+1]*0.587;
			R=pImage1[j*V_WIDTH+i+2]*0.299;*/

			RGB2HSV(R, G, B, &H, &S, &V);

			if(R < RMIN || R > RMAX ||G < GMIN || G > GMAX ||B < BMIN || B > BMAX)
			{
				if(H < min_h || H > max_h || S < min_s || S > max_s || V < min_v || V > max_v){

					pImage1[j*V_WIDTH + i] = 0;


				}}
		}

	}	


}

void CDX_VIEW::Thresholding2(long *pImage,long* pImage5,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX , int RMIN, int RMAX, int GMIN, int GMAX, int BMIN, int BMAX)
{
	int i,j;
	BYTE R,G,B;
	double H,S,V;
	double min_h,max_h,min_s,max_s,min_v,max_v;
	min_h=((double)HMIN)/360;
	max_h=((double)HMAX)/360;
	min_s=((double)SMIN)/100;
	max_s=((double)SMAX)/100;
	min_v=((double)VMIN)/100;
	max_v=((double)VMAX)/100;

	double min_h1,max_h1,min_s1,max_s1,min_v1,max_v1;
	min_h1=((double)RMIN)/360;
	max_h1=((double)RMAX)/360;
	min_s1=((double)GMIN)/100;
	max_s1=((double)GMAX)/100;
	min_v1=((double)BMIN)/100;
	max_v1=((double)BMAX)/100;


	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{
			R = pImage[j*V_WIDTH + i] & 0xFF;
			G = (pImage[j*V_WIDTH + i]>>8) & 0xFF;
			B = (pImage[j*V_WIDTH + i]>>16) & 0xFF;

			RGB2HSV(R, G, B, &H, &S, &V);

			if(R < RMIN || R > RMAX ||G < GMIN || G > GMAX ||B < BMIN || B > BMAX)
			{
				if(H < min_h || H > max_h || S < min_s || S > max_s || V < min_v || V > max_v){

					pImage[j*V_WIDTH + i] = 0;


				}}
		}

	}	




	//CString str;
	//str.Format("%d",HMIN);
	//AfxMessageBox(str);


}






void CDX_VIEW::red_scale(long *pImage1,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX , int RMIN, int RMAX, int GMIN, int GMAX, int BMIN, int BMAX)
{
	const float RtD = 57.29577951f, DtR =0.017453293f; //라디안 디그리 변환 상수 

	float R,G,B;
	float H,S,I;
	float min=0;
	int i,j;

	float VMAXY=((float)VMAX);
	float VMINY=((float)VMIN);

	for(i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH;j++)
		{

			R = pImage1[i*V_WIDTH + j] & 0xFF;
			G = (pImage1[i*V_WIDTH + j]>>8) & 0xFF;
			B = (pImage1[i*V_WIDTH + j]>>16) & 0xFF;

			//RGB 최소값
			if(R < G) min = R; else min = G;
			if(min > B) min = B;

			//계산 
			I = (R + G + B)*0.333333;    
			S = 1 - ( (3.0/(R+G+B+0.001))*(min));   
			H = acos(((0.5*((R-G)+(R-B)))/(sqrt(1+((R-G)*(R-G))+(R-B)*(G-B)))));    
			if( B > G ) H = (360 - H*RtD)*DtR;


			//	if(R < RMIN || R > RMAX ||G < GMIN || G > GMAX ||B < BMIN || B > BMAX)
			{
				if(H<HMIN || H>HMAX || S<SMIN || S>SMAX || I<VMIN || I>VMAX)
				{
					pImage1[j*V_WIDTH + i] = 0;
				}
			}



		}
	}
}






void CDX_VIEW::reverse_Image(long* pImage)
{
	long temp;


	int j;

	for(int i=0;i<V_HEIGHT;i++)
	{
		for(j=0;j<V_WIDTH/2;j++)
		{
			temp=pImage[i*V_WIDTH+j];
			pImage[i*V_WIDTH+j]=pImage[((i*V_WIDTH)+(V_WIDTH-1))-j];
			pImage[((i*V_WIDTH)+(V_WIDTH-1))-j]=temp;
		}
	}
}



void CDX_VIEW::Thresholding_Yellow(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX )
{
	int i,j;
	BYTE R,G,B;
	double H,S,V;
	double min_h,max_h,min_s,max_s,min_v,max_v;
	min_h=((double)HMIN)/360;
	max_h=((double)HMAX)/360;
	min_s=((double)SMIN)/100;
	max_s=((double)SMAX)/100;
	min_v=((double)VMIN)/100;
	max_v=((double)VMAX)/100;


	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{
			R = pImage[j*V_WIDTH + i] & 0xFF;
			G = (pImage[j*V_WIDTH + i]>>8) & 0xFF;
			B = (pImage[j*V_WIDTH + i]>>16) & 0xFF;

			RGB2HSV(R, G, B, &H, &S, &V);

			if(min_h<H && H<max_h && min_s<S && S<max_s && min_v<V && V<max_v)
			{
				//drawing_Image[j*V_WIDTH+i]=pImage[j*V_WIDTH+i];
				drawing_Image[j*V_WIDTH+i]=setRGB(255,255,0);
			}
		}

	}	



}


void CDX_VIEW::Thresholding_Blue(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX )
{
	int i,j;
	BYTE R,G,B;
	double H,S,V;
	double min_h,max_h,min_s,max_s,min_v,max_v;
	
	min_h=((double)HMIN)/360;
	max_h=((double)HMAX)/360;
	min_s=((double)SMIN)/100;
	max_s=((double)SMAX)/100;
	min_v=((double)VMIN)/100;
	max_v=((double)VMAX)/100;



	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{
			R = pImage[j*V_WIDTH + i] & 0xFF;
			G = (pImage[j*V_WIDTH + i]>>8) & 0xFF;
			B = (pImage[j*V_WIDTH + i]>>16) & 0xFF;

			RGB2HSV(R, G, B, &H, &S, &V);


			if(min_h<H && H<max_h && min_s<S && S<max_s && min_v<V && V<max_v)
			{
				//drawing_Image[j*V_WIDTH+i]=pImage[j*V_WIDTH+i];
				drawing_Image[j*V_WIDTH+i]=setRGB(0,0,255);
			}
		}

	}	

}




void CDX_VIEW::Thresholding_Red(long* pImage,int HMIN, int HMAX, int SMIN, int SMAX, int VMIN, int VMAX )
{
	int i,j;
	BYTE R,G,B;
	double H,S,V;
	double min_h,max_h,min_s,max_s,min_v,max_v;
	min_h=((double)HMIN)/360;
	max_h=((double)HMAX)/360;
	min_s=((double)SMIN)/100;
	max_s=((double)SMAX)/100;
	min_v=((double)VMIN)/100;
	max_v=((double)VMAX)/100;




	for(j = 0 ; j < V_HEIGHT ; j++)
	{
		for(i = 0 ; i < V_WIDTH ; i++)
		{
			R = pImage[j*V_WIDTH + i] & 0xFF;
			G = (pImage[j*V_WIDTH + i]>>8) & 0xFF;
			B = (pImage[j*V_WIDTH + i]>>16) & 0xFF;

			RGB2HSV(R, G, B, &H, &S, &V);

			//if(R < RMIN || R > RMAX ||G < GMIN || G > GMAX ||B < BMIN || B > BMAX)

			/*if(H < min_h || H > max_h || S < min_s || S > max_s || V < min_v || V > max_v)
			{

			pImage[j*V_WIDTH + i] = 0;


			}*/
			if(min_h<H && H<max_h && min_s<S && S<max_s && min_v<V && V<max_v)
			{
				//drawing_Image[j*V_WIDTH+i]=pImage[j*V_WIDTH+i];
				drawing_Image[j*V_WIDTH+i]=setRGB(255,0,0);
			}
		}

	}	

}


void CDX_VIEW::Morphology(long * pImage)
{
	long * temp_Image=new long[V_HEIGHT*V_WIDTH*sizeof(long)];
	memset(temp_Image,0,sizeof(temp_Image));
	int i,j,count=0;
	for(int k=0;k<1;k++)
	{
		for(i=1;i<V_HEIGHT-1;i++)
		{
			for(j=1;j<V_WIDTH-1;j++)
			{

				if(pImage[i*V_WIDTH+j]==setRGB(255,0,0))
				{
					if(setRGB(255,0,0) == pImage[i*V_WIDTH+(j-1)])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[(i-1)*V_WIDTH+(j-1)])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[(i-1)*V_WIDTH+j])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[(i-1)*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[i*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[(i+1)*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[(i+1)*V_WIDTH+j])
					{
						count++;
					}
					if(setRGB(255,0,0) == pImage[(i+1)*V_WIDTH+(j-1)])
					{
						count++;
					}

					if(count==8)
					{
						temp_Image[i*V_WIDTH+j]=setRGB(255,0,0);
					}
					else
					{
						temp_Image[i*V_WIDTH+j]=0;
					}
					count=0;
				}

				else if(pImage[i*V_WIDTH+j]==setRGB(0,0,255))
				{
					if(setRGB(0,0,255) == pImage[i*V_WIDTH+(j-1)])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[(i-1)*V_WIDTH+(j-1)])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[(i-1)*V_WIDTH+j])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[(i-1)*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[i*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[(i+1)*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[(i+1)*V_WIDTH+j])
					{
						count++;
					}
					if(setRGB(0,0,255) == pImage[(i+1)*V_WIDTH+(j-1)])
					{
						count++;
					}

					if(count==8)
					{
						temp_Image[i*V_WIDTH+j]=setRGB(0,0,255);
					}
					else
					{
						temp_Image[i*V_WIDTH+j]=0;
					}
					count=0;
				}

				else if(pImage[i*V_WIDTH+j]==setRGB(255,255,0))
				{
					if(setRGB(255,255,0) == pImage[i*V_WIDTH+(j-1)])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[(i-1)*V_WIDTH+(j-1)])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[(i-1)*V_WIDTH+j])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[(i-1)*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[i*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[(i+1)*V_WIDTH+(j+1)])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[(i+1)*V_WIDTH+j])
					{
						count++;
					}
					if(setRGB(255,255,0) == pImage[(i+1)*V_WIDTH+(j-1)])
					{
						count++;
					}

					if(count==8)
					{
						temp_Image[i*V_WIDTH+j]=setRGB(255,255,0);
					}
					else
					{
						temp_Image[i*V_WIDTH+j]=0;
					}
					count=0;
				}

			}
		}
	}
	memcpy(pImage,temp_Image,sizeof(pImage));
	delete [] temp_Image;
}







void CDX_VIEW::draw_orbit(long *pImage1,LPVIDEOHDR lpVHDR)    //완성본
{

	long temp;


	BYTE * Image=new BYTE[V_WIDTH*V_HEIGHT*3];
	memset((BYTE *)Image,255, V_WIDTH*V_HEIGHT*3);

	if(Rqueuex.empty()==false)
	{

		temp=setRGB(255,0,0);
		px=Rqueuex.begin();
		py=Rqueuey.begin();
		for(Rx=Rqueuex.begin(),Ry=Rqueuey.begin() ; Rx!=Rqueuex.end(),Ry!=Rqueuey.end() ;Rx++,Ry++)
		{
			/*cnt++;*/
			if(Rqueuex.size()!=1)
			{


				pImage1[((*Ry)-1)*V_WIDTH+(*Rx)-1]=temp;
				pImage1[((*Ry)-1)*V_WIDTH+(*Rx)]=temp;
				pImage1[((*Ry)-1)*V_WIDTH+(*Rx)+1]=temp;

				pImage1[(*Ry)*V_WIDTH+(*Rx)-1]=temp;
				pImage1[(*Ry)*V_WIDTH+(*Rx)]=temp;
				pImage1[(*Ry)*V_WIDTH+(*Rx)+1]=temp;

				pImage1[((*Ry)+1)*V_WIDTH+(*Rx)-1]=temp;
				pImage1[((*Ry)+1)*V_WIDTH+(*Rx)]=temp;
				pImage1[((*Ry)+1)*V_WIDTH+(*Rx)+1]=temp;

				pImage1[((*Ry)-2)*V_WIDTH+(*Rx)-2]=temp;
				pImage1[((*Ry)-2)*V_WIDTH+(*Rx)]=temp;
				pImage1[((*Ry)-2)*V_WIDTH+(*Rx)+2]=temp;

				pImage1[(*Ry)*V_WIDTH+(*Rx)-2]=temp;
				pImage1[(*Ry)*V_WIDTH+(*Rx)]=temp;
				pImage1[(*Ry)*V_WIDTH+(*Rx)+2]=temp;

				pImage1[((*Ry)+2)*V_WIDTH+(*Rx)-2]=temp;
				pImage1[((*Ry)+2)*V_WIDTH+(*Rx)]=temp;
				pImage1[((*Ry)+2)*V_WIDTH+(*Rx)+2]=temp;

				////////////////////////////////////////
				Image[((*Ry)-1)*(V_WIDTH*3)+(*Rx)-1]=0;
				Image[((*Ry)-1)*(V_WIDTH*3)+(*Rx)]=0;
				Image[((*Ry)-1)*(V_WIDTH*3)+(*Rx)+1]=0;

				Image[(*Ry)*(V_WIDTH*3)+(*Rx)-1]=0;
				Image[(*Ry)*(V_WIDTH*3)+(*Rx)]=0;
				Image[(*Ry)*(V_WIDTH*3)+(*Rx)+1]=0;

				Image[((*Ry)+1)*(V_WIDTH*3)+(*Rx)-1]=0;
				Image[((*Ry)+1)*(V_WIDTH*3)+(*Rx)]=0;
				Image[((*Ry)+1)*(V_WIDTH*3)+(*Rx)+1]=0;

				Image[((*Ry)-2)*(V_WIDTH*3)+(*Rx)-2]=0;
				Image[((*Ry)-2)*(V_WIDTH*3)+(*Rx)]=0;
				Image[((*Ry)-2)*(V_WIDTH*3)+(*Rx)+2]=0;

				Image[(*Ry)*(V_WIDTH*3)+(*Rx)-2]=0;
				Image[(*Ry)*(V_WIDTH*3)+(*Rx)]=0;
				Image[(*Ry)*(V_WIDTH*3)+(*Rx)+2]=0;

				Image[((*Ry)+2)*(V_WIDTH*3)+(*Rx)-2]=0;
				Image[((*Ry)+2)*(V_WIDTH*3)+(*Rx)]=0;
				Image[((*Ry)+2)*(V_WIDTH*3)+(*Rx)+2]=0;


			



			}


			px=Rx;
			py=Ry;
		}


	}


	if(Rqueuex.size()==80)
	{
		bmout.output(/*lpVHDR->lpData*/Image);
		Rqueuex.clear();
		Rqueuey.clear();
	}



	if(Yqueuex.empty()==false)
	{
		temp=setRGB(255,255,0);
		px=Yqueuex.begin();
		py=Yqueuey.begin();
		for(Yx=Yqueuex.begin(),Yy=Yqueuey.begin() ; Yx!=Yqueuex.end(),Yy!=Yqueuey.end() ;Yx++,Yy++)
		{
			if(Yqueuex.size()!=1)
			{

				pImage1[((*Yy)-1)*V_WIDTH+(*Yx)-1]=temp;
				pImage1[((*Yy)-1)*V_WIDTH+(*Yx)]=temp;
				pImage1[((*Yy)-1)*V_WIDTH+(*Yx)+1]=temp;

				pImage1[(*Yy)*V_WIDTH+(*Yx)-1]=temp;
				pImage1[(*Yy)*V_WIDTH+(*Yx)]=temp;
				pImage1[(*Yy)*V_WIDTH+(*Yx)+1]=temp;

				pImage1[((*Yy)+1)*V_WIDTH+(*Yx)-1]=temp;
				pImage1[((*Yy)+1)*V_WIDTH+(*Yx)]=temp;
				pImage1[((*Yy)+1)*V_WIDTH+(*Yx)+1]=temp;

				pImage1[((*Yy)-2)*V_WIDTH+(*Yx)-2]=temp;
				pImage1[((*Yy)-2)*V_WIDTH+(*Yx)]=temp;
				pImage1[((*Yy)-2)*V_WIDTH+(*Yx)+2]=temp;

				pImage1[(*Yy)*V_WIDTH+(*Yx)-2]=temp;
				pImage1[(*Yy)*V_WIDTH+(*Yx)]=temp;
				pImage1[(*Yy)*V_WIDTH+(*Yx)+2]=temp;

				pImage1[((*Yy)+2)*V_WIDTH+(*Yx)-2]=temp;
				pImage1[((*Yy)+2)*V_WIDTH+(*Yx)]=temp;
				pImage1[((*Yy)+2)*V_WIDTH+(*Yx)+2]=temp;

				Image[((*Yy)-1)*(V_WIDTH*3)+(*Yx)-1]=0;
				Image[((*Yy)-1)*(V_WIDTH*3)+(*Yx)]=0;
				Image[((*Yy)-1)*(V_WIDTH*3)+(*Yx)+1]=0;

				Image[(*Yy)*(V_WIDTH*3)+(*Yx)-1]=0;
				Image[(*Yy)*(V_WIDTH*3)+(*Yx)]=0;
				Image[(*Yy)*(V_WIDTH*3)+(*Yx)+1]=0;

				Image[((*Yy)+1)*(V_WIDTH*3)+(*Yx)-1]=0;
				Image[((*Yy)+1)*(V_WIDTH*3)+(*Yx)]=0;
				Image[((*Yy)+1)*(V_WIDTH*3)+(*Yx)+1]=0;

				Image[((*Yy)-2)*(V_WIDTH*3)+(*Yx)-2]=0;
				Image[((*Yy)-2)*(V_WIDTH*3)+(*Yx)]=0;
				Image[((*Yy)-2)*(V_WIDTH*3)+(*Yx)+2]=0;

				Image[(*Yy)*(V_WIDTH*3)+(*Yx)-2]=0;
				Image[(*Yy)*(V_WIDTH*3)+(*Yx)]=0;
				Image[(*Yy)*(V_WIDTH*3)+(*Yx)+2]=0;

				Image[((*Yy)+2)*(V_WIDTH*3)+(*Yx)-2]=0;
				Image[((*Yy)+2)*(V_WIDTH*3)+(*Yx)]=0;
				Image[((*Yy)+2)*(V_WIDTH*3)+(*Yx)+2]=0;



			}

			px=Yx;
			py=Yy;
		}
	}

	if(Yqueuex.size()==80)
	{
		bmout.output(Image);
		Yqueuex.clear();
		Yqueuey.clear();
	}


	if(Bqueuex.empty()==false)
	{
		if(flexflag==1)
		{
			printf("flexflag=1\n");
			temp=setRGB(0,0,255);
			Bx=Bqueuex.begin();
			By=Bqueuey.begin();
			pImage1[((*By)-1)*V_WIDTH+(*Bx)-1]=temp;
			pImage1[((*By)-1)*V_WIDTH+(*Bx)]=temp;
			pImage1[((*By)-1)*V_WIDTH+(*Bx)+1]=temp;

			pImage1[(*By)*V_WIDTH+(*Bx)-1]=temp;
			pImage1[(*By)*V_WIDTH+(*Bx)]=temp;
			pImage1[(*By)*V_WIDTH+(*Bx)+1]=temp;

			pImage1[((*By)+1)*V_WIDTH+(*Bx)-1]=temp;
			pImage1[((*By)+1)*V_WIDTH+(*Bx)]=temp;
			pImage1[((*By)+1)*V_WIDTH+(*Bx)+1]=temp;

			pImage1[((*By)-2)*V_WIDTH+(*Bx)-2]=temp;
			pImage1[((*By)-2)*V_WIDTH+(*Bx)]=temp;
			pImage1[((*By)-2)*V_WIDTH+(*Bx)+2]=temp;

			pImage1[(*By)*V_WIDTH+(*Bx)-2]=temp;
			pImage1[(*By)*V_WIDTH+(*Bx)]=temp;
			pImage1[(*By)*V_WIDTH+(*Bx)+2]=temp;

			pImage1[((*By)+2)*V_WIDTH+(*Bx)-2]=temp;
			pImage1[((*By)+2)*V_WIDTH+(*Bx)]=temp;
			pImage1[((*By)+2)*V_WIDTH+(*Bx)+2]=temp;

			Image[((*By)-1)*V_WIDTH+(*Bx)-1]=temp;
			Image[((*By)-1)*V_WIDTH+(*Bx)]=temp;
			Image[((*By)-1)*V_WIDTH+(*Bx)+1]=temp;

			Image[(*By)*V_WIDTH+(*Bx)-1]=temp;
			Image[(*By)*V_WIDTH+(*Bx)]=temp;
			Image[(*By)*V_WIDTH+(*Bx)+1]=temp;

			Image[((*By)+1)*V_WIDTH+(*Bx)-1]=temp;
			Image[((*By)+1)*V_WIDTH+(*Bx)]=temp;
			Image[((*By)+1)*V_WIDTH+(*Bx)+1]=temp;

			Image[((*By)-2)*V_WIDTH+(*Bx)-2]=temp;
			Image[((*By)-2)*V_WIDTH+(*Bx)]=temp;
			Image[((*By)-2)*V_WIDTH+(*Bx)+2]=temp;

			Image[(*By)*V_WIDTH+(*Bx)-2]=temp;
			Image[(*By)*V_WIDTH+(*Bx)]=temp;
			Image[(*By)*V_WIDTH+(*Bx)+2]=temp;

			Image[((*By)+2)*V_WIDTH+(*Bx)-2]=temp;
			Image[((*By)+2)*V_WIDTH+(*Bx)]=temp;
			Image[((*By)+2)*V_WIDTH+(*Bx)+2]=temp;

			Bqueuex.clear();
			Bqueuey.clear();
			flexflag=0;
			printf("flexflag=0\n");
		}

	}


	delete [] Image;

}


void CDX_VIEW::parsing(char * data,int length)
{


	int flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Speed_x=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Speed_y=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}

	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Speed_z=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Range_x=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Range_y=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Range_z=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Angle_x=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Angle_y=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Angle_z=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_Angle_center=atof(data);
				flag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}


		/*if(device_Angle_center > 0.0)
		{
		if(test[1] == 0)
		{
		test[0] = (int)device_Angle_center;
		test[1] = 1;
		}
		}*/

	}
	flag=0;
	for(data;data!=NULL;data++)
	{
		if(flag==0)
		{
			if(*data=='-' || ('0'<=*data && *data<='9'))
			{	
				device_flex=atof(data);
				flag=1;
				flexflag=1;
			}
		}
		else
		{
			if(*data=='.')
			{
			}
			else if('0'>*data || *data>'9')
			{
				break;
			}
		}

		/*	if(device_flex > 450.0)
		{
		if(test2[1] == 0)
		{
		test2[0] = (int)device_flex;
		test2[1] = 1;
		}
		}*/

	}

}


void CDX_VIEW::output_conduction(long * pImage)
{

	FILE *infile;
	infile = fopen("2.bmp", "rb");


	// BMP Header Information
	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;
	fread(&hf, sizeof(BITMAPFILEHEADER),1,infile);

	fread(&hInfo,sizeof(BITMAPINFOHEADER),1,infile);


	// BMP Pallete
	RGBQUAD hRGB[256];
	fread(hRGB, sizeof(RGBQUAD), 256, infile);

	// Memory
	BYTE *lpImg = new BYTE [hInfo.biSizeImage];
	fread(lpImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);



	for(int i=0;i<97;i++)
	{
		for(int j=0;j<105;j++)
		{
			pImage[i*105+j]=lpImg[i*105+j];
		}
	}

	delete [] lpImg;

}


void CDX_VIEW::draw_draw(long * pImage)
{
	for(int i=0;i<V_HEIGHT;i++)
	{
		pImage[i*V_WIDTH+50]=setRGB(0,255,0);

		pImage[i*V_WIDTH+100]=setRGB(0,255,0);
	}
	for(int i=0;i<100;i++)
	{
		pImage[120*V_WIDTH+i]=setRGB(0,255,0);
	}


}




void CDX_VIEW::DrumImage(long* pImage)
{
	int i,j;

	unsigned char pImage33[320*240*3];

	for(j=0;j<V_HEIGHT;j++)
	{
		for(i=0;i<V_WIDTH;i++)
		{
			pImage33[j*V_WIDTH+i]=0;
		}
	}

	FILE *fp = fopen("input.raw","r"); //화면에 띄울 드럼 이미지


	//FILE *fp = fopen("mast_raw.raw","r"); //화면에 띄울 드럼 이미지

	if(fp!=NULL)
	{
		fread(pImage33,sizeof(char),320*240*3,fp);
		fclose(fp);
	}
	else
	{
		perror("can't file open");
	}

	ConvertRGB24to32(pImage33,pImage77);




	long temp=setRGB(255,255,255);
	for(int i=0;i<V_HEIGHT;i++)
	{
		for(int j=100;j<120;j++)
		{
			pImage[i*V_WIDTH+j]=temp;
		}
		for(int j=120;j<280;j++)
		{
			pImage[i*V_WIDTH+j]=pImage77[i*V_WIDTH+(/*j-120*/280-j)];
		}
		for(int j=280;j<V_WIDTH;j++)
		{
			pImage[i*V_WIDTH+j]=temp;
		}
	}
}



