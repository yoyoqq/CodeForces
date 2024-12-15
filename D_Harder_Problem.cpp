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
    vector<int> a(n); for(int& x : a) cin >> x;

    // get next nums
    // vector<int> next_num;
    // for (int& num : a){
    //     if (next_num.size() && next_num.back() != num){
    //         next_num.push_back(num);
    //     }
    // }

    
    // put 2 of each 
    set<int> seen;
    vector<int> b;
    for (int& num : a){
        if (seen.find(num) == seen.end()){
            seen.insert(num);
            b.push_back(num);
        }else{
            b.push_back(-1);
        }
    }

    // dbg_out(b);
    int dummy = 1;
    for (int i=0; i<n; i++){
        // found -1
        if (b[i] == -1){
            // get a good dummy 
            while (seen.find(dummy) != seen.end()){
                dummy++;   
            }
            // update
            b[i] = dummy;
            dummy++;
            // seen.insert(dummy);
        }
    }
    
    // dbg_out(b);
    // dbg_out(count);
    for (int& num : b){
        cout << num << " ";
    }cout << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/