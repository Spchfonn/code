#include <stdio.h>
#include <stdlib.h>

void traverseMaze(char **arr,int sti,int stj,int n)
{
    int x[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};
    for(int i=0;i<4;i++){
        if(sti+x[i][0]<0 || sti+x[i][0]>=n || stj+x[i][1]<0 || stj+x[i][1]>=n)
            continue;
        if(arr[sti+x[i][0]][stj+x[i][1]]=='G'){
            arr[sti][stj] = '.';
            for(int j = 0; j < n; j++) printf("%s\n",arr[j]);
        }
        if(arr[sti+x[i][0]][stj+x[i][1]]==' '){
            if (arr[sti][stj]!='S')
                arr[sti][stj] = '.';
            traverseMaze(arr,sti+x[i][0],stj+x[i][1],n);
            arr[sti][stj] = ' ';
        }
    }
}

int main(void)
{
    char **arr,j;
    int n,sti,stj;
    scanf("%d ", &n);
    arr = (char **)malloc(sizeof(char *) * n);
    for(int i=0;i<n;i++){
        j = 0;
        arr[i] = (char *)malloc(sizeof(char) * n + 2);
        fgets(arr[i],n + 2,stdin);
        arr[i][n] = '\0';
        while(arr[i][j]){
            if(arr[i][j]=='S'){
                sti = i;
                stj = j;
            }
            j++;
        }
    }
    traverseMaze(arr,sti,stj,n);
}