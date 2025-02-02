#include<stdio.h>
#include<stdlib.h>
#define max 50
int n;
int m;
char p[max];
char t[max];

int min(int a,int b){
    return a<b?a:b;
}

int lastoccurance(char c){
    for(int i=m-1;i>=0;i--){
        if(p[i]==c)
            return i;
    }
return -1;
}


int boyer(){
    int l;
    int i=m-1;
    int j=m-1;
    do{
        if(t[i]==p[j]){
            if(j==0)
                return i;
            else{
                i--;
                j--;
            }
        }else{
            i=i+(m-1)-min(j-1,lastoccurance(t[i]));;
            j=m-1;
        }
  
        }while(i<n);
    return -1;  
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
int ans=boyer();
printf("string starting index is %d",ans);
return 0;
}