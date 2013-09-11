def next_permutation(a):
    
    # if list has less than two elements, has no next permutation.
    if len(a) < 2: return False

    # step 1: find max i for a[i] > a[i+1]
    i = len(a)-2
    while i >= 0 and a[i] >= a[i+1]: i -= 1
    if i < 0: return False
    j = i + 1

    # step 2: find max k for a[k] > a[i]
    k = len(a) - 1
    while a[i] >= a[k]: k -= 1

    # step 3: swap a[i] and a[k]
    (a[i], a[k]) = (a[k], a[i])

    # step 4: reverse a[j:]
    a[j:] = a[:j-1:-1]
    
    return True


n = input().strip()
l = (len(n)+1>>1)

if len(n) % 2 == 1:
    print('4'*l+'7'*l)
elif n > '7'*l+'4'*l:
    print('4'*l+'47'+'7'*l)
else:
    a = list('4'*l+'7'*l)
    x = list(n)
    while a < x:
        next_permutation(a)
    print(''.join(a))
