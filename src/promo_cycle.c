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

void displayNextPromo(void) {
    if (last == NULL) {
        printf("\n  [!] No promos available.\n");
        return;
    }

    if (current == NULL) {
        current = last->next;
    } else {
        current = current->next;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                     NEXT ACTIVE PROMO                       |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Promo ID     | %-44d |\n", current->id);
    printf("  | Title        | %-44s |\n", current->title);
    printf("  +--------------+----------------------------------------------+\n");
}

void displayAllPromos(void) {
    if (last == NULL) {
        printf("\n  [!] No promos available.\n");
        return;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------------+\n");
    printf("  |                    PROMOTIONAL BANNER TABLE                       |\n");
    printf("  +----------+--------------------------------------------------------+\n");
    printf("  | Promo ID | Title                                                  |\n");
    printf("  +----------+--------------------------------------------------------+\n");

    Promo* cur = last->next;
    do {
        printf("  | %-8d | %-54s |\n",
               cur->id,
               cur->title);
        cur = cur->next;
    } while (cur != last->next);

    printf("  +----------+--------------------------------------------------------+\n");
}

void searchPromo(void) {
    int id;
    printf("Enter promo id to search: ");
    scanf("%d", &id);

    Promo* promo = findPromoById(id, NULL);
    if (promo == NULL) {
        printf("\n  [!] Promo not found.\n");
        return;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                    PROMO SEARCH RESULT                      |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Promo ID     | %-44d |\n", promo->id);
    printf("  | Title        | %-44s |\n", promo->title);
    printf("  +--------------+----------------------------------------------+\n");
}

void updatePromo(void) {
    int id;
    printf("Enter promo id to update: ");
    scanf("%d", &id);

    Promo* promo = findPromoById(id, NULL);
    if (promo == NULL) {
        printf("Promo not found.\n");
        return;
    }

    printf("Enter new promo title: ");
    scanf(" %99[^\n]", promo->title);
    printf("Promo updated successfully.\n");
}

void deletePromo(void) {
    int id;
    printf("Enter promo id to delete: ");
    scanf("%d", &id);

    Promo* prev = NULL;
    Promo* node = findPromoById(id, &prev);

    if (node == NULL) {
        printf("Promo not found.\n");
        return;
    }

    if (node == last && node == last->next) {
        free(node);
        last = NULL;
        current = NULL;
    } else {
        prev->next = node->next;
        if (node == last) last = prev;
        if (current == node) current = node->next;
        free(node);
    }

    printf("Promo deleted successfully.\n");
}
