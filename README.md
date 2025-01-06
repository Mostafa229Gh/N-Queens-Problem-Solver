# N-Queens Problem Solver

This project provides a straightforward implementation of the **N-Queens Problem** in C++. The problem involves placing `n` queens on an `n x n` chessboard so that no two queens threaten each other. The program outputs the solution in chess notation (e.g., `a1`, `c3`).

## Overview
The program uses **backtracking**, a systematic trial-and-error approach, to explore all possible configurations of the board. It incrementally places queens while ensuring that each placement is valid according to the rules of the problem:

1. No two queens can be in the same row.
2. No two queens can be in the same column.
3. No two queens can be on the same diagonal.

If an invalid configuration is reached, the algorithm "backtracks" to try different positions. This process continues until a solution is found or all possibilities are exhausted.

## How It Works
The solution process follows these steps:

1. **Recursive Placement**:
   - Start with the first row and try placing a queen in each column.
   - Move to the next row and repeat the process, ensuring that no conflicts arise with previously placed queens.

2. **Validation**:
   - Each placement is checked to ensure it doesn’t conflict with any previously placed queens. The checks include:
     - Same column.
     - Same diagonal (both left and right).

3. **Backtracking**:
   - If no valid position is found in the current row, the algorithm steps back to the previous row and tries the next available column.

4. **Solution Completion**:
   - When queens are successfully placed in all rows, the solution is complete, and the positions are converted into chess notation for output.

## Input and Output
- **Input**: The program prompts the user to enter the value of `n`, which represents both the size of the chessboard and the number of queens.
- **Output**: If a solution exists, the program prints the positions of all `n` queens in chess notation. If no solution exists, a message indicating so is displayed.

### Example
#### Input
```
Enter the value of n: 4
```

#### Output
```
Solution for 4 queens:
a2 c4 e1 d3
```
This indicates the queens are placed as follows:
- Queen 1: `a2`
- Queen 2: `c4`
- Queen 3: `e1`
- Queen 4: `d3`

## Notes and Considerations
- For `n < 4`, valid solutions usually do not exist (except for trivial cases like `n = 1`).
- The algorithm explores all possibilities, which means its runtime grows factorially with `n` in the worst case. However, backtracking significantly reduces the number of configurations that need to be examined.

## Conclusion
This implementation offers an effective solution to the N-Queens Problem using backtracking, providing results in a user-friendly chess notation format. It’s a great demonstration of how recursive algorithms can solve constraint-based problems.
