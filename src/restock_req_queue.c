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