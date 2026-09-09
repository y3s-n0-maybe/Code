import random as rnd

b = False
while (b != True):
    upperBound = int(input("Upper bound? "))
    lowerBound = int(input("Lower bound? "))
    length = int(input("length? "))

    if upperBound <= lowerBound: print("upperBound <= lowerBound")
    elif length >= (upperBound - lowerBound): print("length >= range")
    else: b = True

lotto = []
i = 0

while(i < length):
    item = rnd.randint(lowerBound, upperBound)
    if(item not in lotto):
        lotto.append(item)
        i += 1

lotto.sort()
print(lotto)