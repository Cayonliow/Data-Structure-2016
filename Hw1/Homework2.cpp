/*F74045034*/
/*Lao Chon Lam*/
/*Assignment1 - Hw2*/

#include <iostream> 
#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <cmath>
using namespace std;

char set[10]; 
int order; // The num of elements
bool det[10] = { 0 };  //Turth Table
string output[500];
int count;

void recursive(int depth){
  int i,j;
 
  if (depth == order) //terminal condition
  {
    for ( i=0 ; i<order ; i++ )
      if (det[i])    
        output[count] = output[count] + set[i]; //store the string for the later output
      count++; //counter 
      return;
  }

  det[depth] = false ;
  recursive(depth+1);

  det[depth] = true ;
  recursive(depth+1);



}


int main(){
  char assist;
  int i;
  order = 0;
  count = 0;

  while (1)
  {	/*read as char*/ 
    scanf("%c",&assist);
    scanf("%c",&set[order]);
    if (assist == '}') break;
    if (set[order] == '}') return 0 ;
    order++;
  }
  
  recursive(0); // Start

	cout<<"{}"<<endl;


	/*Output in order*/
	for (int k = 1; k<=order;k++)
	{
		for (int j = pow(2,order)-1;j >=0 ;j--)
		{
			if (output[j].length()==k)
			{ /*Output as the form required*/
				cout<<"{";
				for (int g = 0; g < output[j].length(); g++)
				{
					cout<<output[j][g];
					if ( g != output[j].length()-1 ) 
						cout<<",";
				}
				cout<<"}";
				cout<<endl;
			}
		}	
	}	
	int out = pow(2,order); // Total count
	printf("Powerset裡總共有%d個集合",out);
}
