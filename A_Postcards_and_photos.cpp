#include <bits/stdc++.h>
using namespace std;

int main(){
string s; cin >> s;
int count = 1;
int cur = 1;
for (int i=1; i<s.size(); i++){
if (s[i-1] == s[i] && cur < 5){
cur++;
}
else{
cur = 1;
count++;
}
}
cout << count << endl;
return 0;
}