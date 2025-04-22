#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


// class MedianFinder {
//     public:
//         priority_queue<int> maxHeap;
//         priority_queue<int, vector<int>, greater<int>> minHeap;
    
//         MedianFinder() {
            
//         }
        
//         void addNum(int num) {
//             // it is a greater value to the minHeap 
//             if (minHeap.size() && minHeap.top() < num){
//                 int tp = minHeap.top(); minHeap.pop();
//                 minHeap.push(num);
//                 maxHeap.push(tp);
//             } 
//             else{
//                 maxHeap.push(num);
//             }
//             if (maxHeap.size() != 1 + minHeap.size()){
//                 int tp = maxHeap.top(); maxHeap.pop();
//                 minHeap.push(tp);
//             }
//         }
        
//         int findMedian() {
//             return maxHeap.top();
//             // int size = maxHeap.size() + minHeap.size();
//             // if (size % 2 == 0){
//             //     return (double)(maxHeap.top() + minHeap.top()) / 2;
//             // }else{
//             // }
//         }

//         void restart(){
//             maxHeap = priority_queue<int>();
//             minHeap = priority_queue<int, vector<int>, greater<int>>();
//         }
//     };

// void solve(){
//     int n, k; cin >> n >> k;
//     vector<int> a(n); for(int& x : a) cin >> x;
//     MedianFinder left;
//     for (int i=0; i<n-1; i++){
//         left.addNum(a[i]);
//         MedianFinder mid;
//         for (int j=i+1; j<n; j++){
//             mid.addNum(a[j]);
//             dbg_out(left.findMedian(), mid.findMedian());
//             if (left.findMedian() <= k && mid.findMedian() <= k){
//                 cout << "YES" << endl;
//                 return;
//             }
//         }   
//     }
//     left.restart();
//     for (int i=1; i<n-1; i++){
//         left.addNum(a[i]);
//         MedianFinder mid;
//         for (int j=i+1; j<n; j++){
//             mid.addNum(a[j]);
//             dbg_out(left.findMedian(), mid.findMedian());
//             if (left.findMedian() <= k && mid.findMedian() <= k){
//                 cout << "YES" << endl;
//                 return;
//             }
//         }   
//     }
//     cout << "NO"<< endl;
// }


bool check_prefix_and_middle(int n, vector<int>& a){
    // prefix and suffix 
    vector<int> suf(n+1, 0);
    vector<int> minsuf(n+1, 0);
    suf[n] = a[n-1];
    minsuf[n] = a[n-1];
    // get suffix 
    for (int i=n-2; i>=0; i--){
        suf[i+1] = suf[i+2] + a[i];
        minsuf[i+1] = min(minsuf[i+2], suf[i+1]);
    }
    dbg_out(suf, minsuf);
    int s = 0;
    for (int i=0; i<n-2; i++){
        s += a[i];
        if (s < 0) continue;
        if (suf[i+2] >= minsuf[i+3]){
            return true;
        }
    }
    return false;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for (int i=0; i<n; i++){
        cin >> a[i];
        if (a[i] <= k) a[i] = 1;
        else a[i] = -1;
    }

    int ar = n+1, b = -1;
    int s = 0;
    // find positive part left side  
    for (int i=0; i<n; i++){
        s += a[i];
        if (s >= 0){
            ar = i + 1;
            break;
        }
    }
    // find positive on right side 
    s = 0;
    for (int i=n-1; i>=0; i--){
        s += a[i];
        if (s>=0){
            b = i + 1;
            break;
        }
    }
    // output ? 
    // case its on left and right
    if (ar + 1 < b){
        cout << "YES" << endl;
        return;
    }
    // check if its on mid and left/right side 
    if (check_prefix_and_middle(n, a)){
        cout << "YES" << endl;
            return;
    }
    reverse(all(a));
    if (check_prefix_and_middle(n, a)){
        cout << "YES" << endl;
        return;
    }
    // otherwise not possible 
    cout << "NO" << endl;
    
    
    // at least 2 <= k (median)
    // med()     x values need to be <= k      no need for pq, just count 
    // sliding window, prefix ? 

    // prefix of <= k or > k     first for 
    // second for mid value 
    // int left_smaller = 0;
    // int left_greater = 0;
    // for (int i=0; i<n; i++){
    //     if (a[i] <= k) left_smaller++;
    //     else left_greater++;
    // } 
    // for (int i=0; i<n; i++){
    //     // count a[i] off 
    //     if (a[i] <= k){
    //         left_smaller--;
            
    //     }else{
    //         left_greater--;
    //     }
    //     int mid_smaller = 0, mid_greater = 0;  
    //     int right_smaller = left_smaller, right_greater = left_greater;
    //     // take all from i+1 to j
    //     for (int j=i+1; j<n; j++){
    //         if (a[i] <= k){
    //             mid_smaller++;
    //             right_smaller--;
    //         }
    //         else{
    //             mid_greater++;
    //             right_greater--;
    //         }
    //         if (mid_smaller >= mid_greater && right_smaller >= right_greater){
    //             cout << "YES" << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "NO" << endl;
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