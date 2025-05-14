#include <stdio.h>
#include <string.h>

#define max 20
int dp[max][max];
char X[max]; 
char Y[max];

int lcs(char X[], char Y[], int m , int n) {
    int i, j;
    // Build the LCS table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
                
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
                
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[m][n];
}

void printLcs(int len, int m , int n)
{
    int index = len;
    char lcsString[index + 1];
    lcsString[index] = '\0';  // Null terminator

    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (X[i - 1] == Y[j - 1]) 
        {
            lcsString[--index] = X[i - 1];
            i--; j--;
        } 
        
        else if (dp[i - 1][j] > dp[i][j - 1]) 
            i--;
            
        else 
            j--;
    }
    printf("\nLength of the longest common subsequences: %d\n", len);
    printf("LCS: %s\n", lcsString);
}

int main() {
    strcpy(X, "ABCABE");
    strcpy(Y, "ABBCDAE");
    int len= lcs(X, Y, strlen(X), strlen(Y));
    printLcs(len, strlen(X), strlen(Y));
    return 0;
}
