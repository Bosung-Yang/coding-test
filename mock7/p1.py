def rotate90(a):
    # N×M → M×N, 원래 (i, j) → (j, N-1-i)
    n, m = len(a), len(a[0])
    r = [[0] * n for _ in range(m)]
    for i in range(n):
        for j in range(m):
            r[j][n - 1 - i] = a[i][j]
    return r


def solution(a, k):
    for _ in range(k % 4):       # 4번 회전하면 원래대로
        a = rotate90(a)
    return a
