#include<stdio.h>
#include<fstream>
#include<string.h>
int main() {

	/*
		FILEを使用して読み書きを行う
			FILEはファイルの位置情報を保存しておく
	*/
	FILE* fp = nullptr;
	

	/*
			fopen_s
		第一引数：
			FILEポインタのアドレス

			第二引数
			ファイル名(パス読み込み)

			第三引数
			アクセスモード

			a=>追記モード
			w=>書き込みモード
			r=>読み込みモード
			b=>バイナリモード

			例：
			wb=>バイナリ書き込みモード
	*/

	fopen_s(&fp,"ファイル名.txt","w");
	if (fp == nullptr){
		printf("オープン失敗\n");
		return -1;
	}

	/*
		第一引数：
			書き込む内容

		第二引数：
			書き込み量

		第三引数：
			書き込み回数

		第四引数：
			ファイルポインタ

			strlen=>string.hを追加
	*/
	fwrite("あいうえおかきくけこさしすせそ",strlen("ああああいああああいああああい"),1,fp);

	fclose(fp);

	fopen_s(&fp, "ファイル名.txt", "r");
	if (fp == nullptr)
	{
		printf("ファイル名オープンに失敗\n");
		return -1;
	}

	/*
	読み込みで必要なもの
		読み込んだデータを保存するための入れ物
	*/
	char buffer[1024] = {};

	/*
		feof
			FILEがファイルの末端に到達していたら非０がかえる
	*/
	while (feof(fp) == 0)
	{
		/*
			第一引数：
				読み込んだデータの保存先

			第二引数：
				保存先のサイズ

			第三引数：
				読み込み量

			第四引数：
				読み込み回数

			第五引数：
				ファイルポインタ

		*/
		//fread_s(buffer, 1024, 10, 1, fp);

		fgets(buffer,11,fp);

		printf("%s\n", buffer);
	}

	fclose(fp);
	

	   	 
	while (fgets(buffer,1024,fp))
	{
		char* p = buffer;
		int map[10][10];
		int column = 0;
		int row = 0;


			
			while (true)
			{
				map[row][column] = atoi(p);

				p = strchr(p,'.');

				if (p == nullptr);
				{
					break;
				}
				p++;
				column++;
			}
		row++;
	}

	return 0;
}