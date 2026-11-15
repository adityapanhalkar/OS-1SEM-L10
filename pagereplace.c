#include <stdio.h>

int main(void) {
    int p[20],f[10],n,nf,i,j,alg,faults,found,pos,stamp[10],t;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page reference string:\n");
    for(i=0;i<n;i++) scanf("%d",&p[i]);

    printf("Enter number of frames: ");
    scanf("%d",&nf);

    if(n<1 || n>20 || nf<1 || nf>10) return 1;

    for(alg=0;alg<2;alg++) {
        for(i=0;i<nf;i++) {
            f[i]=-1;
            stamp[i]=0;
        }

        faults=0;
        t=0;

        printf("\n%s:\n",alg==0?"FIFO":"LRU");

        for(i=0;i<n;i++) {
            found=0;

            for(j=0;j<nf;j++) if(f[j]==p[i]) {
                found=1;
                if(alg==1) stamp[j]=++t;
                break;
            }

            if(!found) {
                pos=-1;

                for(j=0;j<nf;j++)
                    if(f[j]==-1) {
                        pos=j;
                        break;
                    }

                if(pos==-1) {
                    pos=0;
                    for(j=1;j<nf;j++)
                        if(stamp[j]<stamp[pos]) pos=j;
                }

                f[pos]=p[i];
                stamp[pos]=++t;
                faults++;
            }

            printf("%d: ",p[i]);

            for(j=0;j<nf;j++)
                if(f[j]==-1) printf("- ");
                else printf("%d ",f[j]);

            printf("\n");
        }

        printf("Total page faults: %d\n",faults);
    }

    return 0;
}
