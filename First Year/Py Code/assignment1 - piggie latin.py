# This program translates a string into pig latin. Created by Lexi Venner on 05/11/2025

def pig_latin(latin):
    vowels = ("A", "E", "I", "O", "U", "a", "e", "i", "o", "u")
    punctuation = ("!", ",", "?", ":", ";", ".")
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
    return translated