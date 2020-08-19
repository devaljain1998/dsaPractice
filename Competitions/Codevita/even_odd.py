BIG_NUMBER = 1000000007

def countOdd(L, R): 
    N = (R - L) // 2
  
    # if either R or L is odd 
    if (R % 2 != 0 or L % 2 != 0): 
        N += 1
  
    return N

def isOdd(n):
    return n & 1


low, high = 4, 5#low, high=map(int,input().split())
k = 3#k = int(input())

odd = countOdd(low, high)
even = (high - low + 1) - odd

e = k
o = 0

permutations = 0
for i in range(1, k+1):
    permutations = (permutations + 
                    (pow(even, e) * pow(odd, o)) % BIG_NUMBER
                    ) % BIG_NUMBER
    e -= 2
    o += 2
    
print(permutations)