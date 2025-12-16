#include <stdio.h>

int main(){
  int n;
  printf("Enter number:");
  scanf("%d",&n);
  int sum=0;
  for(int i=1;i<n+1;i++){
    sum=sum+i*i*i;
  } 
  printf("sum is %d\n",sum);
  return 0;
}
