#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DLL {
    int data;
    struct DLL *prev, *next;
} DLL;

typedef struct SLL {
    int data;
    struct SLL *next;
} SLL;

DLL* createDLL(int n) {
    DLL *head = malloc(sizeof(DLL)), *curr = head;
    head->data = 0; head->prev = NULL;
    for(int i=1; i<n; i++) {
        curr->next = malloc(sizeof(DLL));
        curr->next->data = i;
        curr->next->prev = curr;
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

SLL* createSLL(int n) {
    SLL *head = malloc(sizeof(SLL)), *curr = head;
    head->data = 0;
    for(int i=1; i<n; i++) {
        curr->next = malloc(sizeof(SLL));
        curr->next->data = i;
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

void eraseDLL(DLL *node) {
    if (!node) return;
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    free(node);
}

void eraseSLL(SLL *head, SLL *target) {
    if (!head || !target) return;
    if (head == target) return; // need pred
    SLL *curr = head;
    while (curr && curr->next != target) curr = curr->next;
    if (curr) {
        curr->next = target->next;
        free(target);
    }
}

int main() {
    int n = 100000, trials = 20;
    clock_t start, end;
    double tDLL=0, tSLL=0;

    for(int t=0; t<trials; t++) {
        DLL *dll = createDLL(n);
        SLL *sll = createSLL(n);

        DLL *targetDLL = dll->next->next; // pick middle
        SLL *targetSLL = sll->next->next;

        start = clock();
        eraseDLL(targetDLL);
        end = clock();
        tDLL += (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        eraseSLL(sll, targetSLL);
        end = clock();
        tSLL += (double)(end-start)/CLOCKS_PER_SEC;
    }
    printf("DLL erase avg: %.6f s\n", tDLL/trials);
    printf("SLL erase avg: %.6f s\n", tSLL/trials);
    return 0;
}
