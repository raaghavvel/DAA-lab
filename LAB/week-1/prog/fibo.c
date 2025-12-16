#include <stdio.h>

int main(){
  int n;
  printf("Enter number:");
  scanf("%d",&n);
  int f0=0,f1=1;
  printf("\n%d %d ",f0,f1);
  for(int i=1;i<n+1;i++){
    int temp=f1;
    f1=f0+f1;
    f0=temp;
    printf("%d ",f1);
  } 
  return 0;
}
