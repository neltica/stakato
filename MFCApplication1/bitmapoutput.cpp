#include "stdafx.h"
#include "bitmapoutput.h"
#include <stdio.h>
bitmapoutput::bitmapoutput()
{
	m_Width = 320;
	m_Height = 240;

	BYTE *lpImg = new BYTE[m_Width * m_Height*3];
	memset(lpImg, 255, m_Width*m_Height*3);

}

bitmapoutput::~bitmapoutput()
{

}


void bitmapoutput::SetPixel (BYTE *lpImg, int i, int j, BYTE r, BYTE g, BYTE b)//lpImp,10,100,123,200,40
{
	*(lpImg+m_Width*3*i+j*3+0)=r; //red
	*(lpImg+m_Width*3*i+j*3+1)=g; //green
	*(lpImg+m_Width*3*i+j*3+2)=b; //blue
}


void bitmapoutput::Raw2BMP (BYTE *lpImg)
{
	int i;
	BYTE *TmpBuf = new BYTE[m_Width*m_Height*3];

	BYTE tempimg[3];
	//rgb 를 bgr로 변경
	for(int i = 0 ; i < m_Height; i++) {
		for(int j=0 ; j < m_Width; j++)    {
			*(TmpBuf+m_Width*3*i+j*3+2) = *(lpImg+m_Width*3*i+j*3+0); 
			*(TmpBuf+m_Width*3*i+j*3+1) = *(lpImg+m_Width*3*i+j*3+1);
			*(TmpBuf+m_Width*3*i+j*3+0) = *(lpImg+m_Width*3*i+j*3+2); 
		}
	}
	//위아래 변경

	//for(i = 0 ; i < m_Height ; i++) {
	//	for(int j = 0 ; j < m_Width ; j++) {
	//		//요부분이 문제임..
	//		*(lpImg+i*j*0) = *(TmpBuf+(m_Height-i)*j*0);
	//		*(lpImg+i*j*1) = *(TmpBuf+(m_Height-i)*j*1);
	//		*(lpImg+i*j*2) = *(TmpBuf+(m_Height-i)*j*2);
	//		
	//	}
	//}

	for(int i=0;i<m_Height;i++)
	{
		for(int j=0;j<m_Width;j++)
		{
			*(lpImg+m_Width*3*i+j*3+0)=*(TmpBuf+m_Width*3*(240-i)+(j)*3+0);
			*(lpImg+m_Width*3*i+j*3+1)=*(TmpBuf+m_Width*3*(240-i)+(j)*3+1);
			*(lpImg+m_Width*3*i+j*3+2)=*(TmpBuf+m_Width*3*(240-i)+(j)*3+2);
		}
	}


	delete []TmpBuf;
}

void bitmapoutput::MakeBMPFile(char *FileName, BYTE *OutImage)
{
	FILE *OutFile;
	OutFile = fopen(FileName, "wb");

	fwrite(&hf,sizeof(char), sizeof(BITMAPFILEHEADER), OutFile);
	fwrite(&hInfo, sizeof(char), sizeof(BITMAPINFOHEADER), OutFile);
	fwrite(OutImage, m_Width * m_Height * 3, 1, OutFile);

	fclose(OutFile);
}


void bitmapoutput::output(BYTE *pImage)
{
	m_Width = 320;
	m_Height = 240;

	lpImg = new BYTE[m_Width * m_Height*3];
	memset(lpImg, 255, m_Width*m_Height*3);
	// pixel drawing in(i,j)=>(r,g,b)
	lpImg=pImage;
	int i=10;
	int j=100;
	BYTE r=123;
	BYTE g=200;
	BYTE b=40;

	SetPixel(lpImg, i, j, r, g, b);    //lpImp,10,100,123,200,40

	Raw2BMP (lpImg);
	// save to bmp
	// BMP header
	hInfo.biSize=40;  //0
	hInfo.biWidth=m_Width;  //0
	hInfo.biHeight=m_Height;  //0
	hInfo.biPlanes=1;  //0
	hInfo.biBitCount=24;  //0
	hInfo.biCompression=0;  //0
	hInfo.biSizeImage=m_Width*m_Height*3;  // 16bit = *2, 24bit = *3, 32bit = *4
	hInfo.biXPelsPerMeter=0;  //0
	hInfo.biYPelsPerMeter=0;  //0
	hInfo.biClrUsed=0;
	hInfo.biClrImportant=0;

	hf.bfType=19778;
	hf.bfOffBits=54;
	hf.bfReserved1=0;
	hf.bfReserved2=0;
	hf.bfSize=hInfo.biSizeImage+hf.bfOffBits;

	MakeBMPFile ("test.bmp",lpImg);
	//delete [] lpImg;
}