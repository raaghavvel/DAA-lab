#include <stdio.h>

int main(){
  int n[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  int transpo[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      transpo[i][j]=n[j][i];
      printf("%d",transpo[i][j]);
    }
    printf("\n");
  }
  
}
