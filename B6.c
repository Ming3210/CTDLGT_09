#include <stdio.h>

#define V 10

void findHighestDegree(int graph[V][V], int n) {
    int degree[V]; 
    int maxDegree = -1; 
    int max = -1;  

    for (int i = 0; i < n; i++) {
        degree[i] = 0; 
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                degree[i]++; 
            }
        }

        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            max = i;
        }
    }

    printf("Dinh co bac cao nhat la: %d\n", max);
}

int main() {
    int n, m;
    printf("Nhap so luong dinh: ");
    scanf("%d", &n);
    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    int graph[V][V] = {0};

    printf("Nhap cac canh (dinh1, dinh2):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
        graph[v][u] = 1;  
    }

    findHighestDegree(graph, n);

    return 0;
}
