
# Program 
text = input("text:")
words = len(text.split())
letters = 0
sentences = 0


for i in range(len(text)):
    if text[i].isalpha():
        letters += 1


for i in range(len(text)):
    if text[i] == "." or text[i] == "?" or text[i] == "!":
        sentences += 1

avg_l = letters / words * 100
avg_s = sentences / words * 100
index = 0.0588 * avg_l - 0.296 * avg_s - 15.8


if index > 16:
    print("Grade 16+")

elif index < 1: 
    print("Before Grade 1")

else:
    print(f"Grade {round(index)}")

