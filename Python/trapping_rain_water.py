
def trap(heights):
    water_collected = 0

    #organizing a list of levels for the problem
    highest_left_levels = [heights[0]]
    highest_right_levels = [heights[-1]]
    
    #pointers for iterating on levels:
    right_ptr = len(heights) - 2
    
    #iterating through heights and updating the pointers
    for i in range(1, len(heights)):
        #filling left ptr first
        highest_left_levels.append(max(highest_left_levels[i-1], heights[i]))
        
        #then the right_ptr
        right_ptr = len(heights) - 1 - i
        highest_right_levels.append(max(highest_right_levels[i-1], heights[right_ptr]))
        
    #Reversing right_levels
    highest_right_levels.reverse()
    
    
    water_collected_building_wise = [min(highest_left_levels[i], highest_right_levels[i]) - heights[i] 
                                        for i in range(len(heights))]
    
    #now calculating water_collected
    for water_collected_at_each_building in water_collected_building_wise:
        water_collected += water_collected_at_each_building
    
    return water_collected

if __name__ == '__main__':
    n = int(input())
    heights = []
    if (n != 0):
        heights = input().split()
        heights = [int(i) for i in heights]
    result = trap(heights)
    print(result)
    
