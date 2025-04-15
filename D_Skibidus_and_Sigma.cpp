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
    map<ll, vector<vector<int>>> freq;

    for (int i=0; i<n; i++){
        vector<int> a(m);
        ll sm = 0;
        for (int j=0; j<m; j++){
            cin >> a[j];
            sm += a[j];
        }
        freq[sm].push_back(a);
    }    
    // compute the sums 
    vector<int> ans;
    for (auto it=freq.rbegin(); it!=freq.rend(); it++){
        vector<vector<int>> arr = it->second;
        // sort(arr.begin(), arr.end());        // ! it doesnt matter no need to sort, already the max due to the sum ..
        // dbg_out(arr);                        // ? should prove it that there is not need to sort by using the sum of a + b || b + a with the same sum 
        // append to the ans;
        for (int i=arr.size()-1; i>=0; i--){
            for (int j=0; j<arr[i].size(); j++){
                ans.push_back(arr[i][j]);
            }
        } 
    }
    // dbg_out(ans);
    // calculate the sum of sum
    ll count = 0;
    ll cur_sum = 0;
    for (int i=0; i<ans.size(); i++){
        cur_sum += ans[i];
        count += cur_sum;
    }
    cout << count << endl;
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