#include <stdio.h>

void main()
{
	//과제 1
	int i, j;
	unsigned char OrgImg[256][256];

	FILE *infile, *outfile;

	//디스크에서 영상데이터 읽기
	errno_t err;
	err = fopen_s(&infile, "Coin.raw", "rb");
	if (err != 0) {
		printf("File open error!!");
		return;
	}
	fread(OrgImg, sizeof(unsigned char), 256 * 256, infile);
	fclose(infile);

	//역상계산을 위한 영상처리
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < 256; j++)
		{
			OrgImg[i][j] = 255 - OrgImg[i][j];
		}
	}

	//하드디스크에 영상데이터 쓰기
	errno_t err_out;
	err_out = fopen_s(&outfile, "Coin_inv.raw", "wb");
	fwrite(OrgImg, sizeof(unsigned char), 256 * 256, outfile);
	fclose(outfile);



	//과제 2
	unsigned char Assign1_OrgImg[256][256];

	for (int i = 0; i < 64; i++) {
		for (int p = 0; p < 256; p++) {
			Assign1_OrgImg[p][i] = 0;
		}

	}
	for (int j = 64; j < 128; j++) {
		for (int p = 0; p < 256; p++) {
			Assign1_OrgImg[p][j] = 64;
		}
	}
	for (int k = 128; k < 192; k++) {
		for (int p = 0; p < 256; p++) {
			Assign1_OrgImg[p][k] = 192;
		}
	}

	for (int q = 192; q < 256; q++) {
		for (int p = 0; p < 256; p++) {
			Assign1_OrgImg[p][q] = 255;
		}
	}

	FILE *assign1_outfile = fopen("sample image.raw", "wb");
	fwrite(Assign1_OrgImg, sizeof(unsigned char), 256 * 256, assign1_outfile);
	fclose(assign1_outfile);



	//과제 3
	unsigned char Assign2_OrgImg_R[256][256];
	unsigned char Assign2_OrgImg_G[256][256];
	unsigned char Assign2_OrgImg_B[256][256];
	//black=255,255,255  red=255,0,0  green=0,255,0  blue=0,0,255

	for (int i = 0; i < 64; i++) {
		for (int p = 0; p < 256; p++) {
			Assign2_OrgImg_R[p][i] = 255;
			Assign2_OrgImg_G[p][i] = 0;
			Assign2_OrgImg_B[p][i] = 0;
		}

	}


	for (int j = 64; j < 128; j++) {
		for (int p = 0; p < 256; p++) {
			Assign2_OrgImg_R[p][j] = 0;
			Assign2_OrgImg_G[p][j] = 255;
			Assign2_OrgImg_B[p][j] = 0;
		}
	}


	for (int k = 128; k < 192; k++) {
		for (int p = 0; p < 256; p++) {
			Assign2_OrgImg_R[p][k] = 0;
			Assign2_OrgImg_G[p][k] = 0;
			Assign2_OrgImg_B[p][k] = 255;
		}
	}


	for (int q = 192; q < 256; q++) {
		for (int p = 0; p < 256; p++) {
			Assign2_OrgImg_R[p][q] = 0;
			Assign2_OrgImg_G[p][q] = 0;
			Assign2_OrgImg_B[p][q] = 0;
		}
	}

	FILE *assign2_outfile = fopen("sample color image.raw", "wb");
	fwrite(Assign2_OrgImg_R, sizeof(unsigned char), 256 * 256, assign2_outfile);
	fwrite(Assign2_OrgImg_G, sizeof(unsigned char), 256 * 256, assign2_outfile);
	fwrite(Assign2_OrgImg_B, sizeof(unsigned char), 256 * 256, assign2_outfile);
	fclose(assign2_outfile);
}
