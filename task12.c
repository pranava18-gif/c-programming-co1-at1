
#include <stdio.h>

int main()
{
    unsigned long long normalWh, peakWh;
    unsigned long long totalWh;

    int normalRate, peakRate;
    long long billPaise;

    FILE *file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Tariff file not found!\n");
        return 1;
    }

    if (fscanf(file, "%d%d", &normalRate, &peakRate) != 2)
    {
        printf("Invalid tariff file!\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    if (normalRate < 0 || peakRate < 0)
    {
        printf("Invalid tariff values!\n");
        return 1;
    }

    printf("Enter normal-period consumption in Wh: ");
    if (scanf("%llu", &normalWh) != 1)
        return 1;

    printf("Enter peak-period consumption in Wh: ");
    if (scanf("%llu", &peakWh) != 1)
        return 1;

    totalWh = normalWh + peakWh;

    billPaise =
        ((long long)normalWh * normalRate +
         (long long)peakWh * peakRate) / 1000;

    printf("\n===== SMART METER BILL =====\n");

    printf("Normal Consumption: %llu Wh\n", normalWh);
    printf("Peak Consumption: %llu Wh\n", peakWh);
    printf("Total Consumption: %llu Wh\n", totalWh);

    printf("Total Bill: Rs. %lld.%02lld\n",
           billPaise / 100, billPaise % 100);

    return 0;
}
