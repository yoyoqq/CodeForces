#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

vector<pair<ll, ll>> factors(ll num){
    map<ll, ll> freq;
    for (ll i = 2; i * 0.5 <= num; i++){
        while (num % i == 0){
            freq[i]++;
            num /= i;
        }
    }
    // map<ll, ll> output;
    vector<pair<ll, ll>> output;
    for (auto [k, v] : freq){
        output.push_back({v, k});
    }
    sort(all(output));
    return output;
}

void solve(){

    int n; cin >> n; 
    vector<ll> b(30, 1);
    int mx = 0;
    for (int j=2; j*j<=n; j++){
        int k = 0;
        while (n % j == 0){
            b[k++] *= j;    // put in diff basket 
            mx = max(mx, k);
            n /= j;
        }
    }
    // get k basket values 
    if (n > 1){
        // dbg_out(n);
        mx = max(mx, 1);
        b[0] *= n;
    }
    // dbg_out(b);
    cout << accumulate(b.begin(), b.begin()+mx, 0LL) << endl;
    
    
    // int n, l = 0, i, c; 
    // cin >> n;
    // // get primes of the number 
    // for (int i=2; i*i<=n; i++){
    //     if (n % i == 0){
    //         c = 0;
    //         while (n % i == 0) c++, n /= i;
    //         s.push_back({c, i});     
    //     }
    // }
    // output choose the most number of diff prime numbers 
    // if (n != 1) s.push_back({1, n});    // some prime number 
    // sort(all(s));
    // for (int i=s.size(); i>=1; i--){
    //     d[i] = d[i+1] * s[i].second;    // d * num 
    // }
    // int ans = 0;
    // for (int i=1; i<s.size(); i++){
    //     if (s[i].first != s[i-1].first){
    //         ans += d[i] * (s[i].first - s[i-1].first);
    //     }
    // }
    // cout << ans << endl;
    
    // ll n; cin >> n;
    // vector<pair<ll, ll>> freq = factors(n);    // power, num

    // ll count = 0;
    // for (ll i=0; i<freq.size(); i++){
    //     ll power = freq[i].first;
    //     ll num = freq[i].second;
    //     if (power == 0) continue;
    //     for (ll j=i+1; j<freq.size(); j++){
    //         num *= freq[j].second;
    //         freq[j].first -= power;
    //     }
    //     count += (num * power);
    // }
    // cout << count << endl;
    
    // compute the max multiplication 
    // its the multiplication of all the values 
    // ll count = 0;
    // for (auto it=freq.begin(); it!=freq.end(); it++){
    //     ll power = it->first;
    //     ll cur = it->second;
    //     if (power == 0) continue;
    //     auto tmp = it;
    //     for (auto sec=tmp++; sec!=freq.end(); sec++){
    //         cur *= sec->second;
    //         freq[sec->first] -= power;
    //     }
    //     count += (power * cur);
    // }
    // cout << count << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 0; cin >> test;
    while (test--) solve();
    return 0;
}