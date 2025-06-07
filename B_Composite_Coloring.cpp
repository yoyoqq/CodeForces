#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

vector<int> primes;

void compute_primes(){
    for (int i=2; primes.size()<=11; i++){
        int is_prime = true;
        for (int j=2; j*j<=i; j++){
            if (i % j == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
}


vector<int> fill_gaps(vector<int>& arr){
    vector<int> a(arr.size());
    sort(arr.begin(), arr.end());
    int color = 1; 
    int num = arr[0];
    for (int i=0; i<arr.size(); i++){
        // if same 
        if (num == arr[i]) a[i] = color;
        else{
            color++;
            a[i] = color;
            num = arr[i];
        }
    }
    return a;
}

void solve(){
    int n; cin >> n;
    // put into groups each num 
    vector<vector<int>> groups(primes.size());
    for (int i=0; i<n; i++){
        int num; cin >> num;
        for (int j=0; j<primes.size(); j++){
            if (num % primes[j] == 0){
                groups[j].push_back(i);
                break;
            }
        }
   }
   // put reverse and put into array
   vector<int> res(n);
   int color = 0;
   for (auto group : groups){
        if (group.size()){
            color++;
            // for each idx put this color 
            for (int& idx : group){
                res[idx] = color;
            }
        }
   }    
   // print out 
   cout << color << endl;
   for (int& x : res) cout << x << " ";
   cout << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    compute_primes(); // up to 11 
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}