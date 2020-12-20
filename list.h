#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Record.h"


typedef struct Node {
    Record value;
    struct Node *next;
} Node;

void push(Node **head, Record data) {}

void pop(Node **head) { }

Node* getNth(Node* head, int n) {  }

Node* getLast(Node *head) { }

void pushBack(Node *head, Record value) { }

Node* getLastButOne(Node* head) { }		

void popBack(Node **head) { }

void insert(Node *head, unsigned n, Record val) { }

void deleteNth(Node **head, int n) { }

int getLength(const Node *head){}

void printList(const Node *head) {}