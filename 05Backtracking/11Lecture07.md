# Sudoku Solver
## Problem
Given a 9x9 sudoku board, solve it

## Solution
We need to fill the board so that each row, column, and 3x3 sub-grid contains the digits 1 through 9 without duplicates.

### Key Insights
1. **Backtracking**: It is a powerful technique for Sudoku because we can try placing a number, then recursively attempt to solve the remaining puzzle. If we reach a contradiction, we backtrack by removing the number and trying the next possibility.
2. **Constraints Checking**: Each number must be unique within its row, column, and 3x3 sub-grid. This constraint can be efficiently handled with three sets or arrays to track used numbers, so that unnecessary recursion branches can be pruned off.

### Approach
1. **Initialize Helper Structures**: Create three 2-d boolean arrays: `rows`, `cols`, and `boxes`. Each boolean array will be indexed 0-8, representing a row `(i)`, column `(j)` or a sub-grid `(k)`. To mark if a digit `(x)` 1-9 has been used in a specific row, column, or box (3x3 sub-grid). Ensures efficient `O(1)` checking of constraints for each number. This makes backtracking faster because we can quickly skip invalid placements, and recursion allows a natural way to explore all possibilities.
2. **Recursive Backtracking Function**:
    - Start from the top-left of the board, moving cell by cell. For each empty cell, try placing each digit from 1 to 9.
    - After placing a digit, check if it still satisfies the constraints. If yes, recursively try to fill in the remaining cells.
    - If a solution is reached, we stop; otherwise, backtrack by removing the last placed digit and trying the next possibility.

### Edge Cases
1. **No Empty Cells**: If the puzzle is already filled and valid, the algorithm should recognize it as solved.
2. **Multiple Solutions**: For puzzles with multiple solutions, this backtracking algorithm finds the first valid one.
3. **Invalid Board**: The board might start in an invalid state. This implementation does not check for validity initially, but if required, this can be added.

### Developing Intuition
Sudoku is an ideal problem for practicing backtracking. The grid layout and strict constraints allow you to narrow down possibilities quickly, which is central to the intuition behind solving constraint satisfaction problems.

### Code
```java
class SudokuSolver {
    private boolean[][] rows = new boolean[9][9];
    private boolean[][] cols = new boolean[9][9];
    private boolean[][] boxes = new boolean[9][9];

    public void solveSudoku(char[][] board) {
        // Initialize the helper arrays based on the initial board
        for (int r = 0; r < 9; r++) 
            for (int c = 0; c < 9; c++) 
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    rows[r][num] = true;
                    cols[c][num] = true;
                    boxes[getBoxIndex(r, c)][num] = true;
                }

        backtrack(board, 0, 0);
    }

    private boolean backtrack(char[][] board, int row, int col) {
        // Move to next row if column is out of bounds
        if (col == 9) {
            col = 0;
            row++;
        }

        // If we reach the end of the board, the puzzle is solved
        if (row == 9) return true;

        // If cell is already filled, move to the next cell
        if (board[row][col] != '.') return backtrack(board, row, col + 1);

        for (int num = 0; num < 9; num++) {
            int boxIndex = getBoxIndex(row, col);

            // Check if the number can be placed in row, column, and box
            if (!rows[row][num] && !cols[col][num] && !boxes[boxIndex][num]) {
                // Place the number and mark the constraints
                board[row][col] = (char) (num + '1');
                rows[row][num] = cols[col][num] = boxes[boxIndex][num] = true;

                // Recursively attempt to fill the rest of the board
                if (backtrack(board, row, col + 1)) return true;  // If successful, stop and return true

                // Backtrack by removing the number and unmarking the constraints
                board[row][col] = '.';
                rows[row][num] = cols[col][num] = boxes[boxIndex][num] = false;
            }
        }
        return false;  // Trigger backtracking if no valid number is found
    }

    private int getBoxIndex(int row, int col) {
        return (row / 3) * 3 + (col / 3); // Calculate index of the 3x3 sub-box
    }

    public static void main(String[] args) {
        SudokuSolver solver = new SudokuSolver();
        char[][] board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        solver.solveSudoku(board);

        for (char[] row : board) {
            for (char cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}
```

### Complexity
1. **Time**: Approximately `O(9^{M})`, where `M` is the number of empty cells.
2. **Space**: `O(1)`, since the board is modified in place and only constant space is used for tracking constraints.
