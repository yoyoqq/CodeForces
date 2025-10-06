class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> alert;
        for (int i=0; i<keyName.size(); i++){
            int hour = stoi(keyTime[i].substr(0, 2));
            int min = stoi(keyTime[i].substr(3, 2));
            int time = hour * 60 + min;
            // cout << time << endl;
            alert[keyName[i]].push_back(time);
        }
        for (auto& [k, v] : alert){
            sort(v.begin(), v.end());
            // if (k != "maa") continue;
            // cout << k << endl;
            // for (auto val : v) cout << val << " "; cout << endl;
        }

        vector<string> ans;
        for (auto& [k, v] : alert){
            if (v.size() < 3) continue;
            for (int i=0; i<v.size()-2; i++){
                if (v[i+2]-v[i] <= 60){
                    ans.push_back(k);
                    break;
                }
                // new day, skip it 
                // if (23 <= v[i] && v[i] <= 24 && v[i+2] <= 1) continue;
                // cout << v[i] << " " << v[i+2] << " " << (v[i+2]-v[i]) << " " << (v[i+2]-v[i] <= 1) << endl;
                // double temp = v[i+2] - v[i];
                // if (temp <= (double)1.00){
                    // ans.push_back(k);
                    // break;
                // }
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
