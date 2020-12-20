#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"





void push(Node **head, Record data) { // Добавляет элемент в начало списка
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


void pop(Node **head) { // Удаляет конечный элемент
    Node* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}


Node* getNth(Node* head, int n) {  // Возвращает n - элемент
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}



Node* getLast(Node *head) { // возвращает последний элементр
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}


void pushBack(Node *head, Record value) { // Добавляет элемент в конец
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}


Node* getLastButOne(Node* head) { // Возвращает предпоследний элемент
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}		




void popBack(Node **head) { // удаляет последний элемент
    Node *lastbn = NULL;
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    //Если в списке один элемент
    if (lastbn == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}


void insert(Node *head, unsigned n, Record val) { // Вставляет на n - место новое значение
    unsigned i = 0;
    Node *tmp = NULL;
    //Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
    //ошибка выбрасываться не будет, произойдёт вставка в конец
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = val;
    //Если это не последний элемент, то next перекидываем на следующий узел
    if (head->next) {
        tmp->next = head->next;
    //иначе на NULL
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}


void deleteNth(Node **head, int n) {  // Удаляет n - элемент
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
 
        prev->next = elm->next;
        free(elm);
    }
}



int getLength(const Node *head){
	int counter = 0;
    while (head) {
    	counter++;
        head = head->next;
    }
    return counter;
}

void printList(const Node *head) {
	int counter = 0;
    while (head) {
    	counter++;
        printf("%i: %s | %s | %s | %s | %s | %s\n", counter, head->value.work, head->value.student, head->value.variant, head->value.level, head->value.date, head->value.mark); 
        head = head->next;
    }
    printf("\n");
}