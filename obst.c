#include <stdio.h>
#include <limits.h>

int find(int c[][6], int r[][6], int i, int j);
void obst(int, int *, int *);

void printtable(int w[][6],int c[][6],int r[][6],int m)
{
    for(int i=0;i<6-m;i++)
    {
        printf("weight: %d\t",w[i][i+m]);
    }
    printf("\n");
    for(int i=0;i<6-m;i++)
    {
        printf("cost: %d\t",c[i][i+m]);
        if(m==0)
        printf("\t");
    }
    printf("\n");
    for(int i=0;i<6-m;i++)
    {
        printf("root: %d\t",r[i][i+m]);
        printf("\t");
    }
    printf("\n\n");
}
int main() {
    int n;
    printf("Enter the number of identifiers: ");
    scanf("%d", &n);
    int p[n + 1], q[n + 1];
    printf("Enter P:");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter Q:");
    for (int i = 0; i <= n; i++)
        scanf("%d", &q[i]);
    obst(n, p, q);
}

void obst(int n, int p[n + 1], int q[n + 1]) {
    int w[n + 1][n + 1], r[n + 1][n + 1], c[n + 1][n + 1],m=0;
    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
    }
    printtable(w,c,r,m);
    m++;
    for (int i = 0; i <= n; i++) {
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
    }
    printtable(w,c,r,m);
    w[n][n] = q[n];
    r[n][n] = 0;
    c[n][n] = 0;
    for ( m = 2; m <= n; m++) {
        for (int i = 0; i <= n - m; i++) {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = find(c, r, i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
        printtable(w,c,r,m);
    }
}

int find(int c[][6], int r[][6], int i, int j) {
    int min = INT_MAX, l;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
        if (c[i][m - 1] + c[m][j] < min) {
            l = m;
            min = c[i][m - 1] + c[m][j];
        }
    }
    return l;
}
