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

        int maxi = -1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) maxi = max(maxi, mat[i][j]);
        }

        vector<int> vis_r(n + 1, 0);
        vector<int> vis_c(m + 1, 0);

        int index1 = 0, index2 = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(mat[i][j] == maxi) {
                    vis_r[i]++;
                    vis_c[j]++;

                    index1 = i;
                    index2 = j;
                }
            }
        }

        int c = 0, r = 0;

        for(int i = 1; i <= n; i++) {
            if(vis_r[i] > 1) {
                r++;
                index1 = i;
            }
        }

        for(int i = 1; i <= m; i++) {
            if(vis_c[i] > 1) {
                c++;
                index2 = i;
            }
        }

        if(r > 1 || c > 1) {
            cout << maxi << '\n';
        }
        else if((r == 1 && c == 1) || (r == 0 && c == 0)) {

            for(int i = 1; i <= n; i++){
                mat[i][index2]--;
            }

            for(int i = 1; i <= m; i++) {
                if(i == index2) continue;
                mat[index1][i]--;
            }


        }
        else {
            if(r == 1) {
                for(int i = 1; i <= m; i++) {
                    mat[index1][i]--;
                }

                vector<int> maxi_col;

                for(int i = 1; i <= m; i++) {
                    int curr = mat[0][i];

                    for(int j = 1; j <= n; j++) {
                        curr = max(curr, mat[j][i]);
                    }

                    maxi_col.push_back(curr);
                }

                sort(maxi_col.begin(), maxi_col.end());
            }
            if(c == 1) {
                for(int i = 1; i <= n; i++) {
                    mat[i][index2]--;
                }
            }

            

        }

    }
    return 0;
}