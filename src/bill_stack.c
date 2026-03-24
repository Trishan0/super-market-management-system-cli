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
void popLastItem(void) {
    if (isStackEmpty()) {
        printf("Bill stack is empty.\n");
        return;
    }

    BillItem item = bill.items[bill.top--];
    printf("Last item removed: ID=%d | Name=%s | Price=%.2f | Qty=%d\n",
           item.productId, item.productName, item.price, item.qty);
}

void peekLatestItem(void) {
    if (isStackEmpty()) {
        printf("\n  [!] Bill stack is empty.\n");
        return;
    }

    BillItem item = bill.items[bill.top];

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                    LATEST BILL ITEM                         |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Product ID   | %-44d |\n", item.productId);
    printf("  | Product Name | %-44s |\n", item.productName);
    printf("  | Price        | %-44.2f |\n", item.price);
    printf("  | Quantity     | %-44d |\n", item.qty);
    printf("  +--------------+----------------------------------------------+\n");
}
