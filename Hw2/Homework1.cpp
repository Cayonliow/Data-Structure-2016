#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void value(int n, int a, int b, int i,int j, int e);

int main(){
	FILE *fin,*fout;
	string filename;
	int n;
	int matrix[100][100]; 
	int e[100*100];
	int i,j,k; 
	
	printf("Please input the file name: ");
	cin>>filename;
	fin = fopen (filename.c_str(),"r");
	fscanf(fin,"%d",&n);
	for (i = 0; i < n; i++)
		for (j = 0;j < n; j++)
		{
			fscanf(fin,"%d",&matrix[i][j]);	
		}
	fclose(fin);
}
