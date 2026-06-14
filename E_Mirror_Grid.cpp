#include<bits/stdc++.h>
using namespace std;
#define ll as long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> mat(n+1, vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                char c;
                cin >> c;
                mat[i][j] = c - '0';
            }
        }

        int count = 0;

        for(int i = 1; i <= n/2; i++){
            for(int j = 1; j <= n/2; j++){
                
                int sum = mat[i][j] + mat[j][n-i+1] + mat[n-i+1][n-j+1] + mat[n-j+1][i];

                count += min(sum, 4-sum);
            }
        }

        if(n % 2){
            for(int i = 1; i <= n/2; i++){
                int j = n/2 + 1;
                int sum = mat[i][j] + mat[j][i] + mat[n-i+1][j] + mat[j][n-i+1];
                count += min(sum, 4-sum);
            }
        }

        cout << count << '\n';
    }
    return 0;
}
