#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;

        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        vector<int> count1(n + 1, 0), count2(n + 1, 0), count3(n + 1, 0);

        for(int i = 0; i < n; i++) {

            count1[i + 1] = count1[i] + (arr[i] == 1);
            count2[i + 1] = count2[i] + (arr[i] == 2);
            count3[i + 1] = count3[i] + (arr[i] == 3);
        }

        vector<int> t_score(n + 1);

        for(int i = 0; i <= n; i++) {

            t_score[i] = count1[i] + count2[i] - count3[i];
        }    

        vector<int> best(n + 2, INT_MIN);

        for(int i = n - 1; i >= 2; i--) {

            best[i] = max(t_score[i], best[i + 1]);
        }

        bool ans = false;

        for(int i = 1; i <= n - 2; i++){

            int one_c = count1[i];
            int two_c = count2[i];
            int three_c = count3[i];

            if(one_c < two_c + three_c) continue;

            if(best[i + 1] >= t_score[i]){
                ans = true;
                break;
            }
        }

        if(ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}