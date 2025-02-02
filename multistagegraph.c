#include<stdio.h>
#include<stdbool.h>
#define max 999
int shortestpath(int k,int g[max][max],int cost[max],int n){
	int p[max];
	int d[n];
	int count=0;
	int min,dummy=k;
	cost[n]=0;
	printf("(%d,%d)=%d\n",k,n,cost[n]);
	for(int j=n-1;j>=1;j--){
		if(count++%4==0)
			dummy=dummy-1;
		min=max;
		for(int l=n;l>=1;l--){
			if(g[j][l]!=999 && min>cost[l]+g[j][l]){
				min=cost[l]+g[j][l];
				cost[j]=min;
				d[j]=l;
			}
		}
		 printf("(%d,%d)=%d\t",dummy,j,cost[j]);
		 printf("(%d,%d)=%d\n",dummy,j,d[j]);

	}
	p[1]=1;
	p[k]=n;
	for(int j=2;j<k;j++){
	p[j]=d[p[j-1]];
	}
	for(int i=1;i<=k;i++){
		printf("%d",p[i]);
		if(i!=k)
			printf("->");
		}
printf("\n");
	return cost[1];
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
    
   int ans= shortestpath(levels,g,cost,n);
    printf("Shortest path from %d",ans);
  
	return 0;
}
