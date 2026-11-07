
#include <stdio.h>

#define FIXED_CHARGE 5000
#define SLAB1 100
#define SLAB2 200
#define RATE1 0
#define RATE2 225
#define RATE3 450

long calculateBill(int units)
{
    long bill = FIXED_CHARGE;

    if (units < 0)
        return -1;

    if (units <= SLAB1)
        bill += (long)units * RATE1;

    else if (units <= SLAB2)
        bill += (long)SLAB1 * RATE1
              + (long)(units - SLAB1) * RATE2;

    else
        bill += (long)SLAB1 * RATE1
              + (long)(SLAB2 - SLAB1) * RATE2
              + (long)(units - SLAB2) * RATE3;

    return bill;
}

int main()
{
    int previous[5], current[5], units[5];
    long bill[5], total = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("\nHousehold %d\n", i + 1);

        printf("Enter previous reading: ");
        if (scanf("%d", &previous[i]) != 1)
            return 1;

        printf("Enter current reading: ");
        if (scanf("%d", &current[i]) != 1)
            return 1;

        if (previous[i] < 0 || current[i] < previous[i])
        {
            printf("Invalid meter reading!\n");
            return 1;
        }

        units[i] = current[i] - previous[i];
        bill[i] = calculateBill(units[i]);

        total += bill[i];
    }

    printf("\n===== ELECTRICITY BILL REPORT =====\n");

    for (int i = 0; i < 5; i++)
    {
        printf("House %d: %d units - Rs. %ld.%02ld\n",
               i + 1, units[i], bill[i] / 100, bill[i] % 100);
    }

    printf("\nTotal Collection: Rs. %ld.%02ld\n",
           total / 100, total % 100);

    return 0;
}
