// 28
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>

#define stop system("pause")
#define SCREENW 79
#define SCREENH 25



using namespace std;

int a[30];
int b[5][4];
int d[10][10];
int s;

void nop(void){}

void sort(int (&d)[10])
{
	for (int x = 9; x > 0; x--) 
		for (int y = 0; y < x ; y++) 
			d[y] < d[y + 1] ? s = d[y], d[y] = d[y + 1], d[y + 1] = s : s = s;
}


int main(void) {
	srand(time(0));
	setlocale(LC_ALL, "");
	s = 0;


	/*z28
	

	for (int i = 0; i < 30; i++) {
		a[i] = 500+rand()%501;
	}
	uint32_t s = 0;
	for (int i = 0; i < 30; i++, s += a[i]);


	for (int i = 0; i < 30; i++) {
		cout<< a[i]<<"\n";
	}
	cout << "\n S= " << s<<"\n\n";

	*/

	/* z2*/

/*
	int **b = new int*[4];
	for (int i = 0; i < 4; i++)
	{
	b[i] = new int[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = rand()%60;
			cout << b[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n\n\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <3; j++) {
			b[i][j] = pow(b[i][j],2);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout<<b[i][j] <<"\t";
		}
		cout << "\n";
	}*/
	/*
	/*z12*/
/*
	int **c = new int*[5];
	for (int i = 0; i < 5; i++) 
	{
		c[i] = new int[5];  
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			c[i][j] = rand() % 60;
			cout << c[i][j] << "\t";
		}
		cout << "\n";
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < i; j++, s += c[i][j]);


			cout << "\n S= " << s << "\n\n";
	*/
//z45
	for (int i = 0; i < 10; i++, cout << "\n")
		for (int j = 0; j < 10; d[i][j] = rand() % 60, cout << d[i][j++] << "\t");

	cout << "\n\n"; 

	for (int i = 0; i < 10; sort(d[i++]));// sorting arrays

	for (int i = 0; i < 10; i++, cout << "\n")
		for (int j = 0; j < 10; cout << d[i][j++] << "\t");

	cout << "\n\n"; 

	stop;
	return(0);
}