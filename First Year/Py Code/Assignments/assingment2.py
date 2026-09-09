# Code for Assignment 2
# Created by Lexi Venner 26/11/25

import random as rnd
import string

# looks through a dictionary and returns all keys that match a given value
def reverse_lookup(d, v):
    output = []
    for key in d:
        if d[key] == v:
            output.append(key)
    return output

# simulates a 2d6 roll
def dice_roll():
    return (rnd.randint(1, 6) + rnd.randint(1, 6))

# simulates n 2d6s
def many_dice_rolls(n):
    rolls = {2 : 0, 3 : 0, 4 : 0, 5 : 0, 6 : 0, 7 : 0, 8 : 0, 9 : 0, 10 : 0, 11 : 0, 12 : 0}

    for i in range(n):
        rolls[dice_roll()] += (100/n)
    
    for key in rolls:
        print(str(key) + ": " + str(round(rolls[key])) + "%")

# prints the first 10 lines of a file
def head(fname):
    with open(fname) as file:
        contents = file.read()

        j = 0
        i = 0

        while j < 10:
            if contents[i:i+1] == "\n": 
                j += 1
            if j == 10:
                contents = contents[:i]
            i += 1
    print(contents)


# finds the average word length of a file
def word_length(fname):
    with open(fname) as file:
        contents = file.read()

    contents = contents.strip(string.punctuation)
    contents = contents.split()
    listicle = []

    for item in contents:
        listicle.append(len(item))

    return(sum(listicle)/len(listicle))

many_dice_rolls(100)