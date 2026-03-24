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