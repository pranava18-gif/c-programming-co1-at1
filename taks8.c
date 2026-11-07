
#include <stdio.h>

int main()
{
    int previousReading = 1200;
    int currentReading = 1350;
    int units;

    units = currentReading - previousReading;

    printf("Electricity Billing Report\n");
    printf("Previous Reading: %d\n", previousReading);
    printf("Current Reading: %d\n", currentReading);
    printf("Units Consumed: %d\n", units);

    return 0;
}
