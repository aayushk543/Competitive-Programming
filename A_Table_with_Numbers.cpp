#include<bits/stdc++.h>
using namespace std;

int f(vector<int> arr, int i, int k){
    int n = arr.size();
    int ans = 0;
    int c = 0;
    while(c < k){
            ans += floor(arr[i+c]/arr[n-k+c]);
            arr[i+c] = 0;
            arr[n-k+c] = 0;
            c++;
        }
        for(int i = 0; i < n; i++){
            ans += arr[i];
        }
        return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,h,l;
        cin >> n >> h >> l;

        vector<int> a(n,0);
        int sum = 0;


        for(int i = 0; i < n; i++){
        cin >> a[i];
        
        
        }

        sort(a.begin(), a.end());

        int i = 0, j = a.size() - 1;

        while(i < j){
            if(a[j] > max(h,l)){
                j--;
            }
            else if(a[i] > min(h,l)){
                break;
            }
            else if(a[j] <= max(h,l) && a[i] <= min(h,l)){
                sum++;
                j--;
                i++;
            }
            
        }

        cout << sum << '\n';
        
    }
    return 0;
}