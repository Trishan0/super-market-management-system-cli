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