def balanced_paranthesis(open, close, op, paranthesises):
    #Base condition:
    if open == 0 and close == 0:
        paranthesises.append(op)
        return
        
    if open != 0:
        op1 = op + '('
        balanced_paranthesis(open - 1, close, op1, paranthesises)
        
    if close > open:
        op2 = op + ')'
        balanced_paranthesis(open, close - 1, op2, paranthesises)
        
    return

def get_balanced_paranthesis(n : int):
    open = n - 1
    close = n
    op = '('
    paranthesises = []
    balanced_paranthesis(open, close, op, paranthesises)
    return paranthesises

print(get_balanced_paranthesis(3))