#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

// bool check(vector<int>& a, int mid, int ori){
//     vector<int> freqbit(31);
//     // get bit of the first window 
//     for (int i=0; i<mid; i++){
//         int x = a[i];
//         for (int j=30; j>=0; j--){
//             if (x>=(1<<j)){
//                 x -= (1<<j);
//                 freqbit[j]++;
//             }
//         }
//     }
//     int or2 = 0;
//     for (int i=0; i<freqbit.size(); i++){
//         if (freqbit[i] > 0){
//             or2 += (1<<i);
//         }
//     }
//     if (or2 != ori) return false;
//     // slinding window all the pairs need to be eq
//     for (int i=1; i+mid-1 <a.size(); i++){
//         int x = a[i-1];
//         for (int j=30 ; j>=0; j--){
//             if (x>=(1<<j)){
//                 x-= (1<<j);
//                 freqbit[j]--;
//                 if (freqbit[j] == 0){
//                     or2 -= (1<<j);
//                 }
//             }
//         }
//         x = a[i+mid-1];
//         for (int j=30; j>=0; j--){
//             if (x>=(1<<j)){
//                 x -= (1<<j);
//                 if (freqbit[j] == 1){
//                     or2 += (1<<j);
//                 }
//             }
//         }
//         if (or2 != ori){
//             return false;
//         }
//     }
//     return true;
// }

bool check(vector<int>& v, int mid,int ori)
{
    vector<int>frekbit(31);
    // initial window 
    for (int i = 0; i < mid; i++)
    {
        int x = v[i];
 
        for (int j = 30; j >= 0; j--)
        {
            if (x>=(1<<j))
            {
                x -= (1<<j);
                frekbit[j]++;
            }
        }
    }
    // intial or 
    int or2 = 0;
    for (int i = 0; i < frekbit.size(); i++)
    {
        if (frekbit[i] > 0)
        {
            or2 += (1 << i);
        }
    }
    // needs to be eq 
    if (or2 != ori)
    {
        return false;
    }
    // sliding window 
    for (int i = 1; i + mid - 1 < v.size(); i++)
    {
        int x = v[i - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]--;
                if (frekbit[j] == 0)
                {
                    or2 -= (1 << j);
                }
            }
        }
        x = v[i+mid - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]++;
                if (frekbit[j] == 1)
                {
                    or2 += (1 << j);
                }
            }
        }
        if (or2 != ori)
        {
            return false;
        }
    }
    return true;
}

void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    int ori = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ori |= a[i];
    }
    int left = 1, right = n;
    while (left < right){
        int mid = (left + right) / 2;
        if (check(a, mid, ori)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    cout << left << endl;
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
