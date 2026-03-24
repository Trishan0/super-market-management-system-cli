#include <stdio.h>
#include <string.h>
#include "types.h"
#include "restock_req_queue.h"

static RestockQueue restockQueue;

void initQueue(void) {
    restockQueue.front = 0;
    restockQueue.rear = 2;

    restockQueue.items[0] = (RestockRequest){101, "Rice 1kg", 20};
    restockQueue.items[1] = (RestockRequest){102, "Milk Powder", 10};
    restockQueue.items[2] = (RestockRequest){104, "Tea Pack", 15};
}

static int isQueueEmpty(void) {
    return restockQueue.front > restockQueue.rear;
}

static int isQueueFull(void) {
    return restockQueue.rear == MAX_QUEUE - 1;
}

void enqueueRestockRequest(void) {
    if (isQueueFull()) {
        printf("Restock request queue is full.\n");
        return;
    }

    RestockRequest r;
    printf("Enter product id: ");
    scanf("%d", &r.productId);
    printf("Enter product name: ");
    scanf(" %49[^\n]", r.productName);
    printf("Enter requested quantity: ");
    scanf("%d", &r.requestedQty);

    restockQueue.rear++;
    restockQueue.items[restockQueue.rear] = r;
    printf("Restock request added successfully.\n");
}

void dequeueRestockRequest(void) {
    if (isQueueEmpty()) {
        printf("No pending restock requests.\n");
        return;
    }

    RestockRequest r = restockQueue.items[restockQueue.front++];
    printf("Processed restock request: ID=%d | Name=%s | Qty=%d\n",
           r.productId, r.productName, r.requestedQty);
}

void frontRestockRequest(void) {
    if (isQueueEmpty()) {
        printf("\n  [!] No pending restock requests.\n");
        return;
    }

    RestockRequest r = restockQueue.items[restockQueue.front];

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                  FRONT RESTOCK REQUEST                      |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Product ID   | %-44d |\n", r.productId);
    printf("  | Product Name | %-44s |\n", r.productName);
    printf("  | Request Qty  | %-44d |\n", r.requestedQty);
    printf("  +--------------+----------------------------------------------+\n");
}
void displayRestockRequests(void) {
    if (isQueueEmpty()) {
        printf("\n  [!] No pending restock requests.\n");
        return;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------------+\n");
    printf("  |                    RESTOCK REQUEST QUEUE TABLE                    |\n");
    printf("  +------------+--------------------------+---------------------------+\n");
    printf("  | Product ID | Product Name             | Requested Quantity        |\n");
    printf("  +------------+--------------------------+---------------------------+\n");

    for (int i = restockQueue.front; i <= restockQueue.rear; i++) {
        printf("  | %-10d | %-24s | %-25d |\n",
               restockQueue.items[i].productId,
               restockQueue.items[i].productName,
               restockQueue.items[i].requestedQty);
    }

    printf("  +------------+--------------------------+---------------------------+\n");
}