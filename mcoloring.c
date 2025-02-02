#include<stdio.h>
#define max 30
int n;
int graph[max][max];
int x[max];

void nextvertex(int k){
    
do{
    x[k]=(x[k]%n)+1;
    if(x[k]==0)
        return;
    for(int j=1;j<=n;j++){
        if(graph[k][j]!=0&&(x[k]==x[j]))
            break;
        if(j==n){
        return;
    }

    }

}while(1);
}


void mcolor(int k){
    nextvertex(k);
    if(x[k]==0){
        return;
    }else if(k==n){
        for(int i=1;i<=n;i++){
            printf("%d ",x[i]);
        }
    }else
        mcolor(k+1);
}
int main(){
printf("Enter the number of vertices\n");
scanf("%d",&n);
int src,dest;
for(int i=1;i<=n;i++){
    x[i]=0;
    for(int j=1;j<=n;j++)
        graph[i][j]=0;
}
while(1){
printf("Enter source and destination(-1 -1 to exit)\n");
scanf("%d%d",&src,&dest);
if(src==-1&&dest==-1)
    break;
graph[src][dest]=graph[dest][src]=1;
}
x[1]=1;
mcolor(2);
}