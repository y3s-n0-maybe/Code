import random as rnd

d = {"one": 1, "two": 2, "three": 3, "eins": 1, "uno": 1, "deux": 2, "trois": 3, "four": 4, "zwei": 2}
rolls = {1 : 0, 2 : 0, 3 : 0, 4 : 0, 5 : 0, 6 : 0, 7 : 0, 8 : 0, 9 : 0, 10 : 0, 11 : 0, 12 : 0}

program = input("? ")

def reverse_lookup(thisdict, v):
    output = []
    for key in thisdict:
        if thisdict[key] == v:
            output.append(key)
    return output

def dice_roll():
    return (rnd.randint(1, 6) + rnd.randint(1, 6))

if program == "revd":
    v = int(input("v? "))
    print(reverse_lookup(d, v))

elif program == "why":
    string = input("String? ")
    dictionary = {}

    for letter in string: 
        if letter not in dictionary:
            dictionary[letter] = 1
        else: dictionary[letter] += 1

    print(len(dictionary))

elif program == "roll":
    n = int(input("How many times? "))
    for i in range(n):
        rolls[dice_roll()] += 1
    print(rolls)