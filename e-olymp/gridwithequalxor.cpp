// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
  
// Function to find the n x n matrix
// that satisfies the given condition
void findGrid(int n)
{
    int arr[n][n];
  
    // Initialize x to 0
    int x = 0;
  
    // Divide the n x n matrix into n / 4 matrices
    // for each of the n / 4 rows where
    // each matrix is of size 4 x 4
    for (int i = 0; i < n / 4; i++) {
        for (int j = 0; j < n / 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    arr[i * 4 + k][j * 4 + l] = x;
                    x++;
                }
            }
        }
    }
  
    // Print the generated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           printf("%d ", arr[i][j]); // cout << arr[i][j] << " "; 
        }
        printf("\n"); //cout << "\n";
    }
}
  
// Driver code
int main()
{
    int n;
    scanf("%d", &n);
    findGrid(n);
  
    return 0;
}