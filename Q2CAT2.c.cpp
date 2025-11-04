#include <stdio.h>
/*
NAME: ARNOLD OBAGA
REG NO: PA106/G/28787/25
DESCRIPTION: This program calculates the gross pay, taxes, and net pay for an employee based on hours worked and hourly wage.
*/

int main() {
    float hours, rate, grossPay, tax, netPay;

    // Input from user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    // Calculate gross pay
    if (hours <= 40) {
        grossPay = hours * rate;
    } else {
        float overtimeHours = hours - 40;
        grossPay = (40 * rate) + (overtimeHours * rate * 1.5);
    }

    // Calculate taxes
    if (grossPay <= 600) {
        tax = 0.15 * grossPay;
    } else {
        tax = (0.15 * 600) + (0.20 * (grossPay - 600));
    }

    // Calculate net pay
    netPay = grossPay - tax;

    // Output results
    printf("\nGross Pay: $%.2f\n", grossPay);
    printf("Taxes: $%.2f\n", tax);
    printf("Net Pay: $%.2f\n", netPay);

    return 0;
}