import random as rnd

sequence = []
count = 0
total = 0


while(count < 2):
    if rnd.randint(0, 1) == 0:
        count += 1
        sequence.append("T")
    else:
        count = 0
        sequence.append("H")
    total += 1
print(sequence)
print(total)