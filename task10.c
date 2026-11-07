
#include <stdio.h>

int main()
{
    int households[] = {4000, 60000, 800000};

    float bill = 10.10f;
    long long billPaise = 1010;

    for (int i = 0; i < 3; i++)
    {
        float floatTotal = households[i] * bill;
        long long paiseTotal = households[i] * billPaise;

        printf("\nHouseholds: %d\n", households[i]);

        printf("Float Total: Rs. %.2f\n", floatTotal);

        printf("Integer Paise Total: Rs. %lld.%02lld\n",
               paiseTotal / 100, paiseTotal % 100);
    }

    return 0;
}
