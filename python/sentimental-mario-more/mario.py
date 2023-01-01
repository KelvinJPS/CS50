# a program that prints out a double half-pyramid of a specified height

def main():
    while True:
        try:
            height = int(input("height:"))
            while height > 8 or height < 1:
                print("height must be an integer betwen 1 and 8")
                height = int(input("height:",))
                break
            break
        except ValueError:
            print("height must be an integer")

    for i in range(1, height + 1):
        # Print spaces
        print(" " * (height - i), end="")
        # Print columns
        print(("#" * i) + "  " + ("#" * i))


if __name__ == "__main__":
    main()    
