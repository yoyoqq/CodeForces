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
    string s; cin >> s;
    // base case
    if (n == 1){
        cout << s << endl;
        return;
    }
    else if (n == 2){
        if (s[0] != s[1]){
            s[0] = s[1];
        }
        cout << s << endl;
        return;
    }
    // get freq map 
    vector<int> freq(26, 0);
    for(char c : s){
        freq[c-'a']++;
    }    
    // get max and min count
    vector<pair<int, char>> b;
    for(int i=0; i<26; i++){
        if (freq[i] != 0){
            b.push_back({freq[i], i+'a'});
        }
    }
    sort(all(b));
    // dbg_out(b);
    // select the item to change 
    auto [count, min_char] = b[0];
    auto [count1, max_char] = b[b.size()-1];
    for (int i=0; i<n; i++){
        if (s[i] == min_char){
            s[i] = max_char;
            break;
        }
    }
    cout << s << endl;

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