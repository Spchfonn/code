#include<stdio.h>
int arr[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        int check = arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(check<arr[j]){
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = check;
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }

    return 0;
}