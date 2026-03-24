#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "purchase_history.h"

static Purchase* head = NULL;
static Purchase* tail = NULL;

static Purchase* findPurchaseByRecordId(int recordId) {
    Purchase* cur = head;
    while (cur != NULL) {
        if (cur->recordId == recordId) return cur;
        cur = cur->next;
    }
    return NULL;
}

void addPurchaseRecord(void) {
    Purchase* node = (Purchase*)malloc(sizeof(Purchase));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter record id: ");
    scanf("%d", &node->recordId);

    if (findPurchaseByRecordId(node->recordId) != NULL) {
        printf("Record ID already exists.\n");
        free(node);
        return;
    }

    printf("Enter customer id: ");
    scanf("%d", &node->customerId);
    printf("Enter customer name: ");
    scanf(" %49[^\n]", node->customerName);
    printf("Enter purchase amount: ");
    scanf("%f", &node->amount);

    node->prev = tail;
    node->next = NULL;

    if (tail != NULL) tail->next = node;
    else head = node;
    tail = node;

    printf("Purchase record added successfully.\n");
}

void searchPurchaseRecord(void) {
    int recordId;
    printf("Enter record id to search: ");
    scanf("%d", &recordId);

    Purchase* p = findPurchaseByRecordId(recordId);
    if (p == NULL) {
        printf("\n  [!] Purchase record not found.\n");
        return;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                 PURCHASE RECORD SEARCH RESULT               |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Record ID    | %-44d |\n", p->recordId);
    printf("  | Customer ID  | %-44d |\n", p->customerId);
    printf("  | Name         | %-44s |\n", p->customerName);
    printf("  | Amount       | %-44.2f |\n", p->amount);
    printf("  +--------------+----------------------------------------------+\n");
}
