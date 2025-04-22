#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4  // You can change this to any N

int board[N];
int solution[N], x=0;
// Check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check same column
        if (board[i] == col)
            return false;
        // Check diagonals
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(int row) {
    if (row == N) {
        // All queens placed successfully
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                {
                    printf("Q ");
                    solution[x++]=j+1;
                }
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return true;  // To print all solutions, do not return here
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;  // Place queen
            if (solveNQueens(row + 1))
                return true;  // To find one solution only
        }
    }
    return false;  // Backtrack
}

int main() {
    if (!solveNQueens(0))
        printf("No solution exists\n");
    
    else
    {
        for (int i=0; i< N ; i++)
        {
            printf("%d\t", solution[i]);
        }
    }
    return 0;
}
