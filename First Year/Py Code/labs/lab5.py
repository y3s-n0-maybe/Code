

program = input("What program do you want to run? ")

if program == "tran":
    n = int(input("Integer < 1000: "))

    hundreds = n // 100
    residue = n % 100
    tens = residue // 10
    ones = residue % 10

    one_to_one = ["One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
    one_to_tens = ["Ten", "Twenty",  "Thirty",  "Fourty",  "Fifty",  "Sixty",  "Seventy",  "Eighty",  "Ninety"]


    onesstr = ""
    tensstr= ""
    hundredsstr = ""

    if ones != 0: onesstr = one_to_one[ones-1]
    if tens != 0: tensstr = one_to_tens[tens-1]
    if hundreds != 0: hundredsstr = str(one_to_one[hundreds-1]) + " hundred"

    print(hundredsstr, tensstr, onesstr)

elif program == "pali":
    s = input("Is palindrome? ")
    s = s.lower()
    s = s.replace(" ", "").replace(",", "")
    reverseds = s[::-1]
    if reverseds == s: print("True")
    else: print("False")

elif program == "peak":
    inputlist = (input("List? "))
    inputlist = [int(item) for item in inputlist.split()]
    outputlist = []
    maxitem = 0

    for item in inputlist:
        if item > maxitem:
            maxitem = item
            outputlist.append(item)
    print(outputlist)