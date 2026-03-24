#ifndef TYPES_H
#define TYPES_H

#define MAX_PRODUCTS 200
#define MAX_SALES 200
#define MAX_QUEUE 100
#define MAX_STACK 100
#define NAME_LEN 50
#define DESC_LEN 100

typedef struct Promo {
    int id;
    char title[DESC_LEN];
    struct Promo* next;
} Promo;