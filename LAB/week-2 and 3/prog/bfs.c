#include <stdio.h>

void main() {
    int n,i,j,s,q[50],f=0,r=0;
    int a[50][50],v[50]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d",&s);
    q[r++]=s;
    v[s]=1;
    while(f<r) {
        s=q[f++];
        printf("%d ",s);
        for(i=0;i<n;i++)
            if(a[s][i]==1 && v[i]==0) {
                q[r++]=i;
                v[i]=1;
            }
    }
}
