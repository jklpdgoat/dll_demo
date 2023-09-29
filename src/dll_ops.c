#include "../include/dll_ops.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Try Doubly Linked XOR List
  (ground/term)
  | data | XOR (NULL, 200) | ::   <-- Node @ mem adrress 100 (head)
  | data | XOR (100, 300) | ::    <-- Node @ mem adrress 200
  | data | XOR (200, NULL) | ::   <-- Node @ mem adrress 300
*/

typedef struct DLLNode {
        int data;
        // "x_ptr": XOR of the previos and next node address
        struct DLLNode *x_ptr;
        // struct DLLNode *next;
        // struct DLLNode* prev;
} DLLNode;

DLLNode *XOR(DLLNode *a, DLLNode *b) {
        return (DLLNode *)((unsigned int)(a) ^ (unsigned int)(b));
}

/*
Insert a node at the start of the XORed LL and make the newly inserted
node as head

insertNode function expects an address '&head' for reference and the
actual data to be inserted */
void insertNode(DLLNode **head_ref, int data) {
        // malloc for new node
        DLLNode *new_node = (DLLNode *)malloc(sizeof(DLLNode));
        // set newly inserted data as head
        new_node->data = data;

        // first node will always have XOR(NULL, Address)
        // and last node XOR(Address,NULL)
        new_node->x_ptr = XOR(*head_ref, NULL);

        // handle if LL is empty or not.
        // if it's not empty then x_ptr of the current head node will be the
        // XOR (new_node, current head)
        if (*head_ref != NULL) {
                // *(head_ref)->x_ptr is XOR of NULL and the next node
                // We should get next by XOR-ing it with NULL
                DLLNode *next = XOR((*head_ref)->x_ptr, NULL);
                (*head_ref)->x_ptr = XOR(new_node, next);
        }

        // Update head
        *head_ref = new_node;
}

// prints contents of doubly linked list in forward direction
void showList(DLLNode *head) {
        DLLNode *curr = head;
        DLLNode *prev = NULL;
        DLLNode *next;

        printf("LL Nodes: ");

        while (curr != NULL) {
                // print curr node
                printf("%d ", curr->data);

                next = XOR(prev, curr->x_ptr);

                prev = curr;
                curr = next;
        }
}

int main() {

        // call a function in another file
        // myPrintHelloMake();

        DLLNode *head = NULL;
        insertNode(&head, 10);
        insertNode(&head, 20);
        insertNode(&head, 30);
        insertNode(&head, 40);

        // print the created list
        showList(head);

        return 0;
}