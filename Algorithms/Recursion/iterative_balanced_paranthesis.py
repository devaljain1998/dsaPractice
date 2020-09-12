from typing import List
from collections import deque

class ParanthesisNode:
    def __init__(self, open: int, close: int, curr: str):
        self.open = open
        self.close = close
        self.curr = curr

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        combinations = []
        open = n - 1
        close = n
        stack = deque()
        curr = '('
        #Adding the first node inside the stack
        stack.append(ParanthesisNode(open, close, curr))
        
        while len(stack):
            #fetch the first node
            node = stack.pop()
            
            open, close, curr = node.open, node.close, node.curr
            
            if open == 0 and close == 0:
                combinations.append(curr)
                continue
                
            if close > open:
                curr2  = curr + ')'
                new_node = ParanthesisNode(open, close - 1, curr2)                
                
            if open != 0:
                curr1  = curr + '('
                new_node = ParanthesisNode(open - 1, close, curr1)             
        
        
        return combinations
    
print(Solution().generateParenthesis(3))