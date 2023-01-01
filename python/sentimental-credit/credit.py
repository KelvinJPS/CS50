# A Program that checks if a number is a valid credit card number
import re
def main():
    # Ask user for a credit card number  
    while True:
        card_number = input("Number:")
        if(card_number.isdigit()):
            break

    check_credit_card(card_number)

def checksum(card_number):
    sum = 0
    # number’s second-to-last digit
    for i in reversed(range(1,len(card_number),2)):
        n = int(card_number[i]) * 2
        sum += (n // 10 ) + (n % 10)
    # remaining numbers 
    for i in range(0,len(card_number),2):
        sum += int(card_number[i])
    return sum % 10 == 0


def check_credit_card(card_number): 
    if checksum(card_number):
        if re.match('[34]|[37]', card_number) != None:
            print("AMEX")
        elif re.match('[51-57]', card_number) != None:
            print("MASTERCARD")

        elif re.match('4', card_number) != None :
            print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
