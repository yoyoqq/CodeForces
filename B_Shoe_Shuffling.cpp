#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    int n; cin >> n;
    vector<int> s(n), p(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }    
    int l = 0, r = 0;
    bool ans = true;
    for (int i=0; i<n; i++){
        p[i] = i+1;
    }
    while (r < n){
        while (r < n-1 && s[r] == s[r+1]){  // equal values
            r++; 
        }
        if (l == r){    // only one item (not possible)
            ans = false;
        }
        else{
            rotate(p.begin()+l, p.begin()+r, p.begin()+r+1); // rotate 
        }
        l = r + 1;
        r++;
    }
    if (ans){
        for (auto x : p) cout << x << " ";
        cout << endl;
    }else{
        cout << - 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}


// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #define all(x) (x).begin(), (x).end()   // sort(all(a))
// using ll = long long;


// void solve(){
//     int n; cin >>n;
//     map<int, vector<int>> freq;
//     // map<int, int> position;
//     int x;
//     for(int i=0; i<n; i++){
//         cin >> x;
//         freq[x].push_back(i);
//         position[i] = x;
//     }
//     // if false 
//     int sz = 1e9;
//     for (auto& [k, v] : freq){
//         sz = min(sz, (int)v.size());
//         // vector<int> temp(v.size());
//         // for(int i=0; i<v.size()-1; i++){
//         //     temp[i] = v[i+1]; // Shift elements left
//         // }
//         // temp[v.size()-1] = v[0]; // Move first element to the back
//         // v = temp;
//     }
//     if (sz <= 1){
//         cout << -1 << endl;
//         return;
//     }

//     // two pointers 
//     int j = 1;
//     int c = 1;
//     for (int i=1; i<=n; i++){
//         while (arr[i] == arr[j] && j<=n){
//             j++;
//             c=i;
//         }
//         if (c == i){
//             cout << j - 1 << " ";
//         }else{
//             cout << i - 1 << " ";
//         }
//     }
//     cout << endl;
    
//     // return perm 
//     // for (int i=0; i<n; i++){
//     //     int colour = position[i];
//     //     int cur = freq[colour].back(); freq[colour].pop_back();
//     //     // dbg_out(cur);
//     //     cout << cur+1 << " ";
//     // }cout << endl;
// }

// int main(){
//     ios::sync_with_stdio(0); cin.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int test = 0; cin >> test;
//     while (test--) solve();
//     return 0;
// }