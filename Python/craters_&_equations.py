N = 1000000

def countSol(coeff, start, end, rhs):
    
    #Termination
    if (rhs == 0):
        return True
        
    #initialize count of solutions:
    result = 0
    
    #subtract all smaller or equal coeff and recursion
    for i in range(start, end+1):
        if (coeff[i] <= rhs):
            sol = countSol(coeff, i, end, rhs - coeff[i])
            if (sol > N or sol < 1):
                continue
            
            result += sol

    if (result > 0): return True
            
    return False

def solve(A):
    true_str = "Valid"
    false_str = "Invalid"
    
    A = A.split()
    coeff = []
    i = 0
    prev_sign = 1
    while(A[i] != '='):
        if (A[i] == "?"):
            coeff.append(prev_sign)
        elif (A[i] == "+"):
            prev_sign = 1
        elif (A[i] == '-'):
            prev_sign = -1
            
        i += 1
            
    rhs = int(A[-1])
    
    return true_str if (countSol(coeff, 0, len(coeff) - 1, rhs)) else false_str


test_str = "? + ? - ? = 10"
print(solve(test_str))