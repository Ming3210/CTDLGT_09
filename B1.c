#include <stdio.h>
#include <stdlib.h>
#define V 4

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


void addEdge(int matrix[V][V],Node *arr[],int i, int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
	
	Node* newNode = createNode(j);
	newNode->next = arr[i];
	arr[i] = newNode;
	
	newNode = createNode(i);
	newNode->next = arr[j];
	arr[j] = newNode;
}

void printMatrix(int matrix[V][V]){
	for(int i = 0;i<V;i++){
		for(int j = 0;j<V;j++){
			printf("%d    ",matrix[i][j]);
		}
		printf("\n");
	}
}

void printAdj(Node* arr[V]) {
    printf("Do thi vo huong:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        Node* temp = arr[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
int matrix[V][V] = {0};
    Node* adj[V] = {NULL};

    addEdge(matrix, adj, 0, 1);
    addEdge(matrix, adj, 0, 2);
    addEdge(matrix, adj, 1, 2);
    addEdge(matrix, adj, 2, 3);

    printMatrix(matrix);
    printAdj(adj);
	return 0;
}
