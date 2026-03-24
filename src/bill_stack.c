#include <stdio.h>
#include <string.h>
#include "types.h"
#include "bill_stack.h"

static BillStack bill;

void initBillStack(void) {
    bill.top = 2;
    bill.items[0] = (BillItem){101, "Rice 1kg", 240.00f, 2};
    bill.items[1] = (BillItem){105, "Soap Bar", 150.00f, 3};
    bill.items[2] = (BillItem){104, "Tea Pack", 480.00f, 1};
}

static int isStackEmpty(void) {
    return bill.top == -1;
}

static int isStackFull(void) {
    return bill.top == MAX_STACK - 1;
}

void pushScannedItem(void) {
    if (isStackFull()) {
        printf("Bill stack is full.\n");
        return;
    }

    BillItem item;
    printf("Enter product id: ");
    scanf("%d", &item.productId);
    printf("Enter product name: ");
    scanf(" %49[^\n]", item.productName);
    printf("Enter price: ");
    scanf("%f", &item.price);
    printf("Enter quantity: ");
    scanf("%d", &item.qty);

    bill.top++;
    bill.items[bill.top] = item;
    printf("Item pushed to current bill.\n");
}
