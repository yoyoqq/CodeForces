#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';
int A[200010];

void solve(){
    int n; cin >> n;
    map<int, int> count;
    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        count[x]++; 
    }   
    map<int, int> count1;
    for (int i=0; i<n-1; i++){
        cin >> x;
        count1[x]++;
    }
    // compare fisrt bug 
    int first_bug = -1;
    for(auto [k, v] : count){
        // if diff 
        if (count1.find(k) == count1.end() || count[k] != count1[k]){
            first_bug = k;
            break;
        }
    }
    // second bug 
    map<int, int> count2;
    for (int i=0; i<n-2; i++){
        cin >> x;
        count2[x]++;
    }
    // get second bug
    int second_bug = -1;
    for(auto [k, v] : count1){
        // if diff 
        if (count2.find(k) == count2.end() || count1[k] != count2[k]){
            second_bug= k;
            break;
        }
    }
    // dbg_out(count);
    // dbg_out(count1);
    // dbg_out(count2);
    cout << first_bug << endl;
    cout << second_bug << endl;

    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    // int test = 1e9; cin >> test;
    // while (test--) solve();
    return 0;
}

/*



*/