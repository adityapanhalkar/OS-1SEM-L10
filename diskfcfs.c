#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n,head,req[20],i,seek=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    if(n<1 || n>20) return 1;

    printf("Enter request sequence:\n");
    for(i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Seek sequence: %d",head);

    for(i=0;i<n;i++) {
        seek+=abs(head-req[i]);
        head=req[i];
        printf(" -> %d",head);
    }

    printf("\nTotal head movement: %d\n",seek);

    return 0;
}
