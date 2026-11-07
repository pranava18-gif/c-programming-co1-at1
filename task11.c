
#include <stdio.h>
#include <limits.h>

unsigned int calculateUnits(unsigned short previous,
                            unsigned short current)
{
    if (current >= previous)
        return current - previous;

    return (unsigned int)USHRT_MAX - previous + 1 + current;
}

long long calculateBill(unsigned int units,
                        int slab1, int slab2,
                        int rate1, int rate2,
                        int rate3, int fixedCharge)
{
    long long bill = fixedCharge;

    if (units <= (unsigned int)slab1)
        bill += (long long)units * rate1;

    else if (units <= (unsigned int)slab2)
        bill += (long long)slab1 * rate1
              + (long long)(units - slab1) * rate2;

    else
        bill += (long long)slab1 * rate1
              + (long long)(slab2 - slab1) * rate2
              + (long long)(units - slab2) * rate3;

    return bill;
}

int main()
{
    FILE *file;

    int slab1, slab2;
    int rate1, rate2, rate3, fixedCharge;

    unsigned short previous, current;
    unsigned int units;
    long long bill;

    file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Tariff file not found!\n");
        return 1;
    }

    if (fscanf(file, "%d%d%d%d%d%d",
               &slab1, &slab2, &rate1,
               &rate2, &rate3, &fixedCharge) != 6)
    {
        printf("Invalid tariff file!\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    if (slab1 < 0 || slab2 <= slab1 ||
        rate1 < 0 || rate2 < 0 ||
        rate3 < 0 || fixedCharge < 0)
    {
        printf("Invalid tariff values!\n");
        return 1;
    }

    printf("===== ELECTRICITY BILLING SYSTEM =====\n");

    printf("Enter previous meter reading: ");
    if (scanf("%hu", &previous) != 1)
        return 1;

    printf("Enter current meter reading: ");
    if (scanf("%hu", &current) != 1)
        return 1;

    units = calculateUnits(previous, current);

    bill = calculateBill(units, slab1, slab2,
                         rate1, rate2, rate3,
                         fixedCharge);

    printf("\n===== BILL REPORT =====\n");
    printf("Previous Reading: %hu\n", previous);
    printf("Current Reading: %hu\n", current);
    printf("Units Consumed: %u\n", units);

    printf("Total Bill: Rs. %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
