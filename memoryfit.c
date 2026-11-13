#include <stdio.h>

void allocate(int b[],int nb,int p[],int np,int type) {
    int rem[20],i,j,k;

    for(i=0;i<nb;i++)
        rem[i]=b[i];

    for(i=0;i<np;i++) {
        k=-1;

        for(j=0;j<nb;j++) if(rem[j]>=p[i]) {
            if(type==0) {
                k=j;
                break;
            }

            if(k==-1 || (type==1 && rem[j]<rem[k]) ||
                         (type==2 && rem[j]>rem[k]))
                k=j;
        }

        if(k==-1)
            printf("P%d not allocated\n",i+1);
        else {
            printf("P%d -> Block %d\n",i+1,k+1);
            rem[k]-=p[i];
        }
    }
}

int main(void) {
    int b[20],p[20],nb,np,i;

    printf("Enter number of blocks: ");
    scanf("%d",&nb);

    printf("Enter block sizes:\n");
    for(i=0;i<nb;i++)
        scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    printf("Enter process sizes:\n");
    for(i=0;i<np;i++)
        scanf("%d",&p[i]);

    printf("\nFirst Fit:\n");
    allocate(b,nb,p,np,0);

    printf("\nBest Fit:\n");
    allocate(b,nb,p,np,1);

    printf("\nWorst Fit:\n");
    allocate(b,nb,p,np,2);

    return 0;
}
