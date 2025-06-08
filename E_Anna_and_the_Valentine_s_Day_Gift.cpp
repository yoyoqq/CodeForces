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
    int n, m; cin >> n >> m;
    // vector<int> a;
    vector<pair<int, int>> multiples;
    int count = 0;
    for (int i=0, x; i<n; i++){
        cin >> x;
        // if (x % 10 == 0) multiples.push_back(x);
        if (x % 10 == 0){
            int zeroes = 0;
            while (x % 10 == 0){
                zeroes++;
                x /= 10;
            }
            multiples.push_back({zeroes, x});
        }
        // else a.push_back(x);
        else{
            count += to_string(x).size();
        }
    }
    // sort(all(multiples), greater<pair<int, int>);
    sort(multiples.begin(), multiples.end(), [](auto &a, auto &b) {
    return a.first > b.first;});
    dbg_out(multiples);
    // remove from multiples half of them, take turns 
    for (int i=0; i<multiples.size(); i+=2){
        // while (multiples[i] % 10 == 0){
        //     multiples[i] /= 10;
        // }
        // // dbg_out(multiples[i]);
        // count += to_string(multiples[i]).size();
        count += to_string(multiples[i].second).size();
        
    }
    for (int i=1; i<multiples.size(); i+=2){
        count += multiples[i].first + to_string(multiples[i].second).size();
    }
    // dbg_out(count, m);
    if (count > m){
        cout << "Sasha" << endl;
    }
    else{
        cout << "Anna" << endl; 
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