#0.0588 * L - 0.296 * S - 15.8

from cs50 import get_string


text = get_string("Text: ")

letter_count = 0
space_count = 1
sentence_count = 0

for x in text:
    if x.isspace():
        space_count += 1
    if x.isalpha():
        letter_count += 1
    elif x == '.' or x == '?' or x == '!':
        sentence_count += 1


#print(f"letter count: {letter_count}")
#print(f"space count: {space_count}")
#print(f"sentence count: {sentence_count}\n")


#declaring coleman-liau
l = letter_count / space_count * 100
s = sentence_count / space_count * 100

#print(f"l = {l}, s = {s}\n")

eqn = round(0.0588 * l - 0.296 * s - 15.8)

#print(f"eqn = {eqn}")

if eqn < 1:
    print("Before Grade 1")
elif eqn > 16:
    print("Grade 16+")
else:
    print(f"Grade {eqn}")
