
#include <stdio.h>

int main()
{
    int household_no;
    int previous, current, units;
    float energy_charge, fixed_charge = 50.0, total;

    printf("Enter Household Number: ");
    scanf("%d", &household_no);

    printf("Enter Previous Reading: ");
    scanf("%d", &previous);

    printf("Enter Current Reading: ");
    scanf("%d", &current);

    if (current >= previous)
        units = current - previous;
    else
        units = (65536 - previous) + current;

    if (units <= 100)
        energy_charge = 0;
    else if (units <= 200)
        energy_charge = (units - 100) * 2.25;
    else
        energy_charge = (100 * 2.25) +
                        (units - 200) * 4.50;

    total = fixed_charge + energy_charge;

    printf("\n--- ELECTRICITY BILL ---\n");
    printf("Household Number: %d\n", household_no);
    printf("Units Consumed: %d\n", units);
    printf("Energy Charge: Rs. %.2f\n", energy_charge);
    printf("Fixed Charge: Rs. %.2f\n", fixed_charge);
    printf("Total Bill: Rs. %.2f\n", total);

    return 0;
}
