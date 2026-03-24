#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "promo_cycle.h"

static Promo* last = NULL;
static Promo* current = NULL;

static Promo* findPromoById(int id, Promo** previous) {
    if (last == NULL) {
        if (previous != NULL) *previous = NULL;
        return NULL;
    }

    Promo* prev = last;
    Promo* cur = last->next;

    do {
        if (cur->id == id) {
            if (previous != NULL) *previous = prev;
            return cur;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != last->next);

    if (previous != NULL) *previous = NULL;
    return NULL;
}

void addPromo(void) {
    Promo* node = (Promo*)malloc(sizeof(Promo));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter promo id: ");
    scanf("%d", &node->id);

    if (findPromoById(node->id, NULL) != NULL) {
        printf("Promo with this ID already exists.\n");
        free(node);
        return;
    }

    printf("Enter promo title: ");
    scanf(" %99[^\n]", node->title);

    if (last == NULL) {
        last = node;
        node->next = node;
        current = node;
    } else {
        node->next = last->next;
        last->next = node;
        last = node;
    }

    printf("Promo added successfully.\n");
}
