from sys import stdin

a = max([int(x) for x in stdin.readline().strip().split()])

if a == 6: print('1/6')
elif a == 5: print('1/3')
elif a == 4: print('1/2')
elif a == 3: print('2/3')
elif a == 2: print('5/6')
else: print('1/1')
