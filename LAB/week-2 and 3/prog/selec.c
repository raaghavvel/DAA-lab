#include <stdio.h>

void main() {
    int a[50], n, i, j, min, t;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
}
