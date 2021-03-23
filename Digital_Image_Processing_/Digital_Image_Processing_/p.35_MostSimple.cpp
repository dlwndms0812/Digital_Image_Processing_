#include <stdio.h>

void main()
{
	int i, j;
	unsigned char OrgImg[256][256];

	//디스크에서 영상데이터 읽기
	FILE *infile = fopen("Coin.raw", "rb");
	if (infile == NULL) { printf("File open error!!"); return; }
	fread(OrgImg, sizeof(char), 256 * 256, infile);
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
	FILE *outfile = fopen("Coin_inv.raw", "wb");
	fwrite(OrgImg, sizeof(char), 256 * 256, outfile);
	fclose(outfile);
}

//6행: 영상파일을 저장하기 위한 이차원 배열을 선언함. 
//     이 파일의 크기는 가로가 256픽셀, 세로가 256픽셀로 크기가 정해진 흑백영상파일임을 나타냄. 
//     "unsigned char"는 부호 없는 문자형으로 0~255사이의 값을 저장할 수 있음.
//9행: 영상데이트러르 읽기 위해 파일을 오픈한다. 읽을 파일의 이름은 "coin.raw"파일.
//      "rb"는 read와 byte를 뜻함
//10행: 오픈명령이 수행된 후, infile에 NULL이 넘어오면 파일을 오픈하는데 오류가 발생한 경우이거나 
//      현재 실행 디렉토리 위치에 coin.raw파일이 없는 경우이므로 프로그램을 종료함.
//11행: 오픈된 영상파일을 읽는 부분.
//12행: 파일을 읽은 후 오픈했던 "coin.raw"파일을 닫아줌.
//15행: 입력된 영상의 역상을 계산하는 부분임.
//24행: 계산된 영상파일을 다시 디스크에 쓰기 위해 출력할 파일을 열어주는 부분.
//      출력할 영상파일의 이름은 "coin_inv.raw"파일임. "wb"는 write와 byte를 뜻함.
//25행: 영상파일을 하드디스크에 기록하는 부분.
//26행: 기록이 끝났으면 열었던 파일을 다시 닫아줌.


