#include<stdio.h>
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    int arr[n][n];
    if(p==1){
        for(int i=1;i<=n;i++){
            for(int j=i;j<n*(n-1)+i+1;j+=n){
                printf("%d ",j);
            }
            printf("\n");
        }
    }
    else if(p==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j%2==0) printf("%d ",n*j-i+1);
                else printf("%d ",n*(j-1)+i);
            }
            printf("\n");
        }
    }
    else if(p==3){
        int x=1;
        for(int k=1;k<=n;k++){
            if(k%2==0){
                for(int i=n-k+1,j=1;i<=n,j<=k;i++,j++){
                    arr[i-1][j-1]=x++;
                }
            }
            else{
                for(int i=n,j=k;i>=n-k+1,j>=1;i--,j--){
                    arr[i-1][j-1]=x++;
                }
            }
        }
        for(int k=1;k<n;k++){
            if((k%2==0 && n%2==1) || (k%2==1 && n%2==0)){
                for(int i=n-k,j=n;i>=1,j>=k+1;i--,j--){
                    arr[i-1][j-1]=x++;                    
                }
            }
            else{
                for(int i=1,j=1+k;i<=n-k,j<=n;i++,j++){
                    arr[i-1][j-1]=x++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    else if(p==4){
        int i=0,j=0,x=1;
        for(int k=1;k<=n/2+1;k++){
            for(i=k-1;i<=n-k;i++){
                arr[i][j]=x;
                x++;
            }
            i--;
            for(j=k;j<=n-k;j++){
                arr[i][j]=x;
                x++;
            }
            j--;
            for(i=i-1;i>=k-1;i--){
                arr[i][j]=x;
                x++;
            }
            i++;
            for(j=j-1;j>=k;j--){
                arr[i][j]=x;
                x++;
            }
            j++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}