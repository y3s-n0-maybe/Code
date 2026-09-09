# Code for Assignment 1
# Created by Lexi Venner 26/11/25

# Converts a given number in years into dog years
def dog_years(y): 
    if y == 1: return(10.5)
    else: return(((y-2)*4)+21)

# Prints a doughnut of width & length n to the screen
def doughnut (n):
    t = round(n/3)

    for i in range(t):
        print('=' * n)
    
    for i in range(t):
        print('=' * t, ' ' * t, '=' * t)

    for i in range(t):
        print('=' * n)

# Removes the first & last n values from a list
def trim_extremes(lst, n):
    lst.sort()
    for i in range(n):
        lst.pop(0)
        lst.pop()
    return(lst)


# Translates a number n to english. For example 124 to one hundred and twenty four
def to_english(n):

    hundreds = n // 100
    residue = n % 100
    tens = residue // 10
    ones = residue % 10

    one_to_one = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    one_to_tens = ["twenty",  "thirty",  "fourty",  "fifty",  "sixty",  "seventy",  "eighty",  "ninety"]

    onesstr = ""
    tensstr= ""
    hundredsstr = ""

    if tens == 1: tensstr = one_to_one[(10 * tens) + ones -1]
    elif ones != 0: onesstr = one_to_one[ones-1]

    if tens > 1: tensstr = one_to_tens[tens-2] + " " 

    if hundreds != 0: 
        hundredsstr = str(one_to_one[hundreds-1]) + " hundred"
        if residue != 0:
            hundredsstr += " and "

    return(hundredsstr + tensstr + onesstr)

# Returns the list of values that were higher than all previous values
def peaks(lst):
    outputlist = []
    maxitem = 0

    for item in lst:
        if item > maxitem:
            maxitem = item
            outputlist.append(item)
    return(outputlist)