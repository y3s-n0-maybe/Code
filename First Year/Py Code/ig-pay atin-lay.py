latin = "Jingle bells, jingle bells! Jingle all the way!! Oh, what fun it is to ride In a one horse open sleigh."
vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u", "Y", "y"]
punctuation = ["!", ",", "?", ":", ";", "."]
latin = latin.split(" ")

end_string = ""
translated = ""

for word in latin:
    punc_str = ""
    afterstrophe = ""
    consonants = 0
    capitalised = 0

    if word[0] > "A" and word[0] < "Z":
        capitalised = 1
        word = word.lower()

    for letter in word:
        if letter == "'":
            afterstrophe = word[word.index(letter):]
            word = word.replace(afterstrophe, "")

    for letter in word:
        if letter in punctuation:
            punc_str = punc_str + letter
            word = word.replace(letter, "", 1)

    for letter in word:
        if letter not in vowels: consonants += 1
        else: break

    if consonants != 0:
        end_string = word[:consonants]
        word = word[consonants:] + "-" + end_string + "ay"
    else: 
        word = word + "-way"

    if capitalised == 1:
        word = word.capitalize()

    translated = translated + " " + word + afterstrophe + punc_str

print(translated)