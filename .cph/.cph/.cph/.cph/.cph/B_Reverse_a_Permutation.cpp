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
       
       vector<int> arr(n,0);

       int j = 0;
       int num = 0;
       bool s = true;
       bool s2 = false;

       for(int i = 0; i < n; i++){
        cin >> arr[i];
        
        if(arr[i] != n - i && s){
            num = n - i;
            s = false;
            s2 = true;
        }
        if(arr[i] == num && s2){
            j = i;
        }
       }

       int p = n - num;
       int q = j;

       while(p < q){
        swap(arr[p],arr[q]);
        p++;
        q--;
       }

       for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
       }
       cout << '\n';

    }
    return 0;
}