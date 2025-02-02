#include<stdio.h>
#define max 30
int n;
int graph[max][max];
int x[max];

void nextvertex(int k) {
    int j;
    do {
        x[k] = (x[k] % n) + 1; // Increment x[k] and loop around if it exceeds n

        if (x[k] == 0) // If we looped around, return
            return;

        if (graph[x[k - 1]][x[k]]) { // Check if there's an edge between x[k-1] and x[k]
            for (j = 1; j < k; j++) {
                if (x[j] == x[k]) // Check if the vertex is already visited
                    break;
            }
            if (j == k) { // If not visited, check if it forms a cycle
                if (k < n || (k == n && graph[x[n]][1])) // If it forms a cycle, return
                    return;
            }
        }
    } while (1);
}




void hamiltonian(int k){
    nextvertex(k);
    if(x[k]==0)
        return;
    if(k==n){
        for(int i=1;i<=n;i++)
            printf("%d->",x[i]);
    }
    else{
        hamiltonian(k+1);
    
    }
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
hamiltonian(2);

}