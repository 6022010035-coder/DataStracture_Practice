#include <stdio.h>
#include <stdlib.h>

typedef struct SLL {
    int data;
    struct SLL *next;
} SLL;

typedef struct CSLL {
    int data;
    struct CSLL *next;
} CSLL;

typedef struct DLL {
    int data;
    struct DLL *next, *prev;
} DLL;

int main() {
    int n = 100000;
    printf("On 64-bit system (8 bytes/pointer):\n");
    printf("SLL: 1 pointer/node = %zu bytes\n", sizeof(SLL)-sizeof(int));
    printf("CSLL: 1 pointer/node = %zu bytes\n", sizeof(CSLL)-sizeof(int));
    printf("DLL: 2 pointers/node = %zu bytes\n", sizeof(DLL)-sizeof(int));

    printf("\nFor %d nodes:\n", n);
    printf("SLL ~ %.2f MB\n", n*(sizeof(SLL))/1024.0/1024.0);
    printf("CSLL ~ %.2f MB\n", n*(sizeof(CSLL))/1024.0/1024.0);
    printf("DLL ~ %.2f MB\n", n*(sizeof(DLL))/1024.0/1024.0);

    return 0;
}
