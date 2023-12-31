#include<stdio.h>
#include<string.h>
char arr1[100010][60],arr2[100010][60];

char *sort(char *w){
    for(int i=1;i<w[i];i++){
        char check = w[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(check<w[j]) w[j+1] = w[j];
            else break;
        }
        w[j+1] = check;
    }
    return w;
}

int main(){
    int m,n;
    char word[60];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf(" %s",arr1[i]);
        strcpy(arr2[i],arr1[i]);
        sort(arr2[i]);
    }
    for(int i=0;i<n;i++){
        scanf(" %s",word);
        sort(word);
        for(int j=0;j<m;j++){
            if(!strcmp(word,arr2[j])){
                printf("%s ",arr1[j]);
            }
        }
        printf("\n");
    }

    return 0;
}