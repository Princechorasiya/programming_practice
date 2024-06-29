import random
import pyperclip

array = "{"
for i in range(26):
    array += str(random.randint(0,0))
    array += ","
array += "0}"

# Copy the generated array string to the clipboard
pyperclip.copy(array)
print(array)

