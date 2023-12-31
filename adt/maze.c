#include<stdio.h>
#include<stdlib.h>
void traverseMaze(int n,char **arr,int sti,int stj){
    int x[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};
    for(int i=0;i<4;i++){
        if(sti+x[i][0]<0 || sti+x[i][0]>=n || stj+x[i][1]<0 || stj+x[i][1]>=n){
            continue;
        }
        else if(arr[sti+x[i][0]][stj+x[i][1]]=='G'){
            arr[sti][stj]='.';
            for(int j=0;j<n;j++) printf("%s", arr[j]);
        }
        else if(arr[sti+x[i][0]][stj+x[i][1]]==' '){
            if(arr[sti][stj]==' ') arr[sti][stj]='.';
            traverseMaze(n,arr,sti+x[i][0],stj+x[i][1]);
        }
    }

}

int main(){
    int n,sti,stj;
    char **arr;
    scanf("%d ",&n);
    arr = (char **)malloc(sizeof(char *) * n);
    for(int i=0;i<n;i++){
        arr[i] = (char *)malloc(sizeof(char) * n + 2);
        fgets(arr[i],n + 2,stdin);
        for(int j=0;j<=n;j++){
            if(arr[i][j]=='S'){
                sti=i;
                stj=j;
            }
        }
    }
    traverseMaze(n,arr,sti,stj);
    
    return 0;
}

/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############
*/