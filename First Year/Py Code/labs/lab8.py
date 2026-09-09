import string

program = input("Program? ")

filename = input("Filename? ")
dir = "C:\\Users\\Owner\\Desktop\\Code\\Py Code\\" + filename
dir_head = "C:\\Users\\Owner\\Desktop\\Code\\Py Code\\head_" + filename

with open(dir) as file:
    contents = file.read()


if program == "head":
    j = 0
    i = 0

    while j < 10:
        if contents[i:i+1] == "\n": 
            j += 1
        if j == 10:
            contents = contents[:i]
        i += 1

    print(contents)

    f = open(dir_head, "w")
    f.write(contents)
    f.close()

elif program == "word":
    contents = contents.strip(string.punctuation)
    contents = contents.split()
    listicle = []

    for item in contents:
        listicle.append(len(item))

    print(sum(listicle)/len(listicle))
