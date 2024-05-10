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
    // use deque and make turns 
    // k > 2 * m
    // k < 2 * m 
    int n, k; cin >> n >> k;
    deque<int> dq(n);
    for (auto& x : dq) cin >> x;
    // dbg_out(dq); 
    while(dq.size() > 1 && k){
        int m = min(dq[0], dq[dq.size()-1]);
        // we can take from both ships 
        if (k > 2 * m){
            k -= 2 * m;
            dq.front() -= m;
            dq.back() -= m;
        }
        // else we can only take a portion of it k / 2
        else{
            dq.front() -= (k % 2 == 0) ? k / 2 : k / 2 + 1;
            dq.back() -= k / 2;
            k = 0;
        }
        if (dq.front() == 0){
            dq.pop_front();
        }
        if (dq.back() == 0){
            dq.pop_back();
        }
    }
    int ans = n - dq.size();
    // when size is 1 we might be able to take it out
    int carry = (dq.size() && dq.front() <= k);
    cout << ans + carry << nl;

    
    // DOES NOT WORK BECAUSE WE NEED TO SUBSTRACT FROM BOTH SIDES AT THE SAME TIME, ITS LEFT AND RIGHT. NOT LEFT OR RIGHT..
    // int n, k; cin >> n >> k;
    // vector<int> a(n);
    // for(auto& x : a) cin >> x;
    // // two pointers 
    // int left = 0;
    // int right = n - 1;
    // int l_attack = (k % 2 == 0) ? k / 2 : k / 2 + 1;
    // int r_attack = k / 2;
    // // operate
    // int ships = 0; 
    
    // while (left <= right && (l_attack > 0 || r_attack > 0)){
    //     int attack = 0;
    //     // left
    //     if (l_attack > 0){
    //        attack = min(l_attack, a[left]);
    //        l_attack -= attack;
    //        a[left] -= attack;
    //        if (a[left] == 0){
    //             left++;
    //             ships++;
    //        }
    //     }
    //     // right
    //     if (r_attack > 0){
    //         attack = min(r_attack, a[right]);
    //         r_attack -= attack;
    //         a[right] -= attack;
    //         if (a[right] == 0){
    //             right--;
    //             ships++;
    //         }
    //     }
    // }
    // cout << ships << nl;
    
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