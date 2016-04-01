#pragma once
#include "stdafx.h"
#include "Global.h"
#include <math.h>
#include <Windows.h>

CDX_VIEW *pCView;
BITMAPINFO			g_BitInfo;	 		 // ĸ�ĵ� �̹��� ����
unsigned char				*g_pMapMemory;	 	 // ĸ�ĵ� �̹��� DIB������ ������ ����
BOOL m_IsCapture;


BOOL bTHRES, bBINARY, bOPEN, bLABELING, bTHRES2,bDrum,bOpen2,TEST,RED,GREEN,YELLOW,BLUE;
int YHMIN, YHMAX, YSMIN, YSMAX, YVMIN, YVMAX,RMIN, RMAX, GMIN, GMAX, BMIN, BMAX,RHMIN, RHMAX, RSMIN, RSMAX, RVMIN, RVMAX,BHMIN, BHMAX, BSMIN, BSMAX, BVMIN, BVMAX;

LRESULT CALLBACK VideoStreamCallbackProc(HWND hwnd, LPVIDEOHDR lpVHDR)
{
	//�ڵ����μ������� �����Ҽ� �ֵ��� �޸� �� ���Ͽ� DIB�����͸� �����մϴ�.
	::memcpy( g_pMapMemory, lpVHDR->lpData, lpVHDR->dwBytesUsed );
	//int i;
	pCView->ConvertRGB24to32(g_pMapMemory,pCView->OneDisplayGroundArray);
	//�̰� �߰� ����

	//OneDisplayGroundArray �̰� ȭ�鿡 �Ѹ��� ����迭�� ����
	//if(bTHRES)	pCView->Thresholding(pCView->OneDisplayGroundArray,pCView->OneDisplayGroundArray1, RMIN, RMAX, GMIN, GMAX, BMIN, BMAX);

	/*
	pCView->Thresholding(pCView->OneDisplayGroundArray,pCView->OneDisplayGroundArray1, RMIN, RMAX, GMIN, GMAX, BMIN, BMAX);
	if(bTHRES2)	pCView->Thresholding2(pCView->OneDisplayGroundArray,pCView->OneDisplayGroundArray1, HMIN, HMAX, SMIN, SMAX, VMIN, VMAX,RMIN, RMAX, GMIN, GMAX, BMIN, BMAX);


	if(bBINARY)	pCView->Binary_Image(pCView->OneDisplayGroundArray);

	if(bOPEN)pCView->Open_Image(pCView->OneDisplayGroundArray);


	if(bLABELING)pCView->BlobColoring(pCView->OneDisplayGroundArray);

	if(bBinary) pCView->Binary_Image(pCView->OneDisplayGroundArray,Binary_bar);

	if(bDrum){
	pCView->DrumImage(pCView->OneDisplayGroundArray);	
	pCView->DrumImage_Label(pCView->OneDisplayGroundArray);
	}*/

	//pCView->red_scale(pCView->OneDisplayGroundArray, HMIN,  HMAX,  SMIN,  SMAX,  VMIN,  VMAX ,  RMIN,  RMAX,  GMIN,  GMAX,  BMIN,  BMAX);

	/*if(pCView->drawing_Image==NULL)
	{
	pCView->drawing_Image=new long [V_HEIGHT*V_WIDTH*sizeof(long)];
	memset(pCView->drawing_Image,0,10);
	}*/

	pCView->reverse_Image(pCView->OneDisplayGroundArray);

	//pCView->Thresholding2(pCView->OneDisplayGroundArray,pCView->OneDisplayGroundArray1,HMIN,  HMAX,  SMIN,  SMAX,  VMIN,  VMAX ,  RMIN,  RMAX,  GMIN,  GMAX,  BMIN,  BMAX);


	/*if(YELLOW)
	{
	pCView->Thresholding_Yellow(pCView->OneDisplayGroundArray);
	}
	if(BLUE)
	{
	pCView->Thresholding_Blue(pCView->OneDisplayGroundArray);
	}


	if(TEST)
	{
	pCView->Binary_Image(pCView->OneDisplayGroundArray);
	pCView->BlobColoring(pCView->OneDisplayGroundArray);
	pCView->draw_orbit(pCView->OneDisplayGroundArray);
	}
	*/
	if(pCView->drawing_Image==NULL)
	{
		pCView->drawing_Image=new long[V_HEIGHT*V_WIDTH*sizeof(long)];
		memset((long *)pCView->drawing_Image,0,sizeof(pCView->OneDisplayGroundArray));
	}


	//pCView->output_conduction(pCView->OneDisplayGroundArray);


	if(YELLOW)  // draw_image �� ����� �Է�  
	{
		pCView->Thresholding_Yellow(pCView->OneDisplayGroundArray,YHMIN,YHMAX,YSMIN,YSMAX,YVMIN,YVMAX);
	}
	if(BLUE)  //2  draw_image�� �۷���
	{
		pCView->Thresholding_Blue(pCView->OneDisplayGroundArray,BHMIN,BHMAX,BSMIN,BSMAX,BVMIN,BVMAX);
	}

	if(RED)  //1    draw_image�� ���ϻ�
	{
		pCView->Thresholding_Red(pCView->OneDisplayGroundArray,RHMIN,RHMAX,RSMIN,RSMAX,RVMIN,RVMAX);
	}

	if(TEST==TRUE)
	{
		//pCView->Binary_Image(pCView->drawing_Image);
		//pCView->BlobColoring(pCView->drawing_Image);

		//if(pCView->drawing_Image2==NULL)
		//{
		//pCView->drawing_Image2=new long [V_HEIGHT*V_WIDTH*sizeof(long)];
		//memset(pCView->drawing_Image2,0,10);
		//}
		//pCView->draw_orbit(pCView->OneDisplayGroundArray);  //drawing_Image delete �Ŀ� NULL ����

	
		//pCView->Morphology(pCView->drawing_Image);

		

		//pCView->grass_fire(pCView->drawing_Image);
		//pCView->BlobColoring(pCView->drawing_Image);

		//pCView->draw_orbit(pCView->OneDisplayGroundArray);
		memcpy(pCView->OneDisplayGroundArray,pCView->drawing_Image,sizeof(pCView->OneDisplayGroundArray));
		

	}
	else
	{

		//pCView->Morphology(pCView->drawing_Image);    //��������

		

		//pCView->grass_fire(pCView->drawing_Image);
		pCView->BlobColoring(pCView->drawing_Image);     //grassfire����  ��������
		pCView->draw_draw(pCView->OneDisplayGroundArray);   //�尩����
		pCView->DrumImage(pCView->OneDisplayGroundArray);    //���ֿ���
		pCView->draw_orbit(pCView->OneDisplayGroundArray,lpVHDR);
		
	}



	
	pCView->DisplayDD(0);
	delete [] pCView->drawing_Image;
	pCView->drawing_Image=NULL;

	
	/*if(pCView->drawing_Image!=NULL)
	{
	delete [] pCView->drawing_Image;
	}*/
	return 0L;



}




