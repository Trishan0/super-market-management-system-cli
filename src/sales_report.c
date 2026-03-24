#include <stdio.h>
#include "types.h"
#include "sales_report.h"

static SaleRecord sales[MAX_SALES];
static int salesCount = 0;

void initSales(void) {
    salesCount = 5;
    sales[0] = (SaleRecord){1, 24500.00f};
    sales[1] = (SaleRecord){2, 19800.00f};
    sales[2] = (SaleRecord){3, 22150.00f};
    sales[3] = (SaleRecord){4, 28700.00f};
    sales[4] = (SaleRecord){5, 17600.00f};
}

void addSalesRecord(void) {
    if (salesCount >= MAX_SALES) {
        printf("Sales storage is full.\n");
        return;
    }

    printf("Enter day number: ");
    scanf("%d", &sales[salesCount].day);
    printf("Enter sales amount: ");
    scanf("%f", &sales[salesCount].amount);
    salesCount++;

    printf("Sales record added successfully.\n");
}

static int searchSalesIndexByDay(int day) {
    for (int i = 0; i < salesCount; i++) {
        if (sales[i].day == day) return i;
    }
    return -1;
}

void searchSalesRecord(void) {
    int day;
    printf("Enter day number to search: ");
    scanf("%d", &day);

    int index = searchSalesIndexByDay(day);
    if (index == -1) {
        printf("\n  [!] Sales record not found.\n");
        return;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                  SALES RECORD SEARCH RESULT                 |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Day Number   | %-44d |\n", sales[index].day);
    printf("  | Amount       | %-44.2f |\n", sales[index].amount);
    printf("  +--------------+----------------------------------------------+\n");
}

void updateSalesRecord(void) {
    int day;
    printf("Enter day number to update: ");
    scanf("%d", &day);

    int index = searchSalesIndexByDay(day);
    if (index == -1) {
        printf("Sales record not found.\n");
        return;
    }

    printf("Enter new sales amount: ");
    scanf("%f", &sales[index].amount);
    printf("Sales record updated successfully.\n");
}

void deleteSalesRecord(void) {
    int day;
    printf("Enter day number to delete: ");
    scanf("%d", &day);

    int index = searchSalesIndexByDay(day);
    if (index == -1) {
        printf("Sales record not found.\n");
        return;
    }

    for (int i = index; i < salesCount - 1; i++) {
        sales[i] = sales[i + 1];
    }
    salesCount--;

    printf("Sales record deleted successfully.\n");
}

void displaySalesRecords(void) {
    if (salesCount == 0) {
        printf("\n  [!] No sales records available.\n");
        return;
    }

    printf("\n");
    printf("  +---------------------------------------------------+\n");
    printf("  |                  SALES REPORT TABLE               |\n");
    printf("  +------------+--------------------------------------+\n");
    printf("  | Day Number | Sales Amount                         |\n");
    printf("  +------------+--------------------------------------+\n");

    for (int i = 0; i < salesCount; i++) {
        printf("  | %-10d | %-36.2f |\n",
               sales[i].day,
               sales[i].amount);
    }

    printf("  +------------+--------------------------------------+\n");
}
void totalDailySales(void) {
    float total = 0.0f;
    for (int i = 0; i < salesCount; i++) {
        total += sales[i].amount;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                    SALES TOTAL SUMMARY                      |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Total Sales  | %-44.2f |\n", total);
    printf("  +--------------+----------------------------------------------+\n");
}

void averageSales(void) {
    if (salesCount == 0) {
        printf("\n  [!] No sales records available.\n");
        return;
    }

    float total = 0.0f;
    for (int i = 0; i < salesCount; i++) {
        total += sales[i].amount;
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                   AVERAGE SALES SUMMARY                     |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Average      | %-44.2f |\n", total / salesCount);
    printf("  +--------------+----------------------------------------------+\n");
}

void highestSaleDay(void) {
    if (salesCount == 0) {
        printf("\n  [!] No sales records available.\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < salesCount; i++) {
        if (sales[i].amount > sales[maxIndex].amount) {
            maxIndex = i;
        }
    }

    printf("\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("  |                    HIGHEST SALE DAY                         |\n");
    printf("  +--------------+----------------------------------------------+\n");
    printf("  | Day Number   | %-44d |\n", sales[maxIndex].day);
    printf("  | Amount       | %-44.2f |\n", sales[maxIndex].amount);
    printf("  +--------------+----------------------------------------------+\n");
}