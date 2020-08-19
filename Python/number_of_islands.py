from queue import Queue

# 1 Initialize a visited global matrix=(all false) and a counter=0
visited = []
row_length = 0
col_length = 0

# 4 check if the current node is valid
def is_valid_for_traversal(i, j, grid):
    """
    For a node to be valid for traversal it needs to fulfill the following conditions:
    1. i < row_length
    2. j < col_length
    3. grid[i][j] must be '1'
    4. The node should not be visited
    """
    return i < row_length and j < col_length and grid[i][j] == '1' and not visited[i][j]


def insert_childs(q, grid):
    #Get the current point
    curr_x, curr_y = q.get()
    visited[curr_x][curr_y] = True
    
    #Check is the lower point is valid:
    if (is_valid_for_traversal(curr_x + 1, curr_y, grid)):
        q.put((curr_x + 1, curr_y))
        
    #Check is the left point is valid:
    if (is_valid_for_traversal(curr_x, curr_y + 1, grid)):
        q.put((curr_x, curr_y + 1))
        
    return q
    

# 1 Initialize a visited global matrix=(all false) and a counter=0
# 2 Iterate the graph row by row
# 3 Iterate the graph col by col
# 4 check if the current node is valid
# 5 if yes then mark it visited
# 6 increase the counter by one
# 7 initialize an empty queue
# 8 iterate until queue is empty
# 9 do a bfs search
# 10 keep inserting childs of queue
# 11 return counter
def numIslands(grid):
    counter = 0

    # 2 Iterate the graph row by row
    # 3 Iterate the graph col by col
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            # 4 check if the current node is valid
            if (is_valid_for_traversal(i, j, grid)):
                # 5 if yes then mark it visited
                visited[i][j] = True

                # 6 increase the counter by one
                counter += 1

                # 7 initialize an empty queue
                q = Queue()
                q.put((i, j))
                
                # 8 iterate until queue is empty
                while (not q.empty()):
                    # 9 do a bfs search
                    # 10 keep inserting childs of queue
                    q = insert_childs(q, grid)
                
    return counter

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    grid = []
    for i in range(n):
        r = input()
        grid.append(r)

        #initializing visited matrix also
        list_of_false = [False] * m
        visited.append(list_of_false)

    row_length = n
    col_length = m

    result = numIslands(grid)
    print(result)
