#include <stdio.h>
#include <string.h>

char board[8][9];
int count = 0;
int row_used[8];
int diag1[15]; // row + col
int diag2[15]; // row - col + 7

void backtrack(int col)
{
    if (col == 8)
    {
        count++;
        return;
    }
    for (int row = 0; row < 8; row++)
    {
        if (board[row][col] == '*' || row_used[row] || diag1[row + col] || diag2[row - col + 7])
            continue;
        row_used[row] = 1;
        diag1[row + col] = 1;
        diag2[row - col + 7] = 1;
        backtrack(col + 1);
        row_used[row] = 0;
        diag1[row + col] = 0;
        diag2[row - col + 7] = 0;
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        scanf("%s", board[i]);
    }
    memset(row_used, 0, sizeof(row_used));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));
    backtrack(0);
    printf("%d\n", count);
    return 0;
}