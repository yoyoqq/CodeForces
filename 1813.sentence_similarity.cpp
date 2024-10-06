#include <iostream>
#include <bits/stdc++.h>
using namespace std

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.size() > s2.size()){
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }
        // make groups 
        vector<string> g1 = make_groups(s1);
        vector<string> g2 = make_groups(s2);
        // check if possible
        // check prefix and suffix 
        int prefix = 0;
        int suffix = 0;
        for (int i=0; i<g1.size(); i++){
            if (g1[i] == g2[i]) prefix++;
            else break;
        }
        for (int i=0; i<g1.size(); i++){
            if (g1[g1.size()-1-i] == g2[g2.size()-1-i])
                suffix++;
            else break;
        }
        cout << suffix << endl << prefix << endl;
        return (suffix + prefix >= g1.size() ? true : false);
    }

private:
    vector<string> make_groups(string& s){
        vector<string> res;
        string word = "";
        for (char& c : s){
            if (c == ' '){
                res.push_back(word);
                word = "";
            }else{
                word += c;
            }
        }
        res.push_back(word);
        return res;
    }
};