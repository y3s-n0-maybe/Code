import random as rnd

program = input("? ")

if program == "word":
    sentence = input("Sentence? ")
    count = sentence.count(" ") + 1
    print(count)

elif program == "coin":
    coinflip = ""
    coinflip_last = "0"
    coinflip_list = []

    while not(coinflip == coinflip_last and coinflip == "T"):
        coinflip_last = coinflip
        if rnd.randint(0, 1) == 1:
            coinflip = "T"
        else:
            coinflip = "H"
        print(coinflip)
        coinflip_list.append(coinflip)
    print(coinflip_list, "(", len(coinflip_list), " flips)")

elif program == "triangle":
    current_list = []
    previous_list = [1]
    n = int(input("n? "))

    for i in range(n):

        previous_list.append(0)
        previous_list.insert(0, 0)

        for x in range(len(previous_list)-1):
            piss = previous_list[x] + previous_list[x+1]
            current_list.append(piss)
        
        for item in current_list:
            print(item, end = " ")
        print("")

        previous_list.clear()

        for item in current_list:
            previous_list.append(item)
        
        current_list.clear()
        