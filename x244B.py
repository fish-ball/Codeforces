def cnt(s, p):
    ans = 0
    if p > s: ans = 0
    elif len(p) == len(s): ans = 1
    elif len(set(p.lstrip('0'))) > 2: ans = 0
    elif s[:len(p)] > p:
        if set(p.lstrip('0')) == 2: ans = 2**(len(s)-len(p))
        elif set(p.lstrip('0')) == 1: ans = 1 + 9 * (2**(len(s)-len(p)) - 1)
        else: ans = 35 * (2**(len(s)-len(p)) - 2)
    else: ans = sum(cnt(s, p+c) for c in '0123456789')

    print(s, p, ans)
    return ans
print(cnt(input().strip(), '')-1)

