
#include <stdio.h>
#include "billing.h"

int main()
{
    int units;
    long bill;

    printf("Enter Electricity Units: ");
    scanf("%d", &units);

    bill = compute_bill(units);

    printf("Electricity Units: %d\n", units);
    printf("Total Bill: Rs. %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units < 0)
        return -1;

    if (units > SLAB2_UNITS)
    {
        paise += (long)(units - SLAB2_UNITS)
                 * RATE3_PAISE;
        units = SLAB2_UNITS;
    }

    if (units > SLAB1_UNITS)
    {
        paise += (long)(units - SLAB1_UNITS)
                 * RATE2_PAISE;
        units = SLAB1_UNITS;
    }

    paise += (long)units * RATE1_PAISE;

    return paise;
}
