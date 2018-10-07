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
    printf("%d\n", root->data);
    if(root->next==NULL){
        return;
    }
    dispalyData(root->next);//recursive function call
}
int main(){
    Node *root = NULL;
    printf("Adding node......\n");
    addNode(&root, 15);
    printf("%d\n", root->data);
    addNode(&root, 20);
    printf("%d\n", root->data);
    printf("Displaying data.......\n");
    dispalyData(root);
}