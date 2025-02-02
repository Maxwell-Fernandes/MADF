#include<stdio.h>
#define max 50
#define intmax 9999
int dist[max];
int n;
cost[max][max];


void bellmanford(int v){
    for(int i=1;i<=n;i++){
        dist[i]=cost[v][i];
    }
    dist[v]=0;
    for(int w=2;w<n;w++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;i++){
            if(j=!i&&cost[i][j]!=intmax){
                if(dist[j]>dist[i]+cost[i][j])
                    dist[j]=dist[i]+cost[i][j];
            }
        }
    }
    }
}