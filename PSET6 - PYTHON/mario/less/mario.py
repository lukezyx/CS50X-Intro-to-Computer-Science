from cs50 import get_int

height = 0

while (height <1 or height >8):

    height = get_int("Height: ")

if height >= 1 and height <= 8:

    for i in range(0, height, 1):

        for k in range(height-i-1, 0, -1):
            print(" ", end = "")

        for j in range(0, i+1, 1):
            print("#", end="")

        print()



