def binary_prefix(ones, zeros, n, op):
    #Base Condition
    if (n == 0):
        print(op)
        return
    
    #One will be considered always:
    op1 = op + '1'
    binary_prefix(ones + 1, zeros, n - 1, op1)
    
    #Zero will be considered if ones are greater
    #than zeros
    if ones > zeros:
        op2 = op + '0'
        binary_prefix(ones, zeros + 1, n - 1, op2)
        
    return

def get_binary_prefix(n):
    ones = 1
    zeros = 0
    op = '1'
    binary_prefix(ones, zeros, n - 1, op)
    
get_binary_prefix(3)