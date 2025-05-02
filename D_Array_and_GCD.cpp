#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

const ll N = 1e7 + 5;
vector<ll> primes;
vector<bool> is_prime(N, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


void solve(){
    ll n; cin >> n;
    vector<ll> a(n, 0); for (ll& x : a) cin >> x;
    sort(all(a));
    ll j = 0;
    ll i = n-1;
    ll coins = 0;
    ll ans = 0;
    for (; i>=0; i--){
        if (j >= primes.size()) break;
        if (primes[j] > a[i] + coins){
            ans++;
            continue;
        }
        coins += (a[i] - primes[j]); 
        j++;
    }
    // dbg_out(a);
    cout << ans << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    sieve();
    // for (ll i=0; i<10; i++) cout << primes[i] << " "; cout << endl;
    // dbg_out(primes);
    ll test = 0; cin >> test;
    while (test--) solve();
    return 0;
}
