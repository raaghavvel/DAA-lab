#include <stdio.h>

int a[50][50], v[50]={0}, n;

void dfs(int s) {
    int i;
    printf("%d ",s);
    v[s]=1;
    for(i=0;i<n;i++)
        if(a[s][i]==1 && v[i]==0)
            dfs(i);
}

void main() {
    int i,j,s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d",&s);
    dfs(s);
}
