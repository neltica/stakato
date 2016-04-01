
#include <Windows.h>

class bitmapoutput
{
private:


	int m_Width;
	int m_Height;


	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;

	BYTE *lpImg;

public:
	bitmapoutput();
	~bitmapoutput();

	void SetPixel(BYTE *lpImg, int i, int j, BYTE r, BYTE g, BYTE b);
	void Raw2BMP(BYTE *lpImg);
	void MakeBMPFile(char *FileName, BYTE *OutImage);



	void output(BYTE *pImage);
protected:
};