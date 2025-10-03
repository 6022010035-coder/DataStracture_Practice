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
    curr->next = head;
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

Node* rotateCSLL(Node *head, int k) {
    for(int i=0; i<k; i++) head = head->next;
    return head;
}

Node* rotateSLL(Node *head, int k) {
    if(!head || !head->next) return head;
    Node *curr = head;
    int count = 1;
    while(curr->next && count < k) {
        curr = curr->next; count++;
    }
    if(!curr->next) return head;
    Node *newHead = curr->next;
    curr->next = NULL;
    Node *tail = newHead;
    while(tail->next) tail = tail->next;
    tail->next = head;
    return newHead;
}

int main() {
    int n = 100000, k = n/2, trials = 10;
    Node *csll = createCSLL(n), *sll = createSLL(n);
    clock_t start, end;
    double t1=0, t2=0;

    for(int t=0; t<trials; t++) {
        start = clock();
        rotateCSLL(csll, k);
        end = clock();
        t1 += (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        sll = rotateSLL(sll, k);
        end = clock();
        t2 += (double)(end-start)/CLOCKS_PER_SEC;
    }
    printf("Rotate CSLL: %.6f s\n", t1/trials);
    printf("Rotate SLL:  %.6f s\n", t2/trials);
    return 0;
}
