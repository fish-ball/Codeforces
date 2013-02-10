from sys import stdin

(hh, mm) = [int(x) for x in stdin.readline().strip().split(':')]

hh %= 12

print(str((hh*60.0+mm)*360/(60*12))+' '+str(mm*6))
