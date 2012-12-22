from sys import stdin, stdout

stdin = open("input.txt","r")
stdout = open("output.txt","w")

(b, g) = [int(x) for x in stdin.readline().strip().split()]

gender = b > g

while b + g > 0:
    if gender:
        if b > 0:
            b -= 1
            stdout.write('B')
    else:
        if g > 0:
            g -= 1
            stdout.write('G')
    gender = not gender

print('')
