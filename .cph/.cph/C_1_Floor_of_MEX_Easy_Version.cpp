#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        deque<int> ans;

        int prev = 0;

        int f_limit = -1;
        vector<int> vec;
    
        for(int i = 0; i < n; i++){

            for(int j = prev; j < arr[i] * (i + 1) && j < n; j++) vec.push_back(j);

            while(!vec.empty() && arr[i] == vec.back() / (i + 1)) vec.pop_back();

            prev = min(max(prev, (arr[i] + 1)*(i + 1)), n);

           
        }

        cout << vec.size() << '\n';

        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

        cout << '\n';
    }
}