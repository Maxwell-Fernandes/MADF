#include<stdio.h>
#define max 50

int fowardgraph(int levels,int g[max][max],int cost[max],int n){
    int p[n];
    int d[n];
    int min =max;
    cost[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]!=max && min>cost[j]+g[i][j]){
                min =cost[j]+g[i][j];
                d[i]=j;
                cost[i]=min;
            }
        }
    }
    p[1]=1;p[levels]=n;
    for(int j=levels-1;j<1;j--){
        p[j]=d[p[j+1]];
    }


return cost[n];
}

int main(){
    int g[max][max],n,e,cost[max],levels;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=max;
        }
    }
    for (int i=0;i<n;i++){
    	cost[i]=max;
    }
    int src,dest,cos;
    printf("Enter the number of Edges : ");
    scanf("%d",&e);
    for(int i=1;i<=e;i++){
        printf("Enter the source and destination vertex : ");
        scanf("%d %d",&src,&dest);
        printf("Enter the cost for the edge : ");
        scanf("%d",&cos);
        g[src][dest]=cos;
    }
    printf("Enter the levels : \n");
    scanf("%d",&levels);
    
   int ans= fowardgraph(levels,g,cost,n);
    printf("Shortest path from %d",ans);
  
	return 0;
}
