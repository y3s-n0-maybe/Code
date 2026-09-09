program = input("? ")

if program == "tri":
    b = float(input("base? "))
    h = float(input("height? "))
    print((b * h)/2)

elif program == "diag":
    n = int(input("n? "))
    for i in range(n+1):
        print(" " * i, "x")

elif program == "count":
    vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"]
    counter = 0

    s = input("String? ")

    for char in s:
        if (char in vowels):
            counter += 1
    print(counter)

elif program == "union":
    lst1 = input("list one: ")
    lst1 = lst1.split(" ")

    lst2 = input("list two: ")
    lst2 = lst2.split(" ")
    
    final_list = []
    twodeearray = [lst1, lst2]
    
    for list in twodeearray:
        for item in list:
            if item in final_list:
                pass
            else:
                final_list.append(item)
    print(final_list)
