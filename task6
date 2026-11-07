
#include <stdio.h>

int main()
{
    int consumerID;
    int previousReading, currentReading;
    int units;
    long billPaise;

    printf("Enter Consumer ID: ");
    if (scanf("%d", &consumerID) != 1)
    {
        printf("Invalid Consumer ID!\n");
        return 1;
    }

    printf("Enter Previous Reading: ");
    if (scanf("%d", &previousReading) != 1)
    {
        printf("Invalid Previous Reading!\n");
        return 1;
    }

    printf("Enter Current Reading: ");
    if (scanf("%d", &currentReading) != 1)
    {
        printf("Invalid Current Reading!\n");
        return 1;
    }

    if (previousReading < 0 || currentReading < 0 ||
        currentReading < previousReading)
    {
        printf("Invalid meter readings!\n");
        return 1;
    }

    units = currentReading - previousReading;

    billPaise = 5000;

    if (units > 200)
        billPaise += (long)(units - 200) * 450;

    if (units > 100)
    {
        int slab2 = units > 200 ? 200 : units;
        billPaise += (long)(slab2 - 100) * 225;
    }

    printf("\n----- ELECTRICITY BILL -----\n");
    printf("Consumer ID: %d\n", consumerID);
    printf("Units Consumed: %d\n", units);
    printf("Bill Amount: Rs. %ld.%02ld\n",
           billPaise / 100, billPaise % 100);

    return 0;
}
