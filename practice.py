import os

def menu():
    selecting = True
    while (selecting):
        choice = input("Please select an option: ")
        if (choice == "1"):
            print(1)
        elif (choice == "2"):
            print(2)
        elif (choice == "3"):
            print(3)
        elif (choice == "q"):
            print("Quitting")
            selecting = False
        else:
            print("Wrong input")

def main():
    menu()

if __name__ == "__main__":
    main()