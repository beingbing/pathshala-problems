# N-Queens
## Problem 
Given an NxN board, and N queens. Place these queens such that no two queens attack each other.

## Solution
No two queens should be in the same row, column, or diagonal. 

### Key Insights
1. **Recursive Backtracking**:
    - We use backtracking to explore each possible placement of queens.
    - For each row, place a queen in a column and recursively try to place queens in subsequent rows.
    - If placing a queen in a position leads to a conflict, backtrack by removing the queen and trying the next position.
2. **Constraints on Queen Placement**:
    - **Column Constraint**: No two queens can share the same column.
    - **Diagonal Constraints**: No two queens can share the same diagonal.
    - We keep track of the columns and diagonals attacked by previously placed queens to quickly check if a placement is valid.

### Code
```java
import java.util.*;

class NQueens {
    private List<List<String>> solutions = new ArrayList<>();
    private boolean[] columns;
    private boolean[] diagonals1;
    private boolean[] diagonals2;

    public List<List<String>> solveNQueens(int n) {
        columns = new boolean[n];          // Tracks columns
        diagonals1 = new boolean[2 * n - 1]; // Tracks left-to-right diagonals
        diagonals2 = new boolean[2 * n - 1]; // Tracks right-to-left diagonals

//        either create board and pass it on to each recursion state
//        char[][] board = new char[n][n];
//        for (char[] row : board) Arrays.fill(row, '.'); // Initialize the board with '.'
//        backtrack(0, n, board);
       
        // or track column for each row, and create board at the end
        backtrack(0, n, new ArrayList<>());
        return solutions;
    }

    // private void backtrack(int row, int n, char[][] board) {
    private void backtrack(int row, int n, List<Integer> queenPositions) {
        // If all queens are placed, convert to board and add to solutions
        if (row == n) {
            solutions.add(createBoard(n, queenPositions));
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if the column and diagonals are free
            if (columns[col] || diagonals1[row + col] || diagonals2[row - col + n - 1]) continue; // Conflicting placement

            // Place queen
            // board[row][col] = 'Q';
            queenPositions.add(col);
            columns[col] = true;
            diagonals1[row + col] = true;
            diagonals2[row - col + n - 1] = true;

            // Recurse to place next queen in the next row
            backtrack(row + 1, n, queenPositions);

            // Backtrack by removing the queen and resetting markers
            // board[row][col] = '.';
            queenPositions.removeLast();
            columns[col] = false;
            diagonals1[row + col] = false;
            diagonals2[row - col + n - 1] = false;
        }
    }

//    private List<String> createSolution(char[][] board) {
//        List<String> solution = new ArrayList<>();
//        for (char[] row : board) solution.add(new String(row));
//        return solution;
//    }
    
    private List<String> createBoard(int n, List<Integer> queenPositions) {
        List<String> solution = new ArrayList<>();
        for (int col : queenPositions) {
            char[] row = new char[n];
            Arrays.fill(row, '.');
            row[col] = 'Q';  // Place the queen in the correct column
            solution.add(new String(row));
        }
        return solution;
    }

    public static void main(String[] args) {
        NQueens solver = new NQueens();
        int n = 4;
        List<List<String>> solutions = solver.solveNQueens(n);
        for (List<String> solution : solutions) {
            for (String row : solution) {
                System.out.println(row);
            }
            System.out.println();
        }
    }
}
```

### Complexity Analysis
1. **Time Complexity**: `O(N!)` because the solution space grows factorially as we place queens row by row.
2. **Space Complexity**: `O(N^2)` for storing the board configurations in the solutions list.

### Note:
Prune: discard all those cases, which you know can't lead to results