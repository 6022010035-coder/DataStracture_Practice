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

void deleteWithPred(Node *pred) {
    Node *target = pred->next;
    pred->next = target->next;
    free(target);
}

void deleteWithoutPred(Node *head, Node *target) {
    Node *curr = head;
    while(curr->next != target) curr = curr->next; // O(n)
    curr->next = target->next;
    free(target);
}

int main() {
    int n = 100000, trials = 25;
    Node *csll = createCSLL(n), *head = csll;
    clock_t start, end;
    double t1=0, t2=0;

    for(int t=0; t<trials; t++) {
        Node *pred = head, *target = head->next;

        start = clock();
        deleteWithPred(pred);
        end = clock();
        t1 += (double)(end-start)/CLOCKS_PER_SEC;

        csll = createCSLL(n);
        head = csll;
        target = head->next;

        start = clock();
        deleteWithoutPred(csll, target);
        end = clock();
        t2 += (double)(end-start)/CLOCKS_PER_SEC;
    }
    printf("With predecessor: %.6f s\n", t1/trials);
    printf("Without predecessor: %.6f s\n", t2/trials);
    return 0;
}
