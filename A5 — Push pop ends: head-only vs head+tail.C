#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} DLL;

Node* pushFrontSLL(Node *head, int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->next = head;
    return node;
}

Node* pushBackSLL(Node *head, int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    if (!head) return node;
    Node *curr = head;
    while(curr->next) curr = curr->next;
    curr->next = node;
    return head;
}

DLL pushFrontDLL(DLL list, int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->prev = NULL;
    node->next = list.head;
    if (list.head) list.head->prev = node;
    else list.tail = node;
    list.head = node;
    return list;
}

DLL pushBackDLL(DLL list, int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    node->prev = list.tail;
    if (list.tail) list.tail->next = node;
    else list.head = node;
    list.tail = node;
    return list;
}

int main() {
    int n = 5000, trials = 20;
    clock_t start, end;
    double tSLLfront=0, tSLLback=0, tDLL=0;

    for (int t=0; t<trials; t++) {
        Node *sll=NULL;
        DLL dll={NULL,NULL};

        start = clock();
        for (int i=0;i<n;i++) sll = pushFrontSLL(sll,i);
        end = clock();
        tSLLfront += (double)(end-start)/CLOCKS_PER_SEC;

        sll=NULL;
        start = clock();
        for (int i=0;i<n;i++) sll = pushBackSLL(sll,i);
        end = clock();
        tSLLback += (double)(end-start)/CLOCKS_PER_SEC;

        dll.head=dll.tail=NULL;
        start = clock();
        for (int i=0;i<n;i++) dll = pushBackDLL(dll,i);
        end = clock();
        tDLL += (double)(end-start)/CLOCKS_PER_SEC;
    }
    printf("SLL push_front avg: %.6f s\n", tSLLfront/trials);
    printf("SLL push_back avg:  %.6f s\n", tSLLback/trials);
    printf("DLL push_back avg:  %.6f s\n", tDLL/trials);
    return 0;
}
