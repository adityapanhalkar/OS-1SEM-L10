#include <stdio.h>

int main(void) {
    int total,n,p[20],i,part,internal=0,used=0;

    printf("Enter total memory: ");
    scanf("%d",&total);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    if(n<1 || n>20 || total<1) return 1;

    printf("Enter memory required by each process:\n");
    for(i=0;i<n;i++) scanf("%d",&p[i]);

    part=total/n;

    printf("\nMFT (partition size %d):\n",part);

    for(i=0;i<n;i++) {
        if(p[i]<=part) {
            printf("P%d allocated; internal waste=%d\n",i+1,part-p[i]);
            internal+=part-p[i];
        } else {
            printf("P%d not allocated\n",i+1);
        }
    }

    printf("Internal fragmentation: %d\n",internal);

    printf("\nMVT:\n");

    for(i=0;i<n;i++) {
        if(p[i]<=total-used) {
            used+=p[i];
            printf("P%d allocated %d\n",i+1,p[i]);
        } else {
            printf("P%d not allocated\n",i+1);
        }
    }

    printf("Remaining memory: %d\n",total-used);

    return 0;
}
