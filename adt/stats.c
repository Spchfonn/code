#include <stdio.h>
#include <stdlib.h>
void findStats(int *a,int n,double *avg,int *maxi,int *mini) {
    int total=0,mx=-999999999,mn=999999999;
    for (int i=0; i<n; i++){
        total+=*(a+i);
        if(*(a+i)>=mx) mx=*(a+i);
        if(*(a+i)<=mn) mn=*(a+i);
    }
    *avg=total/(double)n;
    *maxi=mx;
    *mini=mn;
}
int main() {
    int n, i, maxi, mini;
    double avg;
    int *nums;
    scanf("%d", &n);
    nums = (int *)malloc(sizeof (int) *n);
    for (i=0; i<n; i++)
        scanf("%d", nums+i);
    findStats(nums,n,&avg,&maxi,&mini);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}