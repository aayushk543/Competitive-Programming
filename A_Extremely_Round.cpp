#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> f1(vector<ll> arr){
    stack<int> st;

    vector<int> ans(arr.size());

    for(int i = arr.size() - 1; i >= 0; i--){

        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()) ans[i] = arr.size();
        else ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

vector<int> f2(vector<ll> arr){
    stack<int> st;

    vector<int> ans(arr.size());

    for(int i = 0; i < arr.size(); i++){

        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

int main() {
        int n;
        cin >> n;

        vector<ll> arr(n);
        ll ans = 0;
        ll mini = INT_MAX;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<int> right = f1(arr);
        vector<int> left = f2(arr);

        for(int i = 0; i < n; i++){
            ans = max(ans, (ll)(right[i]-left[i]-1)*arr[i]);
        }

        cout << ans << '\n';

}
