#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* add_front(Node* n, int v) {
    Node* new_node = malloc(sizeof(Node));
        if (new_node == NULL) {
        return n;
    }
    new_node->value = v;
    new_node->next = n;
    return new_node;
}

Node* add_back(Node* n, int v) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return n;
    }
    new_node->value = v;
    new_node->next = NULL;
    if (n == NULL) {
        return new_node;
    }
    Node* temp = n;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return n;
}

int print_list(Node* n) {
    while (n != NULL) {
        printf("%d ", n->value);
        n = n->next;
    }
    return 0;
}

int free_list(Node* n) {
    Node* temp;
    while (n != NULL) {
        temp = n;
        n = n->next;
        free(temp);
    }
    return 0;
}


int main(void) {
    Node* n = NULL;
    int v = 6;
    n = add_front(n, v);
    v = 3;
    n = add_back(n, v);
    print_list(n);
    free_list(n);
    return 0;
}