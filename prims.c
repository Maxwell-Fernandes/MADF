#include<stdio.h>
#include<stdlib.h>
#define max 50
#define intmax 9999
int cost[max][max];
int n;
int near[max];
int t[max][2];

int prims(){
int mincost;
int k,l;
int min=intmax;
for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
    if(cost[i][j]<min){
        
        min =cost[i][j];
        k=i;
        l=j;
    }
    }
    }
    mincost=cost[k][l];
    t[1][1]=k;
    t[1][2]=l;
    for(int i=1;i<=n;i++){
        if(cost[i][k]<cost[i][l]){
            near[i]=k;
        }else{
            near[i]=l;
        }
    }
    near[k]=0;
    near[l]=0;
    for(int i=2;i<n;i++){
        int j;
        int dummycost=intmax;
        for(int w=1;w<=n;w++){
            if(near[w]!=0&&cost[w][near[w]]<dummycost){
                j=w;
                dummycost=cost[w][near[w]];
            }
        }
        t[i][1]=j;
        t[i][2]=near[j];
        mincost=mincost+cost[j][near[j]];
        near[j]=0;
        for(int k=1;k<=n;k++){
            if(near[k]!=0&&cost[k][near[k]]>cost[k][j]){
                near[k]=j;
            }
        }
    }
    return mincost;
}

int main(){
    int src,dest,c;
    printf("Enter the no of edgess\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            cost[i][j]=intmax;
        }
    }
    while(1){
        printf("Enter src and dest and cost(-1 -1 -1to exit)\n");
        scanf("%d %d %d",&src,&dest,&c);
        if(src==-1&&dest==-1)
            break;
        cost[src][dest]=c;
        cost[dest][src]=c;
    }
   int ans= prims();
   printf("%d",ans);
   for(int i=1;i<=n;i++){
    for(int j=1;j<=2;j++){
        printf("%d ",t[i][j]);
    }
    printf("\n");
   }
    return 0;
}