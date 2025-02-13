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


string decToBinary(ll n) 
{ 
    string ans = "";
    int i = 0; 
    while (n > 0) { 
        ans += (n % 2 == 0 ? '0' : '1');
        n = n / 2; 
        i++;
    } 
    reverse(all(ans));
    return ans;
} 


ll binToDec(string s){
    ll res = 0;
    int exp = 0; 
    // ignore leading zeroes 
    int i=0; 
    while (i<s.size() && s[i] == '0') i++;
    for (; i<s.size(); i++){
        res = res * 2 + (s[i] == '1' ? 1 : 0);
        exp++;
    }
    return res;
}

void solve(){
    ll n; cin >> n;
   
    if (n == 1){
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    // if only has one bit 
    string base = decToBinary(n);
    int count = 0;
    for (int i=0; i<base.size(); i++){
        if (base[i] == '1') count++;
    }
    if (count == 1){
        cout << 1 << endl << n << endl;
        return;
    }
    
    // for (int i=1; i<=n; i++){
    //     cout << i << " "; 
    //     decToBinary(i);        
    // }

    // take ONLY one zero off in each operation from right to left 
    
    vector<string> a;
    a.push_back(base);
    for (int i=base.size()-1; i>=0; i--){
        if (base[i] == '1'){
            string temp = base;
            temp[i] = '0';
            a.push_back(temp);
        }
    }
    cout << a.size() << endl;
    for (int i=a.size()-1; i>=0; i--){
        // cout << stoi(a[i], nullptr, 2) << " ";
        cout << binToDec(a[i]) << " ";
        // dbg_out(binToDec(a[i]), a[i]);
    }cout << endl;

    
}



// void solvee(){
//     // !better approach by going through the bits and shifting 
//     // if 1e18 -> up to 62 range
//     ll n; cin >> n;
//     vector<int> a;
//     for (int i=62; i>=0; i--){
//         int x = 1 << i;
//         if ((x&n) == x && n != x){  // needs to match 
//             a.push_back(n-x);   // put dif f
//         }
//     }
//     a.push_back(n);
//     cout << a.size() << endl;
//     for (int& x : a) cout << x << " ";
//     cout << endl;
// }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solvee();
    // dbg_out(binToDec("00111"));
    return 0;
}

/*



*/