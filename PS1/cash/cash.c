#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents = 0;

    do 
    { 
        cents = get_int("how many cents?: ");

    }
    while (cents < 1);

    return cents;
}

int calculate_quarters(int cents)
{
    int  quarters = 0;
    const int QUARTER = 25;
    while (cents - QUARTER  >= 0) 
    {
        quarters += 1; 
        cents = cents - QUARTER;
    }

    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    const int DIME = 10;

    while (cents - DIME >= 0)
    {
        dimes += 1;
        cents = cents - DIME;
    }

    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    const int NICKEL = 5;

    while (cents - NICKEL >= 0)
    {
        nickels += 1;
        cents = cents - NICKEL;
    }
    
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    const int PENNY = 1; 

    while (cents - 1 >= 0)
    {
        pennies += 1;
        cents = cents - PENNY;
    }
    return pennies;
}
