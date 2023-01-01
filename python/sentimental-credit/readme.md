## Specification

Write a program that prompt the user for a credit card number. Then print the name of the credit card, Example visa, amex, mastercard

## Usage

Your program should behave per the example below.
```
$ python credit.py
Number: 378282246310005
AMEX
```

## Todo 

- [x] Ask user for number
    - [x] Check input  

- [] Check if it is a valid American Express, MasterCard, or Visa card number

    

### How to check if it is a valid number 

understanding how card numbers works

Luhn’s Algorithm
you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!


Breaking down The algorithm. 

3 7 8 2 8 2 2 4 6 3 1 0 0 0 5

1. Multiply by 2 the second to last digit 

(3 * 2) + (8 * 2) + (8 * 2)  + ( 2 * 2) + (6 * 2) + (1 * 2) + (0 * 2) + (5 * 2)

2. sum this result, with the number all the numbers that weren't multiply by 2.

3. Check if the total's last digit is 0 or total modulo 10 is congruent to 0. 


### Implementation 

1. loop in the number's second to second-to-last digit 
    - sum += (number * 2)%

2. loop in remaining numbers  
    - sum += (number * 2)

