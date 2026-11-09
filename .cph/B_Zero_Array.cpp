#include<bits/stdc++.h>
using namespace std;

long long target = 0;

bool f(vector<long long>& arr, long long sum, int index) {
    int n = arr.size();

    if(index == n) return sum == target;

    bool take = f(arr, sum + arr[index], index + 1);
    bool nottake = f(arr, sum, index + 1);

    return take || nottake;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);

    long long sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum % 2 == 1)  {
        cout << "NO" << '\n';
        return 0;
    }

    target = sum >> 1;

    sort(arr.begin(), arr.end());

    bool ans = f(arr, 0, 0);

    if(ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}