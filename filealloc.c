#include <stdio.h>

int main(void) {
    int start,n,i;

    printf("Enter starting block and file size: ");
    scanf("%d%d",&start,&n);

    if(n<1) return 1;

    printf("\nSequential (contiguous) allocation:\n");
    for(i=0;i<n;i++)
        printf("%d ",start+i);

    printf("\n\nIndexed allocation:\nIndex block: %d\nData blocks: ",start);

    for(i=0;i<n;i++)
        printf("%d ",start+i+1);

    printf("\n\nLinked allocation:\n");

    for(i=0;i<n;i++) {
        if(i<n-1)
            printf("%d -> ",start+i);
        else
            printf("%d -> NULL\n",start+i);
    }

    return 0;
}
