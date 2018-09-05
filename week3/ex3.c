#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

void print_list(LinkedList *list) {
    if (list->head) {
        Node *current = list->head;
        while (current) {
            printf("data# %d ", current->data);
            current = current->next;
        }
    }
    else {
        printf("List is empty");
    }
    printf("\n");
}

// existingNode is a node which belongs to the list
void insert_node(Node *existingNode, Node *newNode, LinkedList *list) {
    if (!existingNode) { // list is empty
        list->head = newNode;
        list->head->next = NULL;
        list->tail = list->head;
    }
    else { // list is not empty
        newNode->next = existingNode->next;
        existingNode->next = newNode;
        if (newNode->next == NULL) { // newnode is a new tail in the list
            list->tail = newNode;
        }
    }

    printf("New node was inserted: data# %d\n", newNode->data);
}

Node * previousNode(Node *node, LinkedList *list) {
    Node *current = list->head;
    while (current && current->next != node) {
        current = current->next;
    }

    return current;
}

void delete_node(Node *node, LinkedList *list) {
    if (list->head == node) {
        list->head = node->next;
        if (!list->head) {
            list->tail = NULL;
        }
    }
    else {
        Node *previous = previousNode(node, list);
        previous->next = node->next;
        if (node == list->tail) {
            list->tail = previous;
        }
    }
    printf("Node was deleted: data# %d\n", node->data);

    free(node);
}

void initialize_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    int n;
    printf("Enter count of elements: ");
    scanf("%d", &n);

    LinkedList *list = malloc(sizeof(LinkedList));
    initialize_list(list);
    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);
        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        insert_node(list->tail, newNode, list);
    }

    print_list(list);
    delete_node(list->head, list);
    print_list(list);
    delete_node(list->tail, list);
    Node *temp = malloc(sizeof(Node));
    temp->data = -100;
    temp->next = NULL;
    insert_node(list->head, temp, list);
    print_list(list);
    delete_node(temp, list);
    print_list(list);

    return 0;
}
