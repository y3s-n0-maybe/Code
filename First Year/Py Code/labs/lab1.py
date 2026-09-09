import math

program = input("Which program do you want to run?: ")

if program == "sum": 
    sum = int(input("Integer: "))
    print("The sum of the first ", sum, " positive integers is ", (sum * (sum+1))/2)

elif program == "area": 
    radius = float(input("Radius: "))
    print("The area of a circle with radius ", radius, " is ", ((radius * 2) * math.pi))

elif program == "time": 
    tofro = input("Conversion  to or from seconds: ")
    if tofro == "to":
        days = int(input("Days: "))
        hours = int(input("Hours: "))
        minutes = int(input("Minutes: "))
        seconds = int(input("Seconds: "))

        print("Total duration in seconds: ", (seconds + (minutes * 60) + (hours * 3600) + (days * 86400)))
    elif tofro == "from":
        duration = int(input("Duration: "))

        days = duration // 86400
        hours = (duration //  3600) - (days * 24)
        minutes = (duration // 60) - ((days * 1440) + (hours * 60))
        seconds = duration - ((days * 86400) + (hours * 3600) + (minutes * 60))

        print(days, " Days, ", hours, " hours, ", minutes, " minutes, ", seconds, " seconds")

    else: print("?")

elif program == "triangle":
    lengths = input("Lengths: ")
    lengths = [int(item) for item in lengths.split()]

    side = (sum(lengths))/2
    sideMinus = [side-x  for x in lengths]
    area = math.sqrt(side * math.prod(sideMinus))

    print("The area of a triangle with side lengths ", lengths[0], ", ", lengths[1], " & ",lengths[2], " is ", area)

elif program == "sort":
    integers = input("Integers: ")
    integers = [int(item) for item in integers.split()]
    integers.sort()
    print(integers)

else: print("whoops")