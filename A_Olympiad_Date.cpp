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
    vector<char> a(n); for(char& c : a) cin >> c;
    string digits = "01032025";
    map<char, int> freq;
    for(int i=0; i<digits.size(); i++){
        freq[digits[i]]++;
    }
    for (int i=0; i<n; i++){
        // check
        if (freq.find(a[i]) != freq.end()){
            freq[a[i]]--;
            if (freq[a[i]] == 0){
                freq.erase(a[i]);
            }
        }
        // outpout ? 
        if (freq.size() == 0){
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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