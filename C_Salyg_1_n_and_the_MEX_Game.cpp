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
    vector<int> a(n); 
    for(int& x : a) cin >> x;
    // sort(all(a));
    int moves = n * 2 + 1;
    int smallest = -1;
    for (int i=0; i<a.size(); i++){
        if (i == 0 && a[i] != 0){
            smallest = 0;
            break;
        }
        else if (i > 0 && a[i] != i){
            smallest = i;
            break;
        }
    }
    if (smallest == -1){
        smallest = n;
    }
    // print first move 
    cout << smallest << endl;
    int bob;
    cin >> bob;
    while (bob != -1){
        cout << bob << endl;
        cin >> bob;
        // dbg_out("HI", bob);
    }
    // while (a.size() && moves){
    //     // take out smallest 
    //     cout << smallest << endl;
    //     cout.flush();
    //     // cin 
    //     cin >> bob;
    //     if (bob == -1) break;
    //     else if (bob == -2){
    //         cout << "BAD" << endl;
    //         break;
    //     }
    //     if (bob < smallest){
    //         smallest = bob;
    //     }
    //     moves--;
    // }   

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
