
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
    string ban = "ban";
    string s = "";
    for (int i=0; i<n; i++){
        s += ban;
    }    
    vector<int> b;
    vector<int> N;
    for (int i=0; i<s.size(); i++){
        if (s[i] == 'b') b.push_back(i);
        if (s[i] == 'n') N.push_back(i);
    }
    // two pointers 
    vector<pair<int, int>> ans;
    // move all the b in front of n 
    for (int i=0; i<n; i++){
        int idx = n-i-1; 
        if (b[i] < N[idx]) ans.push_back({b[i], N[idx]});
    }
    
    
    // int ns = n; 
    // int right = 3*n-1; 
    // int left = 0;
    // solve for substring BAN -> NAB 
    // for (int i=0; i<3*n; i+=3){
    //     ans.push_back({i, i+2});
    // }
    // while (left < right){
    //     if (s[left] == 'b'){
    //         if (s[right] == 'n') ns--;
    //         ans.push_back({left, right});
    //         right--;
    //         if (s[right] == 'b') right--;   
    //     }
    //     if (s[left] == 'n') ns--;
    //     if (ns == 0) break;
    //     left++;
    // }
    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); i++){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
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