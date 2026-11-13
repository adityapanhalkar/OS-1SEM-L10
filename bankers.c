#include <stdio.h>

int main(void) {
    int n, m, i, j, count=0, found;
    int a[10][10], mx[10][10], need[10][10];
    int avail[10], work[10], finish[10]={0}, safe[10];

    printf("Enter processes and resources: ");
    scanf("%d%d",&n,&m);

    if (n<1 || n>10 || m<1 || m>10) return 1;

    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    printf("Enter maximum matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) {
            scanf("%d",&mx[i][j]);
            need[i][j]=mx[i][j]-a[i][j];
        }

    printf("Enter available resources:\n");
    for(j=0;j<m;j++) {
        scanf("%d",&avail[j]);
        work[j]=avail[j];
    }

    while(count<n) {
        found=0;
        for(i=0;i<n;i++) if(!finish[i]) {
            for(j=0;j<m;j++)
                if(need[i][j]>work[j]) break;

            if(j==m) {
                for(j=0;j<m;j++)
                    work[j]+=a[i][j];

                safe[count++]=i;
                finish[i]=1;
                found=1;
            }
        }
        if(!found) break;
    }

    if(count==n) {
        printf("Safe state\nSafe sequence: ");
        for(i=0;i<n;i++) printf("P%d ",safe[i]);
        printf("\n");
    } else {
        printf("Unsafe state\n");
    }

    return 0;
}
