class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            vector<string> ans;
            // set<string> recipe; for(auto& rec : recipes) recipe.insert(rec); 
            set<string> supply; for(auto& sup : supplies) supply.insert(sup);
            bool flag = true;
            // supply size needs to inc each it 
            while (flag){
                bool found_ing = false;
                // for each recipe check if we have all 
                for (int i=0; i<n; i++){
                    if (recipes[i] == "#") continue;
                    int count = 0;
                    for (int j=0; j<ingredients[i].size(); j++){
                        if (supply.find(ingredients[i][j]) != supply.end()) count++;
                    }
                    // cout << recipes[i] << " " << count << endl;
                    if (count == ingredients[i].size()){
                        ans.push_back(recipes[i]);
                        supply.insert(recipes[i]);
                        recipes[i] = "#";
                        found_ing = true;
                    }
                }
                flag &= found_ing;
            }
            return ans;
        }
    };