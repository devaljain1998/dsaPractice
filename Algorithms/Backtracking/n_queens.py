from typing import List
import copy
import pprint


class NQueenSolver:
    """
    This class returns the number of ways to solve the NQueen problem.
    """

    def __init__(self, n: int):
        self.n = n
        self.visited = [[False for i in range(n)] for j in range(n)]

    def get_methods(self, row: int = 0, visited: List[List[bool]] = None) -> int:
        # Nqueen cannot be solved with queens less than
        # or equal to 3.
        if self.n <= 3:
            return 0

        if visited is None:
            visited = self.visited

        methods = 0
        # Iterating for every row in the board of the row
        for i in range(self.n):
            if not visited[row][i]:
                # update the visited board
                new_visited = self.__update_visited(row, i, visited)

                # In case we can dig deeper
                if row != self.n - 1:
                    # get methods from the child functions
                    methods += self.get_methods(row + 1, new_visited)
                # Else return 1
                else:
                    return 1

        return methods

    def __update_visited(self, row: int, col: int, visited: List[List[bool]]) -> List[List[bool]]:
        new_visited = copy.deepcopy(visited)
        n = self.n
        # Mark row
        self.__mark_row(row, col, new_visited, n)
        # Mark col
        self.__mark_column(row, col, new_visited, n)
        # Mark diagonals
        self.__mark_diagonals(row, col, new_visited, n)
        return new_visited

    def __mark_row(self, row: int, col: int, visited: List[List[bool]], n: int) -> None:
        visited[row] = [True for i in range(n)]

    def __mark_column(self, row: int, col: int, visited: List[List[bool]], n: int) -> None:
        for i in range(n):
            visited[i][col] = True

    def __mark_diagonals(self, row: int, col: int, visited: List[List[bool]], n: int) -> None:
        # upper left
        i, j = row, col
        while(self.__is_inbound(i, j, n)):
            visited[i][j] = True
            i -= 1
            j -= 1

        # upper right
        i, j = row, col
        while(self.__is_inbound(i, j, n)):
            visited[i][j] = True
            i -= 1
            j += 1

        # lower left
        i, j = row, col
        while(self.__is_inbound(i, j, n)):
            visited[i][j] = True
            i += 1
            j -= 1

        # lower right
        i, j = row, col
        while(self.__is_inbound(i, j, n)):
            visited[i][j] = True
            i += 1
            j += 1

    def __is_inbound(self, row, col, n):
        return row >= 0 and row < n and col >= 0 and col < n


solver = NQueenSolver(8)
methods = solver.get_methods()
print(methods)