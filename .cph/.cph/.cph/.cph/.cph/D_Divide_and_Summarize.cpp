#include<bits/stdc++.h>
using namespace std;

vector<long long> qu;
set<long long> s;

long long getsum(int l, int r){
    return qu[r+1] - qu[l];
}

void partition(vector<int>& nums, int l, int r){
    s.insert(getsum(l,r));

    if(nums[l] == nums[r]) return;

    int midv = (nums[l] + nums[r])/2;

    int mid = upper_bound(nums.begin() + l, nums.begin() + r + 1, midv) - nums.begin() - 1;

    partition(nums, l, mid);
    partition(nums, mid+1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;

        vector<int> arr(n,0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            
        }
        sort(arr.begin(), arr.end());

        qu.assign(n+1,0);
        for(int i = 0; i < n; i++){
            qu[i+1] = qu[i] + arr[i];
        }

        s.clear();

        partition(arr, 0, n-1);

        for(int i = 0; i < q; i++){
            long long m;
            cin >> m;

            cout << (s.count(m) ? "Yes\n" : "No\n");
        }


    }
    return 0;
}