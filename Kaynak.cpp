/*******************************************************************************************
**                         ÖÐRENCÝ ADI: AYÞEGÜL ÖZSOY
**                         ÖÐRENCÝ NUMARASI:B191210098
**                         GRUBU:1C GRUBU/1.ÖÐRETÝM
********************************************************************************************/



#include<iostream>
#include<iomanip>
#include<windows.h>
#include<time.h>
using namespace std;
struct Sahne
{
	int genislik;
	int yukseklik;
};
struct Lsekli
{
	int x;
	int y;
	int boyut;
	char Lkarakter;
};
void koordinatAta(int x, int y);
Sahne sahneyap();
Lsekli lsekliyap();
void lSekliCiz(Lsekli h2);
Lsekli lSekliAsagiindir(Lsekli l);
int main()
{
	srand(time(0));
	Lsekli l1;
	l1 = lsekliyap();
	Sahne s1;
	s1 = sahneyap();
	while (1)
	{
		system("cls");
		lSekliCiz(l1);
		l1 = lSekliAsagiindir(l1);
		if (l1.y + l1.boyut * 2 == s1.yukseklik - 1)
		{
			l1 = lsekliyap();
		}
		Sleep(100);
	}
}
void koordinatsec(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
Sahne sahneyap()
{
	Sahne h1;
	int m;
	int n;
	char karakterler[] = { '+','*','@','$','#' };
	m = rand() % 5;
	karakterler[m];
	int degerler[] = { 30,40,50 };
	n = rand() % 3;
	degerler[n];
	h1.genislik = degerler[n];
	h1.yukseklik = rand() % 11 + 20;
	for (int i = 0; i < h1.genislik; i++)
	{
		cout << karakterler[m];
		Sleep(100);
	}
	for (int i = 0; i < h1.yukseklik; i++)
	{
		koordinatsec(h1.genislik - 1, i);
		cout << karakterler[m];
		Sleep(100);
	}
	for (int i = 0; i < h1.genislik; i++)
	{
		koordinatsec(h1.genislik - 1 - i, h1.yukseklik);
		cout << karakterler[m];
		Sleep(100);
	}
	for (int i = 0; i < h1.yukseklik; i++)
	{
		koordinatsec(0, h1.yukseklik - 1 - i);
		cout << karakterler[m];
		Sleep(100);
	}
	for (int i = 0; i < h1.yukseklik + 3; i++)
		cout << endl;
	return h1;
}
Lsekli lsekliyap()
{
	Lsekli h2;
	h2.x = rand() % 21 + 5;
	h2.y = 3;
	h2.boyut = rand() % 6 + 2;
	char  ldizi[] = "*#$+@";
	int lrastgele = rand() % 5;
	h2.Lkarakter = ldizi[lrastgele];
	return h2;
}
void lSekliCiz(Lsekli h2)
{
	for (int i = 0; i < h2.boyut; i++)
	{
		// l seklinin yukarý yatayda olusturdum
		koordinatsec(h2.x + i, h2.y);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < (h2.boyut * 2) + 1; i++)
	{
		//l seklinin  sekilin butun boyu olusturdum
		koordinatsec(h2.x, h2.y + i);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < (h2.boyut) * 2 + 1; i++)
	{
		// l seklinin asagi yatay olusturdum
		koordinatsec(h2.x + i, h2.y + h2.boyut * 2);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < h2.boyut + 1; i++)
	{
		// l seklinin yükseklik kýsmý olusturdum
		koordinatsec(h2.x + h2.boyut - 1, h2.y + i);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < h2.boyut + 1; i++)
	{
		// l seklinin orta yatay kýsmýný olusturdum
		koordinatsec(h2.x + h2.boyut - 1 + i, h2.y + h2.boyut);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < h2.boyut + 1; i++)
	{
		// l seklinin asagý yuksekligi kýsmý olusturdum
		koordinatsec(h2.x + (h2.boyut) * 2 - 1, h2.y + h2.boyut + i);
		cout << h2.Lkarakter;
	}
}
Lsekli lSekliAsagiindir(Lsekli l)
{
	l.y++;
}