#include <stdio.h>
#include <stdlib.h>
int i, j, k, a, b, u, v, n, ne=1;
int min, mincost=0, cost[9][9], parent[9];
int find(int i) {
    while(parent[i])
        i=parent[i];
    return i;
}
void uni(int i, int j) {
    parent[j] = i;
}
void main() {
    printf("Implementation of Kruskal's algorithm\n");
    printf("Enter the number of vertices ");
    scanf("%d", &n);
    printf("Enter the cost of adjacency matrix\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) 
                cost[i][j]=999;
        }
    }
    printf("\nThe edge of mini cost spanning tree are\n");
    while(ne<n) {
        for(i=1,min=999; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(cost[i][j]<min) {
                    min = cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(u!=v) {
            uni(u,v);
            printf("\n%dedge(%d,%d)=%d\n",ne++,a,b,min);
            mincost += min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost = %d\n",mincost);
}
