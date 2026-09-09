import re

program = input("Which? ")

if program == "vwls":
    input = input("string? ")
    print(re.sub("[aeiou]", "", input))

elif program == "vwls2":
    input = input("string?")
    vowels = ["a", "e", "i", "o", "u"]
    for letter in vowels:
        input = input.replace(letter, "")
    print(input)

elif program == "split":
    input = input("string? ")
    input = input.split(" ")
    input = [word.capitalize() for word in input]
    print(input)

elif program == "scrab":
    input = input("string? ")
    regexes = ["[aeilnorstu]", "[dg]", "[bcmp]", "[fhvwy]", "[k]", "[jx]","[qz]"]

    i = 1
    output = 0

    for item in regexes:
        output += i * len(re.findall((item), input))
        if i == 5: i += 3
        elif i == 8: i+= 2
        else: i += 1
    print (output)
    
elif program == "list":
    inpup = input("list of integers? ")
    inpup = inpup.split()
    inpup.sort()

    n = int(input("n? "))
    i = 0

    while i < n:
        inpup.pop(0)
        inpup.pop()
        i+= 1 
    print(inpup)

elif program == "perf":
    n = int(input("int? "))
    i = 1
    listie = []

    while i < n:
        if (n % i == 0):
            listie.append(i)
        i += 1
    
    print(listie)
    if sum(listie) == n: print("Perfect!!!")
    else: print("filthy digusting")
    
else: print("dumbass")