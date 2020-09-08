from itertools import combinations 

def get_divisors(n : int):
    divisors = []
    
    i = 1
    while (i * i < n):
        if (n % i == 0):
            divisors.append(i)
            divisors.append(n // i)
        i += 1
        
    if i * i == n:
        divisors.append(i)
        
    divisors.sort()
    
    return divisors


def get_substrings(n : int, k : int):
    s = str(n)
    res = [s[x:y] for x, y in combinations(range(len(s) + 1), r = 2) if len(s[x:y]) == k ] 
    return res


def divisorSubstrings(n : int, k : int) -> int:
    divisors = get_divisors(n)
    substrings = get_substrings(n, k)
    ans = 0
    
    for divisor in divisors:
        d = str(divisor)
        if d in substrings: ans += 1
        
    return ans

print(divisorSubstrings(120, 2))
print(divisorSubstrings(555, 1))
print(divisorSubstrings(5341, 2))