from string import ascii_lowercase as letters
from collections import defaultdict
from functools import reduce

def Solve(N, M, words, Q, queries):
    sets = defaultdict(set)    

    for word in words:
        for i, c in enumerate(word):
            sets[i, c].add(word)

    all_words = set(words)

    for query in queries:
        possible_words = (sets[i, c] for i, c in enumerate(query) if c != '?')
        w = reduce(set.intersection, possible_words, all_words)
        print(query, len(w), w)

N,M = map(int,input().split())

Words =[]
for _ in range(N):
    Words.append(input())
    
Q = int(input())

Query = [] 
for _ in range(Q):
    Query.append(input())

out_ = Solve(N,M,Words,Q,Query)
for x in out_:
    print(x)