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