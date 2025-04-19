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
    ll workers, tasks; cin >> workers >> tasks;
    vector<ll> proficiency(workers+1, 0);
    for (ll i=0, x; i<tasks; i++){
        cin >> x;
        proficiency[x-1]++;
    }
    // bin serach the time needed 
    ll left = 1;
    ll right = tasks * 2;
    ll time = 0;
    while (left <= right){
        ll mid = left + (right - left) / 2;
        ll total_tasks = tasks;
        vector<ll> worker_time(workers+1);
        // first proficiency, keep below mid 
        for (ll i=0; i<workers; i++){
            ll cur_time = min(proficiency[i], mid);
            total_tasks -= cur_time;
            worker_time[i] = cur_time;
            if (total_tasks <= 0) break;
        }
        // try fit all with tasks in (worker time <= mid)  
        for (ll i=0; i<workers; i++){
            if (total_tasks <= 0) break;
            ll cur_time = (mid - worker_time[i])/2;
            total_tasks -= cur_time;
        }
        // if we can in this time 
        if (total_tasks <= 0){
            right = mid - 1;
            time = mid;
        }else{
            left = mid + 1;
        }
    }
    cout << time << endl;
     
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