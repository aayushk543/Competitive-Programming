#include<bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k,x;

    cin >> n >> k >> x;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int count = 0;
    vector<long long> vp;

    for(int i = 1; i < n; i++){
        if(k == 0 && arr[i] - arr[i-1] > x) count++;
        else if(k > 0 && arr[i] - arr[i-1] > x) {
            long long diff = arr[i] - arr[i-1] - 1; 
            count++;
            vp.push_back(diff);
        }
    }
    

    sort(vp.begin(), vp.end());
    for(int i = 0; i < vp.size() && k > 0; i++){
        if((vp[i]/x) <= k) {
            k -= (vp[i]/x);
            count--;
        }
        else break;
    }    

    cout << count + 1 << '\n';
}