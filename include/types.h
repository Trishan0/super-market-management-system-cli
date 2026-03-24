#ifndef TYPES_H
#define TYPES_H
#define NAME_LEN 50

#define MAX_STACK 100

typedef struct {
    int productId;
    char productName[NAME_LEN];
    float price;
    int qty;
} BillItem;

typedef struct {
    BillItem items[MAX_STACK];
    int top;
} BillStack;

#endif