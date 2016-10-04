#include <stdio.h>
#include <stdbool.h>



char set[10];
int order;
bool det[10] = { 0 };

void recursive(int depth){
  int i,j;
 
  if (depth == order)
  {
    for ( i=0 ; i<order ; i++ )
      if (det[i])
        printf("%c",set[i]);
      printf("\n");
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


  while (1)
  {
    scanf("%c",&assist);
    scanf("%c",&set[order]);
    if (assist == '}') break;
    if (set[order] == '}') return;
    order++;
  }
  
  recursive(0);

}
