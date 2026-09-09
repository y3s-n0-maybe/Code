import math

n = int(1)

program = input("Which program do you want to run?: ")

def factorial(num):
    rangenum = range(1, num+1)
    for i in rangenum: num * i
    return(math.prod(rangenum))

if program == "odd":
    n = int(input("Number: "))
    if n % 2 == 0: print("Even")
    else: print("Odd")

elif program == "dog":
    n = int(input("How many human years? "))
    if n == 1: print("10.5")
    else: print(((n-2)*4)+21)

elif program == "roots":
    a = int(input("Non-Zero a: "))
    b = int(input("b: "))
    c = int(input("c: "))
    d = (b^2) - (4*a*c)

    if (d < 0 ): print("No real roots")
    else:
        rootPlus = (-b + math.sqrt(d))/(2*a)
        rootMinus = (-b - math.sqrt(d))/(2*a)
        if (rootPlus == rootMinus): print("1 root: ", rootPlus)
        else: 
            print(rootPlus)
            print(rootMinus)
    
elif program == "factorial":
    n = int(input("Integer: "))
    print(factorial(n))

elif program == "factors":
    factors = []
    while (n < 100):
        n += 1
        for i in range(2, n): 
            if (n % i == 0): 
                factors.append(i)
        print(n, " : ", factors)

elif program == "ex":
    x = float(input("? "))
    k = 0
    listsf= []
    while(k < 101):
        d = factorial(k)

        a = math.pow(x,k)
        n = a/d

        listsf.append(n)
        k += 1

    print(sum(listsf))

else: print("program unrecognised")