#include <stdio.h>

int fac(int a){
  if(a==1){
    return 1;
  }
  else{
    return a*fac(a-1);
  }
}

int main(){
  int n;
  printf("Enter number:");
  scanf("%d",&n); 
  printf("factorial is %d\n",fac(n));
  return 0;
}
