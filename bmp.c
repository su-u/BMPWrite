#include <stdio.h>

#define SIZE 100

//File header
typedef struct FILEHEADER
{
	unsigned short	type;			//�t�@�C���^�C�v
	unsigned long	size;			//�t�@�C���T�C�Y
	unsigned short	reserved1;		//�\��̈�1
	unsigned short	reserved2;		//�\��̈�2
	unsigned long	OffBits;		//�t�@�C���擪����摜�f�[�^�܂ł̃I�t�Z�b�g
} fileheader;

//bmp Information header
typedef struct BMPHEADER
{
	unsigned long	size;			//���w�b�_�T�C�Y
	long		width;				//�摜�̕�
	long		height;				//�摜�̍���
	unsigned short	planes;			//�v���[����
	unsigned short	bitCount;		//�F�r�b�g��
	unsigned long	compression;	//���k�`��
	unsigned long	sizeImage;		//�摜�f�[�^�T�C�Y
	long		XPixPerMeter;		//�����𑜓x
	long		YPixPerMeter;		//�����𑜓x
	unsigned long	clrUsed;		//�i�[�p���b�g��
	unsigned long	clrImportant;	//�d�v�F��
} infoheader;


int	main(void) {
	fileheader file_header;
	infoheader info_header;
	MANDELBLOT c;
	char file_name[80] = { 0 };
	int width, height, i, j;
	unsigned char r_img[SIZE][SIZE];
	unsigned char g_img[SIZE][SIZE];
	unsigned char b_img[SIZE][SIZE];

	width = SIIZE;
	height = SIZE;

	//File Header
	file_header.type = 0x4d42;
	file_header.size = width * height * 3 + 54;
	file_header.reserved1 = 0;
	file_header.reserved2 = 0;
	file_header.OffBits = 54;

	//Information Header
	info_header.size = 40;
	info_header.width = width;
	info_header.height = height;
	info_header.planes = 1;
	info_header.bitCount = 24;
	info_header.compression = 0;
	info_header.sizeImage = 0;
	info_header.XPixPerMeter = 3780;
	info_header.YPixPerMeter = 3780;
	info_header.clrUsed = 0;
	info_header.clrImportant = 0;

	//write
	FILE	*fp;
	strcpy_s(file_name, "./bmp.bmp");

	/*fp = */fopen_s(&fp,file_name, "wb");

	//�w�b�_�[
	fwrite(&file_header.type, sizeof(file_header.type), 1, fp);
	fwrite(&file_header.size, sizeof(file_header.size), 1, fp);
	fwrite(&file_header.reserved1, sizeof(file_header.reserved1), 1, fp);
	fwrite(&file_header.reserved2, sizeof(file_header.reserved2), 1, fp);
	fwrite(&file_header.OffBits, sizeof(file_header.OffBits), 1, fp);

	//�w�b�_�[
	fwrite(&info_header.size, sizeof(info_header.size), 1, fp);
	fwrite(&info_header.width, sizeof(info_header.width), 1, fp);
	fwrite(&info_header.height, sizeof(info_header.height), 1, fp);
	fwrite(&info_header.planes, sizeof(info_header.planes), 1, fp);
	fwrite(&info_header.bitCount, sizeof(info_header.bitCount), 1, fp);
	fwrite(&info_header.compression, sizeof(info_header.compression), 1, fp);
	fwrite(&info_header.sizeImage, sizeof(info_header.sizeImage), 1, fp);
	fwrite(&info_header.XPixPerMeter, sizeof(info_header.XPixPerMeter), 1, fp);
	fwrite(&info_header.YPixPerMeter, sizeof(info_header.YPixPerMeter), 1, fp);
	fwrite(&info_header.clrUsed, sizeof(info_header.clrUsed), 1, fp);
	fwrite(&info_header.clrImportant, sizeof(info_header.clrImportant), 1, fp);

	for (j = 0; j <height; j++) {
		for (i = 0; i < width; i++) {
			fwrite(&b_img[i][j], 1, 1, fp);
			fwrite(&g_img[i][j], 1, 1, fp);
			fwrite(&r_img[i][j], 1, 1, fp);
		}
	}
	
	fclose(fp);

	return 0;
}
