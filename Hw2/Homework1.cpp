#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int matrix[100][100]; 
	
int value(int n, int a, int b, int i,int j, int e[]){
	return matrix[i][j];
}

int main(){
	FILE *fin,*fout;
	string filename;
	int n;
	int e[100*100];
	int i,j,k;
	int a,b; 
	int count = 0;
	int as_i,as_j;
	
	printf("Please input the file name: ");
	cin>>filename;
	fin = fopen (filename.c_str(),"r");
	if (fin == NULL)
	{
		cout<<"\n\""<<filename<<"\" Can not be found";
		return 0;
	} 
	fscanf(fin,"%d",&n);
	for (i = 0; i < n; i++)
		for (j = 0;j < n; j++)
		{
			fscanf(fin,"%d",&matrix[i][j]);	
		}
	fclose(fin);
	cout<<"a:";
	scanf("%d",&a);
	cout<<"b:";
	scanf("%d",&b);
	
	for (i = a-1 ; i>=0 ; i--)
	{
		j = 0; as_i = i;
		while ((as_i < n) && (j < n))
		{
			e[count] = value (n,a,b,as_i,j,e);
			printf("e[%d]=%d		d(%d,%d)\n",count,e[count],as_i,j);
			as_i++;j++;count++;
		}
	}		//lower + diagonal
	
	for (j = 1; j < b ; j++)
	{
		as_j = j; i = 0;
		while ((as_j < n) && (i < n))
		{
			e[count] = value (n,a,b,i,as_j,e);
			printf("e[%d]=%d		d(%d,%d)\n",count,e[count],i,as_j);
			as_j++;i++;count++;
		}
	}		//upper
	

}
