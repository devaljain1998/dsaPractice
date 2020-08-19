TRUE_STR = "true"
FALSE_STR = "false"

def check_remaining_string_does_not_contains_uppercase(remaining_string:str):    
    for i in range(len(remaining_string)):
        if remaining_string[i].isupper():
            return False
        
    return True

#Traversing pattern and word to compare
def patterns_matching(word:str, pattern:str):
    pat_ptr = 0
    uppercase_flag = False
    word_length = len(word)
    pattern_length = len(pattern)
    
    for i in range(word_length):
        #Patterns match
        if pattern[pat_ptr] == word[i]:
            pat_ptr +=  1
            if pat_ptr > pattern_length - 1:
                return check_remaining_string_does_not_contains_uppercase(word[i+1:])
        elif word[i].isupper():
            uppercase_flag = True
            break
        
    if uppercase_flag:
        return False
    
    if pat_ptr > len(pattern) - 1:
        return True


#Taking input:
n = int(input())
words = []
for i in range(n):
    word = input()
    words.append(word)
    
pattern = input()

for word in words:
    print(TRUE_STR if patterns_matching(word, pattern) else FALSE_STR)