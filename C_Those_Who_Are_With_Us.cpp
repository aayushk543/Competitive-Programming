#include<bits/stdc++.h>
using namespace std;

/*
You are given a matrix of integers with n
 rows and m
 columns. The cell at the intersection of the i
-th row and the j
-th column contains the number aij
.

You can perform the following operation exactly once:

Choose two numbers 1≤r≤n
 and 1≤c≤m
.
For all cells (i,j)
 in the matrix such that i=r
 or j=c
, decrease aij
 by one.
You need to find the minimal possible maximum value in the matrix a
 after performing exactly one such operation.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n⋅m≤105
) — the number of rows and columns in the matrix.

The next n
 lines of each test case describe the matrix a
. The i
-th line contains m
 integers ai1,ai2,…,aim
 (1≤aij≤100
) — the elements in the i
-th row of the matrix.

It is guaranteed that the sum of n⋅m
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum maximum value in the matrix a
 after performing exactly one operation.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> mat(n + 1, vector<int>(m + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cin >> mat[i][j];
        }

        int mini = 101, index1 = -1;
        int count_mini = 0;
        
        for(int i = 1; i <= n; i++) {

            int count = 0;

            for(int j = 1; j <= m; j++) {

                if(mini > mat[i][j]) {
                    mini = mat[i][j];
                    index1 = i;
                    count = 1;
                }
                else if(mini == mat[i][j]) count++;
            }
        }

        mini = 101;
        int index2 = -1;

        for(int i = 1; i <= m; i++) {

            for(int j = 1; j <= n; j++) {

                if(j == index1) {

                    if(mini > mat[j][i] - 1) {
                        mini = mat[j][i] - 1;
                        index2 = i;
                    }
                }
                else {
                    if(mini > mat[j][i]) {
                        mini = mat[j][i];
                        index2 = i;
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) mat[i][index2] -= 1;
        for(int i = 1; i <= m; i++) {
            if(i == index2) continue;

            mat[index1][i] -= 1;
        }

        int maxi = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) maxi = max(maxi, mat[i][j]);
        }

        cout << maxi << '\n';
    }
    return 0;
}