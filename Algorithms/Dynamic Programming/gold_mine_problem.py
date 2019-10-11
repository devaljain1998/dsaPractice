class Point:
    def __init__(self, x, y, n):
        this.x = x
        this.y = y
        this.n = n

test_cases = int(input())
while(test_cases):
    m = int(input())
    matrix, optimal_gold = [], []
    minus_one_matrix = [ -1 for x in range(m) ]
    for i in range(m):
        temp_list = [ x for x in input().split() ]
        matrix.append(temp_list)
        
        optimal_gold.append(minus_one_matrix)

    optimal_gold[0][1] = 10

    print(optimal_gold)
    print(minus_one_matrix)
    
    test_cases -= 1
