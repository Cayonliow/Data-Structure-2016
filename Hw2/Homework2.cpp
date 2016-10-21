#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
	
FILE *fout;
int const imove[8] = {-1,0,1,1,1,0,-1,-1};
int const jmove[8] = {1,1,1,0,-1,-1,-1,0};

void printerror(){
	fprintf(fout,"Out of Range!");
}


typedef struct coor {
	int x;
	int y;
};

int main(){
	
	srand(time(NULL)); 
	coor cur_pos;
	int n,m;
	int tiles[40][20] = {0};
	int counter;  // exit when counter = n*m;
	int step ;
	int k;
	fout = fopen ("Output.txt","w+t");
		
	printf("N: ");
	scanf("%d",&n);
	if (n<=2 || n > 40)
	{
		printerror();
		return 0;
	}
	
	printf("M: ");
	scanf("%d",&m);
	if (m<=2 || m > 20)
	{
		printerror();
		return 0;
	}
	
	printf("Initial bug position X: ");
	scanf("%d",&cur_pos.x);
	if (cur_pos.x < 0 || cur_pos.x >= n)
	{
		printerror();
		return 0;
	}
	
	printf("Initial bug position Y: ");
	scanf("%d",&cur_pos.y);
	if (cur_pos.y < 0 || cur_pos.y >= m)
	{
		printerror(); 
		return 0;
	}
	
	tiles[cur_pos.x][cur_pos.y] = 1;
	counter = 1;
	step = 0 ;
	
	 

	while(counter != n*m)
	{
		k = rand() % 8 ; //random!
		if ( ((cur_pos.x + imove[k]) < n) && ((cur_pos.x + imove[k]) >= 0))		
			if ( ((cur_pos.y + jmove[k]) < m) && ((cur_pos.y + jmove[k]) >= 0))  //conditions
				{
					cur_pos.x = cur_pos.x + imove[k];
					cur_pos.y = cur_pos.y + jmove[k];

					if (tiles[cur_pos.x][cur_pos.y] == 0)
						counter++;
					step++;
					if (step == 50000)
					{
						fprintf(fout,"reached the maximum steps 50000.");
						return 0;
					}
					tiles[cur_pos.x][cur_pos.y]++;
				}	
				
				
	}
	 
	fprintf(fout,"\nTotal Steps : \n%d\n\n",step);
	fprintf(fout,"Count Array : \n");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m ; j++)
			fprintf(fout,"%3d",tiles[i][j]);
		fprintf(fout,"\n");
	}
	
	fclose(fout);
	
}
