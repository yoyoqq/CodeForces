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
    int n, m; cin >> n >> m;

    // rather than looking for the pairs 
    // what if we look for the missing one
    // that would mean that if we substract 
    // a - b
    // then the remainding one is the stolen 
    // making pairs in this problem is not important 
    // find MISSING ONE

    vector<vector<int>> freq(m, vector<int>(26));
    // char, count 
    
    // if a -> +1      if b -> -1 
    //    n              n - 1
    // result is values on 1 positive 
    string word;
    for (int i=0; i<n; i++){
        cin >> word; 
        for (int j=0; j<m; j++) // each char 
            freq[j][word[j]-'a']++;
    }
    for (int i=0; i<n-1; i++){
        cin >> word;
        for (int j=0; j<m; j++)
            freq[j][word[j]-'a']--;
    }
    // output 
    string stolen = "";
    for (int i=0; i<m; i++){
        for (int j=0; j<26; j++){
            if (freq[i][j] == 1){
                stolen += (j+'a');
                break;
            }
        }
    }
    // dbg_out(freq);
    cout << stolen << endl;



    // n 
    // n -1
    // set<string> a, b;
    // for (int i=0, string word; i<n; i++){
    //     cin >> word;
    //     a.insert(word);
    // }
    // for (int i=0, string word; i<n-1; i++){
    //     cin >> word;
    //     b.insert(word);
    // }
    // // delete intersection ? ! assume all values are diff  
    // for (string& word : a){
    //     if (b.find(word) != b.end()){
    //         a.erase(word);
    //         b.erase(word);
    //     }
    // }
    // // brute force find val
    // vector<string> arr;
    // for (auto word : b){
    //     arr.push_back(word);
    // } 
    // for (int i=0; i<arr.size(); i++){
    //     for (int j=i+1; j<arr.size(); j++){
    //         // check intersection 
    //         if (){

    //         }
    //     }
    // }
    
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