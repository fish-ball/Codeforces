from sys import stdin, stdout

mat = [[int(x) for x in stdin.readline().strip().split()] for i in range(0, 3)]

mat[0][0] = mat[2][1] - mat[1][0]
mat[1][1] = mat[2][0] + mat[2][1] - mat[1][0] - mat[1][2]

b = (mat[2][0] + mat[0][2] - mat[0][0] - mat[2][2]) // 2

mat[0][0] += b
mat[1][1] += b
mat[2][2] += b

for i in range(0, 3):
    print(' '.join([str(x) for x in mat[i]]))
