from queue import PriorityQueue

class Height:

    def __init__(self, height, x, y):
        self.height = height
        self.x = x
        self.y = y


def get_center_index(n: int):
    index = n//2
    return index, index

def height_is_valid(i, j, heights, visited, prev, curr, cen, cen_x, cen_y):
    return curr < prev and curr > cen and visited[i][j] == False and (i, j) != (cen_x, cen_y)

def height_is_valid2(curr, cen):
    return curr*(-1) > cen

def the_matrix_reloaded(heights, visited, n):
    FALSE = -1
    cen_x, cen_y = get_center_index(n)
    
    #Check for edge case
    if (heights[0][0] <= heights[cen_x][cen_y]):
        return FALSE
    else:
        visited[0][0] = True

    # pq = []
    pq = PriorityQueue()
    prev = heights[0][0]
    cen = heights[cen_x][cen_y]

    for i in range(n):
        for j in range(n):
            curr = heights[i][j]
            if (height_is_valid(i, j, heights, visited, prev, curr, cen, cen_x, cen_y)):
                pq.put(heights[i][j] * (-1))
                #pq.append(heights[i][j] * (-1))
            visited[i][j] = True

    counter = 0
    
    while not pq.empty():
        if not (height_is_valid2(curr, cen)):
            break
        counter += 1

    return counter + 1 if not counter == 0 else -1

#Taking input:
t = int(input())
while t>0:
    visited = []
    heights = []
    n = int(input())
    
    for i in range(n):
        h = list(map(int, input().split()))
        heights.append(h)
    
    false_arr = [False] * n
    visited = [false_arr] * n

    print(the_matrix_reloaded(heights, visited, n))

    t -= 1