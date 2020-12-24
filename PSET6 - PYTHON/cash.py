from cs50 import get_float


cash = 0.00
counter = 0

pennies = 1
nickels = 5
dime = 10
quarters = 25

while (cash <= 0):

    cash = get_float("Change owed: ")
    
cash = cash *100
    
while (cash >= quarters):

    cash -= quarters
    counter += 1

while (cash >= dime):

    cash -= dime
    counter += 1

while (cash >= nickels):

    cash -= nickels
    counter += 1

while (cash >= pennies):

    cash -= pennies
    counter += 1

print(counter)