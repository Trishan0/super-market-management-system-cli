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

typedef struct Promo {
    int id;
    char title[DESC_LEN];
    struct Promo* next;
} Promo;

typedef struct Purchase {
    int recordId;
    int customerId;
    char customerName[NAME_LEN];
    float amount;
    struct Purchase* prev;
    struct Purchase* next;
} Purchase;