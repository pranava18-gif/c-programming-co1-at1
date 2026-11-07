
#include <stdio.h>

int main()
{
    float bill1 = 162.50;
    float bill2 = 250.75;

    int paise1 = 16250;
    int paise2 = 25075;

    printf("Using Float:\n");
    printf("Total Bill = Rs. %.2f\n", bill1 + bill2);

    printf("\nUsing Integer Paise:\n");
    printf("Total Bill = Rs. %d.%02d\n",
           (paise1 + paise2) / 100,
           (paise1 + paise2) % 100);

    return 0;
}
