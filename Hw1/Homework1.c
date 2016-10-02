
#include <stdio.h>

long long int recursive(long long int n){
	
	if (n<=1) return n;
	 return n*recursive(n-1);
	
}


int main(){
	
  printf("Please enter a number bigger than 0. enter '-1' to end program.\n");
	
  long long int n;
  long long int ans;
  long long int p;

  while (1)
  {
    
    scanf("%lld",&n);
    p = n ;
    if (n == -1) return 0;
    
    /*iterative*/
    ans = 1;
    while (n>1)
    {
      ans = ans * n ;
      n--;
    }
    n = p;

    printf("iterative : %lld\n",ans);

    /*recursive*/
	  ans = recursive (n) ;
	  printf("recursive : %lld\n",ans);
	 
  }
}
