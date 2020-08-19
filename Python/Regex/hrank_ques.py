import re

pattern_string = r'[a-z]*P[a-z]*o[a-z]*B[a-z]*r'
pattern = re.compile(pattern_string)

words = ['PotBriyani',
'PotBriyaniTasting',
'PokerBet',
'PlayBuffer',
'PitBull'
]

for word in words:
    search = pattern.search(word)
    if search:
        print(f'{word} : {search.groups()}')
    else:
        print(f'{word} : {search}')