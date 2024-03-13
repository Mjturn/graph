#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
} Node;

Node* construct_node(int value, int* number_of_nodes) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->value = value;
    (*number_of_nodes)++;
    
    return node;
}

void add_edge(int number_of_nodes, int adjacency_matrix[][number_of_nodes], int source_index, int destination_index) {
    adjacency_matrix[source_index][destination_index] = 1;
}

int main() {
    int number_of_nodes = 0;
    
    for(int i = 1; i <= 5; i++) {
        Node* node = construct_node(i, &number_of_nodes);
    }

    int adjacency_matrix[number_of_nodes][number_of_nodes];

    for(int i = 0; i < number_of_nodes; i++) {
        for(int j = 0; j < number_of_nodes; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    
    const int MAX_VALUE = number_of_nodes;
    srand(time(0));

    for(int i = 0; i < 5; i++) {
        int source_index = (rand() % MAX_VALUE);
        int destination_index = (rand() % MAX_VALUE);
        add_edge(number_of_nodes, adjacency_matrix, source_index, destination_index);
    }

    for(int i = 0; i < number_of_nodes; i++) {
        for(int j = 0; j < number_of_nodes; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
