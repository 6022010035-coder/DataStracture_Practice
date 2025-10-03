#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createCSLL(int n) {
    Node *head = malloc(sizeof(Node)), *curr = head;
    head->data = 0;
    for(int i=1; i<n; i++) {
        curr->next = malloc(sizeof(Node));
        curr = curr->next;
        curr->data = i;
    }
    curr->next = head; // circular
    return head;
}

Node* createSLL(int n) {
    Node *head = malloc(sizeof(Node)), *curr = head;
    head->data = 0;
    for(int i=1; i<n; i++) {
        curr->next = malloc(sizeof(Node));
        curr = curr->next;
        curr->data = i;
    }
    curr->next = NULL;
    return head;
}

void traverseCSLL(Node *head, int n) {
    Node *curr = head;
    for (int i=0; i<n; i++) curr = curr->next;
}

void traverseSLL(Node *head, int n) {
    Node *curr = head;
    for (int i=0; i<n; i++) {
        if (!curr) curr = head; // manual reset
        curr = curr->next;
    }
}

int main() {
    int n = 100000, trials = 25;
    Node *csll = createCSLL(n), *sll = createSLL(n);
    clock_t start, end;
    double time_csll = 0, time_sll = 0;

    for(int t=0; t<trials; t++) {
        start = clock();
        traverseCSLL(csll, n);
        end = clock();
        time_csll += (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        traverseSLL(sll, n);
        end = clock();
        time_sll += (double)(end-start)/CLOCKS_PER_SEC;
    }
    printf("CSLL avg: %.6f s\n", time_csll/trials);
    printf("SLL  avg: %.6f s\n", time_sll/trials);
    return 0;
}
