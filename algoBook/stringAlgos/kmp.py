
def prefixArrayCalculation(pattern):
    prefixArr = [0] * len(pattern)

    checkIndex = 0
    i = 1

    while i < len(pattern):
        if pattern[i] == pattern[checkIndex]:
            prefixArr[i] = checkIndex + 1
            checkIndex += 1
            i += 1
        else:
            if checkIndex == 0:
                i += 1
            else:
                checkIndex = prefixArr[checkIndex-1]

    return prefixArr

def patternMatching(string, pattern):
    if len(pattern) > len(string):
        return None

    checkIndex = 0
    i = 0

    prefixArr = prefixArrayCalculation(pattern)

    while i < len(string):
        if string[i] == pattern[checkIndex]:
            checkIndex += 1
            i += 1
            if checkIndex == len(pattern):
                return i - len(pattern)
        else:
            if checkIndex != 0:
                checkIndex = prefixArr[checkIndex - 1]
            else:
                i += 1
    
    return None

def test_prefixArrayCalculation():
    assert all([a == b for a, b in zip(prefixArrayCalculation("abaabb"), [0,0,1,1,2,0])])
    assert all([a == b for a, b in zip(prefixArrayCalculation("abaabbabaaba"), [0,0,1,1,2,0,1,2,3,4,5,3])])

def test_prefixArrayCalculation():
    assert patternMatching("abaabaabb", "abaabb") == 3
    assert patternMatching("abcd", "cd") == 2
    assert patternMatching("abcd", "kd") == None
    assert patternMatching("abcd", "d") == 3