#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int index, int last1, int last2, map<tuple<int,int,int>, int>& mp) {
    int n = arr.size();

    if(index == n) return 0;

    if(mp.find({index, last1, last2}) != mp.end()) return mp[{index, last1, last2}];


    int m1 = f(arr, index + 1, index, last2, mp);
    int m2 = f(arr, index + 1, last1, index, mp);
    
    if(last1 != 0 && arr[last1] < arr[index]) m1 += 1;
    if(last2 != 0 && arr[last2] < arr[index]) m2 += 1;  

    return mp[{index, last1, last2}] = min(m1, m2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        
        int n; 
        cin >> n; 

        
        vector<int> arr(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }


        int last1 = -1, last2 = -1;
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {

            if(last1 == -1 && last2 == -1) last1 = arr[i];
            else if(arr[i] > last1 && last2 == -1) last2 = arr[i];
            else if(arr[i] <= last1 && last2 == -1) last1 = arr[i];
            else if((arr[i] > last1 && arr[i] > last2)) {
                if(last1 > last2) last2 = arr[i];
                else last1 = arr[i];

                ans++;
            }
            else if(arr[i] <= last1 && arr[i] <= last2){
                if(last1 > last2) last2 = arr[i];
                else last1 = arr[i];
            }
            else {
                if(arr[i] > last1) last2 = arr[i];
                else last1 = arr[i];
            }
        }

        cout << ans << '\n';

       }
    return 0;
}   