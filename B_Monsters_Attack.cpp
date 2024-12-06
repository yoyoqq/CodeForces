
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
    int n, k; cin >> n >> k;
    vector<int> a(n), x(n);
    for(int& u : a) cin >> u;
    for(int& u : x) cin >> u;
    vector<int> arr(n+1);
    for(int i=0; i<n; i++){
        arr[abs(x[i])] += a[i];
    }   
    // dbg_out(arr);
    // for each step calculate if possible prev bullets + cur bullets  
    int rem_bullets = 0;
    bool poss = true;
    for (int i=1; i<=n; i++){
        rem_bullets += k - arr[i];
        poss &= (rem_bullets >= 0);   
    }
    cout << (poss ? "YES" : "NO") << endl;

    
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
    int n, k; cin >> n >> k;    
    vector<int> health(n); for(int& x : health) cin >> x;
    vector<int> pos(n); 
    int t;
    for(int& x : pos){
        cin >> t;
        x = abs(t);
    }
    // 
    // pair the pos with the health 
    // dbg_out(health);
    // dbg_out(pos);

    // priority_queue<pair<int, int>, greater<pair<int,int>>> monster; // pos, health
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> monster;
    for (int i=0; i<n; i++){
        monster.push({pos[i], health[i]});
    }
    // dbg_out(monster);

    // dbg_out(monster.size());
    // simulation
    bool survived = true;
    int time = 0;
    int bullets = k;
    while (monster.size()){
        auto pair = monster.top(); monster.pop();
        int pos = pair.first, health = pair.second;
        // dbg_out(pos, health, time, bullets);
        // base case
        if (pos - time <= 0){
            survived = false;
            break;
        }
        // use bullets 
        // many bullets
        while (health > 0){
            int x = min(bullets, health);
            health -= x; 
            bullets -= x; 
            // dbg_out(health, bullets);
            if (bullets == 0){
                bullets = k;
                time++;
                if (pos - time <= 0 && health > 0){
                    survived = false;
                    break;
                }
            }
        }
    }
    cout << (survived ? "YES" : "NO") << endl;
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