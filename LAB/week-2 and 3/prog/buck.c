#include <stdio.h>

void main() {
    int a[50], bucket[50]={0}, n, i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        bucket[a[i]]++;
    }
    for(i=0;i<50;i++)
        while(bucket[i]--)
            printf("%d ",i);
}
