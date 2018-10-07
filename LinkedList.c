//
// Created by nikhil on 10/7/18.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void addNode(Node **root, int data) {
    Node *temp;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    temp = *root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dispalyData(Node *root) {
    while (root != NULL) {
        printf("%d\n", root->data);
        root = root->next;
    }
}

int main() {
    Node *root = NULL;
    // int count=0;
    int ch = 1;
    do {

        printf("1.Add node\n");
        printf("2.Display data\n");
        printf("3.Exit.\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Adding node......\n");
                addNode(&root, 15);
                printf("%d\n", root->data);
                addNode(&root, 20);
                printf("%d\n", root->data);
                printf("***********************************************************************\n");
                break;
            case 2:
                printf("Displaying data.......\n");
                dispalyData(root);
                printf("***********************************************************************\n");

                break;
            case 3:
                printf("Exit.\n");
                printf("***********************************************************************\n");

                exit(1);

                break;

            default:
                printf("Enter valid choice\n");
                break;
        }
        printf("Do u want to continue?(1 for continue)");
        scanf("%d", &ch);
    } while (ch != 3);
    return 0;
}