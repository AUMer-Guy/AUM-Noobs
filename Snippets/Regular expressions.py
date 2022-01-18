#Regular expressions

import re

file = open('email.txt')

for line in file:
    line = line.strip()
    y = re.findall('K+.*t', line)
    if(len(y)>0):
        print(line)