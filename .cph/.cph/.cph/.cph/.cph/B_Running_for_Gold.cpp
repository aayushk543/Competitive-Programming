#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int prev1 = -1, prev2 = -1, prev3 = -1, prev4 = -1, prev5 = -1;

        vector<vector<int>> rank(n, vector<int>(6, 0));
        int skip = 0;

        for(int i = 0; i < n; i++) {
            int n1, n2, n3, n4, n5;
            cin >> n1;
            cin >> n2;
            cin >> n3;
            cin >> n4;
            cin >> n5;

            rank[i][1] = n1;
            rank[i][2] = n2;
            rank[i][3] = n3;
            rank[i][4] = n4;
            rank[i][5] = n5;

            if(i == 0) {
                prev1 = n1;
                prev2 = n2;
                prev3 = n3;
                prev4 = n4;
                prev5 = n5;
            }

            if(i > 0){
                int count = 0;

                if(n1 > prev1) count++;
                if(n2 > prev2) count++;
                if(n3 > prev3) count++;
                if(n4 > prev4) count++;
                if(n5 > prev5) count++;

                if(count >= 3) continue;
                
                skip = i;
                swap(n1, prev1);
                swap(n2, prev2);
                swap(n3, prev3);
                swap(n4, prev4);
                swap(n5, prev5);
            }

        }

        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(i == skip) continue;

            int count = 0;

            if(rank[i][1] > prev1) count++;
            if(rank[i][2] > prev2) count++;
            if(rank[i][3] > prev3) count++;
            if(rank[i][4] > prev4) count++;
            if(rank[i][5] > prev5) count++;
                
            if(count >= 3) continue;
                
            cout << -1 << '\n';
            flag = false;
            break;
        }

        if(flag) cout << skip + 1 << '\n';


    }
    return 0;
}