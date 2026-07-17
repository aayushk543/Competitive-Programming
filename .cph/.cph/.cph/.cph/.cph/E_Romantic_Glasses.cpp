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

        vector<long long> arr(n + 1);

        for(int i = 1; i <= n; i++) cin >> arr[i];

        map<long long, int> mp;
        mp[0] = 1;

        long long odd_sum = 0;
        long long even_sum = 0;

        bool flag = true;

        for(int i = 1; i <= n; i++) {
            if(i % 2) odd_sum += arr[i];
            else even_sum += arr[i];

            long long curr1 = odd_sum - even_sum;
            // long long curr2 = odd_sum - prev_even;
            // long long curr3 = prev_odd - even_sum;

            if(mp[curr1] == 1) {
                cout << "YES" << '\n';
                flag = false;
                break;
            }

            mp[curr1] = 1;
            // st.insert(curr2);
            // st.insert(curr3);

            
        }


        if(flag) cout << "NO" << '\n';
    }
    return 0;
}




