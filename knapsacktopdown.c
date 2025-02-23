#include<stdio.h>

int max(int a,int b){
return a>b?a:b;
}

int knapsack(int w,int wt[],int val[],int n){
int t[n+1][w+1];//dynamic array

for(int i=0;i<=n;i++){
	for(int j=0;j<=w;j++){
	if(i==0||j==0)
		t[i][j]=0;
	else if(wt[i-1]<=j){
		t[i][j]=max((val[i-1]+t[i-1][j-wt[i-1]]),t[i-1][j]);
	}
	else if(wt[i-1]>j)
		t[i][j]=t[i-1][j];
	
	}
}

return t[n][w];


}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum value that can be obtained is %d\n", knapsack(W, wt, val, n));
    return 0;
}

