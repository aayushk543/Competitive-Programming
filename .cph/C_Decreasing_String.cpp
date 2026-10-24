#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       string s;
       cin >> s;

       long long pos;
       cin >> pos;

       long long l = s.length();

       long long index = 1;

       long long low = 1, high = l;

       while(low < high) {
        long long mid = (low + high) >> 1;
        long long sum = ((mid)* (2*l - mid + 1)* 1LL) / 2;

        if(sum < pos) low = mid + 1;
        else high = mid;
       }

       index = high;

       //cout << index << '\n';

       long long removed = index - 1;

       long long store = removed;

       stack<int> st;

       for(int i = 0; i < l; i++) {

        while(!st.empty() && removed > 0 && s[st.top()] > s[i]) {
            removed--;
            st.pop();
        }
        st.push(i);
       }

       while(removed > 0 && !st.empty()) {
        st.pop();
        removed--;
       }

       string s2 = "";

       while(!st.empty()) {
        s2 += s[st.top()];
        st.pop();
       }

       reverse(s2.begin(), s2.end());

       removed = store;

       //cout << s2 << " " << pos - (((index2 - 1)*(2*l - pos + 2)) / 2) << '\n';

       long long offset = pos - 1 - (1LL * removed * (2LL * l - removed + 1) / 2);

       cout << s2[offset];
    }
    return 0;
}