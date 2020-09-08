def reconstructed_string(s, x):
    # if the character wi−x exists and is equal to 1, then si is 1 (formally, if i>x and wi−x= 1, then si= 1);
    # if the character wi+x exists and is equal to 1, then si is 1 (formally, if i+x≤n and wi+x= 1, then si= 1);
    # if both of the aforementioned conditions are false, then si is 0.
    
    new_strings = []
    
    n = len(s)
    
    all_zeros = True
    
    for i in range(n):
        index = i + 1
        if index > x and s[index - x] == '1':
            new_strings.append('1')
            all_zeros = False
        elif (index + x) <= (n) and s[index + x - 1] == '1':
            new_strings.append('1')
            all_zeros = False
        else:
            new_strings.append('0')
            
    if all_zeros : return '-1'
    return "".join(new_strings)
    
def main():
    t = int(input())
    while (t > 0):
        s = input()
        x = int(input())
        print(reconstructed_string(s, x))
        t -= 1
        
main()