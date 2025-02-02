#include<stdio.h>
#define true 1
#define false 0
#define intmax 9999
#define max 50
int n;
int cost[max][max];
int s[max];
int dist[max];

void shortestpath(int v){
int u;
    for(int i=1;i<=n;i++){
        dist[i]=intmax;
        s[i]=false;
    }
        for(int j=1;j<=n;j++)
            dist[j]=cost[v][j];
    s[v]=true;
    dist[v]=0;
    for(int j=2;j<=n;j++){
        int min = intmax;
        for(int i=1;i<=n;i++){
            if(dist[i]<min){
                min =dist[i];
                u=i;
            }
        }
        s[u]=true;
        for(int w=1;w<=n;w++){
            if(s[w]==false && cost[u][w] != intmax && dist[w]>dist[u]+cost[u][w]){
                dist[w]=dist[u]+cost[u][w];
            }
        }
    }
    
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
    shortestpath(1);
return 0;
}