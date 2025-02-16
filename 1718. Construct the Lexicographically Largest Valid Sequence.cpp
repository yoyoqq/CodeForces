class Solution {
    public:
        vector<int> constructDistancedSequence(int target) {
            vector<int> res(target * 2 - 1, 0);
            vector<bool> used(target + 1, false);
            recursion(0, res, used, target);
            return res;
        }
    
    private:
        bool recursion(int idx, vector<int>& res, vector<bool>& used, int target) {
            // bas ecase
            if (idx == res.size()) {
                return true;
            }
            // if found skip 
            if (res[idx] != 0) {
                return recursion(idx + 1, res, used, target);
            }
            // go through all 
            for (int numberToPlace = target; numberToPlace >= 1;
                 numberToPlace--) {
                if (used[numberToPlace]) continue;
    
                used[numberToPlace] = true;
                res[idx] = numberToPlace;
                if (numberToPlace == 1) {
                    if (recursion(idx + 1, res, used, target)) {
                        return true;
                    }
                }
                else if (idx + numberToPlace < res.size() && res[idx + numberToPlace] == 0) {
                    res[idx + numberToPlace] = numberToPlace;
    
                    if (recursion(idx + 1, res, used, target)) {
                        return true;
                    }
                    res[idx + numberToPlace] = 0;
                }
                // undo 
                res[idx] = 0;
                used[numberToPlace] = false;
            }
    
            return false;
        }
    };