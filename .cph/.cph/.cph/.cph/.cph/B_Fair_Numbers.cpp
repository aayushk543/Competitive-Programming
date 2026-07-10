#include<bits/stdc++.h>
using namespace std;

bool check(long long n) {
    long long checker = n;
    vector<int> arr;

    while(n > 0) {
        if(n % 10 != 0) arr.push_back(n % 10);
        if(arr.size() > 0) {
            if(checker % arr[arr.size() - 1]) return false;
        }

        n /= 10;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n; 
        cin >> n;

        for(long long x = n; x <= LLONG_MAX; x++) {
            if(check(x)) {
                cout << x << '\n';
                break;
            }
        }

        // cout << "Error" << '\n';
    }
    return 0;
}