def precompute_boards(boards : list):
    sum_of_boards = boards[0]
    max_num = boards[0]
    for i in range(1, len(boards)):
        sum_of_boards += boards[i]
        max_num = max(boards[i], max_num)
        
    return max_num, sum_of_boards
    
def get_students(books, k):
    students = 1
    book_sum = 0
    
    for i in range(len(books)):
        book_sum += books[i]
        
        if book_sum > k:
            book_sum = books[i]
            students += 1
    
    return students
    
def can_board_be_allocated(boards, k, min_painter):
    painters = 1
    board_sum = 0
    
    for i in range(len(boards)):
        board_sum += boards[i]
        
        if board_sum > k:
            board_sum = boards[i]
            painters += 1
            
            if painters > min_painter: return False
        
        
    return True
    
def get_min_books(books : list, b : int) -> int:
    start, end = precompute_books(books)
    min_books = start
    ans = -1
    
    while (start <= end):
        mid = start + (end - start) // 2
        #print(vars())
        
        if can_book_be_allocated(books, mid, b):
            ans = mid
            end = mid - 1
        else: 
            start = mid + 1
    
    return ans

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def books(self, a, b):
        #edge cases:
        if (b > len(a)): return -1
        if (b == len(a)): max(a)
        
        min_books = get_min_books(a, b)
        return min_books

a = [97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24]
b = 26
print(Solution().books(a, b))
expected_op = 97