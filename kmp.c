#include<stdio.h>
#include<stdlib.h>
#define max 50
char p[max];
char t[max];
int n;
int m;
int fail[max];


void kmpfailure(){
int i=1;
int j=0;
fail[0]=0;
while(i<m){
    if(p[j]==p[i]){
        fail[i]=j+1;
        i++;
        j++;
    }else if(j>0){
        j=fail[j-1];
    }else{
        fail[i]=0;
        i++;
    }
}
}



int kmp(){
int i=0;
int j=0;
while(i<n){
    if(p[j]==t[i]){
        if(j==m-1)
            return i-m+1;
    i++;
    j++;
    }else if(j>0)
        j=fail[j-1];
    else
        i++;
}
}


int main(){
 printf("Enter the length of your string\n");
 scanf("%d",&n);
 printf("Enter your string\n");
 for(int i=0;i<n;i++){
    scanf("%s",&t[i]);
 }  
 printf("Enter the length of string to be searched\n");
 scanf("%d",&m);
 for(int i=0;i<m;i++){
    scanf("%s",&p[i]);
 }
int ans=kmp();
printf("string starting index is %d",ans);
return 0;
}
