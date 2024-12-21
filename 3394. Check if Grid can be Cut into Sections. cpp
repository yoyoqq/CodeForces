class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, bool>> horizontal; 
        vector<pair<int, bool>> vertical;

        for (const auto& rectangle : rectangles) {
            int sx = rectangle[0]; 
            int sy = rectangle[1]; 
            int ex = rectangle[2]; 
            int ey = rectangle[3]; 

            horizontal.push_back({sx, true}); 
            horizontal.push_back({ex, false});  
            vertical.push_back({sy, true});  
            vertical.push_back({ey, false});    
        }
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());

        return line_sweep(horizontal, rectangles.size()) || line_sweep(vertical, rectangles.size());
    }

private:
    bool line_sweep(const vector<pair<int, bool>>& arr, int totalRectangles) {
        int opened = 0;         
        int sectionCount = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
            int pos = arr[i].first;
            bool isClose = arr[i].second;
            if (isClose) {
                opened++;
            } else {
                opened--;
            }

            if (opened == 0) { 
                sectionCount++;
            }
            // cout << pos << " " << isClose << " " << opened << endl;
        }
        // cout << sectionCount << endl;
        return (sectionCount >= 3);
    }
};