def lcs(A, B):
    dp = [[None for i in range(len(B))] for j in range(len(A))]
    return lcsCalculation(A, B, 0, 0, dp)

def lcsCalculation(A, B, x, y, dp):
    if x == len(A) or y == len(B):
        return 0

    if dp[x][y] != None:
        return dp[x][y]

    matchedLcs = 0
    if A[x] == B[y]:
        matchedLcs = 1 + lcsCalculation(A, B, x+1, y+1, dp)

    dp[x][y] = max(matchedLcs, max(lcsCalculation(A, B, x+1, y, dp), lcsCalculation(A, B, x, y+1, dp)))

    return dp[x][y]

def test_lcs():
    assert lcs("ABCDGH", "AEDFHR") == 3
    assert lcs("AGGTAB", "GXTXAYB") == 4