BLOCKED = '#'
UNBLOCKED = '.'

maximum_time = -1

def is_reachable(grid, time_elapsed, time_remaining, position) -> bool:
    # Base Condition
    if position == (len(grid) - 1, len(grid[0]) - 1) and time_elapsed >= time_remaining:
        return True
    else:
        return False
        
    if time_elapsed > time_remaining:
        i, j = position
        #UP
        if ((i - 1) >= 0 and grid[i - 1][j] == UNBLOCKED):
            up_possibility = is_reachable(grid, time_elapsed + 1, time_remaining - 1, (i - 1, j))
            if up_possibility == True: return True
            
        #DOWN
        if ((i - 1) >= 0 and grid[i - 1][j] == UNBLOCKED):
            up_possibility = is_reachable(grid, time_elapsed + 1, time_remaining - 1, (i - 1, j))
            if up_possibility == True: return True            
            
        #LEFT
        if ((i - 1) >= 0 and grid[i - 1][j] == UNBLOCKED):
            up_possibility = is_reachable(grid, time_elapsed + 1, time_remaining - 1, (i - 1, j))
            if up_possibility == True: return True            
            
        #RIGHT
        if ((i - 1) >= 0 and grid[i - 1][j] == UNBLOCKED):
            up_possibility = is_reachable(grid, time_elapsed + 1, time_remaining - 1, (i - 1, j))
            if up_possibility == True: return True            
    else:
        return False

def reachTheEnd(grid, maxTime) -> str:
    maximum_time = maxTime
    return "Yes" if is_reachable(grid, 0, maxTime, (0, 0)) else "No"

def main():
    pass