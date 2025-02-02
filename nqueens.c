#include<stdio.h>
int n;
int count=0;
void solve(int col,char board[n][n],int n,int leftrow[],int upperdia[],int lowerdia[]){
    if(col==n){
        printf("\n%d)\n",++count);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0&&upperdia[n-1 + col -row]==0 && lowerdia[row+col]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lowerdia[row+col]=1;
            upperdia[n-1 + col-row]=1;
            solve(col+1,board,n,leftrow,upperdia,lowerdia);
            board[row][col]='_';
            leftrow[row]=0;
            lowerdia[row+col]=0;
            upperdia[n-1 + col-row]=0;

        }
    }

}


int main(){
    printf("Enter the size of the board\n");
    scanf("%d",&n);
    char board[n][n];
    int leftrow[n];
    int lowerdia[2*n-1];
    int upperdia[2*n-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='_';
        }
    }
    for(int i=0;i<n;i++)
        leftrow[i]=0;
    for(int i=0;i<2*n-1;i++){
        lowerdia[i]=0;
        upperdia[i]=0;
    }
 solve(0,board,n,leftrow,upperdia,lowerdia);
}