def get_minimum_trades(x: int, y: int, k: int):
    trades = 0
    sticks = 1
    coals = 0
    while (True):
        if sticks >= k and coals >= k:
            break
        elif sticks < k:
            sticks +=  -1 + x
        elif coals < k:
            sticks -= y
            coals += 1
            
        trades += 1
    return trades


t = 1#t = int(input())
while (t > 0):
    x, y, k = 1000000000, 1000000000, 1000000000
    # x, y, k = map(int, input().split())
    print(get_minimum_trades(x, y, k))
    t -= 1
