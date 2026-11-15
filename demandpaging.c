#include <stdio.h>

int main(void) {
    int p[20],frame[10],n,f,i,j,k=0,faults=0,found;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page reference string:\n");
    for(i=0;i<n;i++) scanf("%d",&p[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    if(n<1 || n>20 || f<1 || f>10) return 1;

    for(i=0;i<f;i++) frame[i]=-1;

    for(i=0;i<n;i++) {
        found=0;

        for(j=0;j<f;j++)
            if(frame[j]==p[i]) found=1;

        if(!found) {
            frame[k]=p[i];
            k=(k+1)%f;
            faults++;

            printf("Page fault: %d\n",p[i]);
        }
    }

    printf("Total page faults: %d\n",faults);

    return 0;
}
