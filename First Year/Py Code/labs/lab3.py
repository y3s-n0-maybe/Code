import math
import random as rnd

program = str(input("Program?: "))

def triple_line (n):
    t = round(n/3)
    i = 0
    while i < t:
        print('=' * n)
        i += 1

def doughnut (n):
    t = round(n/3)
    i = 0

    triple_line(n)
    while i < t:
        print('=' * t, ' ' * t, '=' * t)
        i += 0
    triple_line(n)
    

if program == "hyp":
    side_one = int(input("Side one? "))
    side_two = int(input("Side two? "))
    print(math.sqrt(side_two**2 + side_one**2))

elif program == "med":
    numbers = input("Numbers? ")
    numbers = [int(item) for item in numbers.split()]
    for i in range(1, len(numbers)):
        key = numbers[i]
        j = i - 1

        while j >= 0 and key < numbers[j]:
            numbers[j+1] = numbers[j]
            j -= 1
            print(numbers)
        numbers[j+1] = key
        print("for ", numbers)

elif program == "doughnut":
    number = int(input("?: "))
    doughnut(number)

elif program == "centre":
    gaysex = input("String to be centred? ")
    width = int(input("Width (in characters) to be centered within? "))
    leading_spaces = int((width- len(gaysex))/2)
    print(' ' * leading_spaces, gaysex)

elif program == "flip":
    i = 0
    previous = ""
    current = ""
    while i < 1000:
        previous = current

        if rnd.randint(0, 1) == 0: current = "heads"
        else: current == "tails"
        i += 1

        if previous == "heads" and current == "heads":
            print (i)
            break

elif program == "root":
    x = abs(float(input("x?: ")))
    i = 0
    guess = x/2

    while i < 100:
        guess = (guess + (x/guess))/2
        i += 1

    print(guess)

else: print("dumbass")