#include <stdio.h>

#define V 4

void addEdge(int matrix[V][V], int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d    ", matrix[i][j]);
        }
        printf("\n");
    }
}

int hasCycleUtil(int matrix[V][V], int v, int visited[], int parent) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (matrix[v][i]) {
            if (!visited[i]) {
                if (hasCycleUtil(matrix, i, visited, v)) {
                    return 1;
                }
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle(int matrix[V][V]) {
    int visited[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(matrix, i, visited, -1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int matrix[V][V] = {0};
    int n;
    int a, b;

    printf("Nhap so canh: ");
    scanf("%d", &n);
    printf("Nhap cac canh:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        addEdge(matrix, a, b);
    }

    printMatrix(matrix);

    if (hasCycle(matrix)) {
        printf("Do thi co chu ky\n");
    } else {
        printf("Do thi khong co chu ky\n");
    }

    return 0;
}