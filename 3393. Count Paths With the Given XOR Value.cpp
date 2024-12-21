class Solution {
public:
    const int MOD = 1e9 + 7;
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}};

    struct State {
        int x, y, xr;
        bool operator==(const State& other) const {
            return x == other.x && y == other.y && xr == other.xr;
        }
    };

    struct HashFunction {
        size_t operator()(const State& state) const {
            return hash<int>()(state.x) ^ hash<int>()(state.y << 10) ^ hash<int>()(state.xr << 20);
        }
    };

    unordered_map<State, int, HashFunction> memo;

    int dp(const vector<vector<int>>& grid, int k, int xr, int x, int y) {
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        if (x == n && y == m) {
            return (xr == k) ? 1 : 0;
        }

        State state = {x, y, xr};
        if (memo.find(state) != memo.end()) {
            return memo[state];
        }

        int count = 0;
        for (const auto& [dx, dy] : dir) {
            int xx = x + dx, yy = y + dy;
            if (xx <= n && yy <= m) {
                count = (count + dp(grid, k, xr ^ grid[xx][yy], xx, yy)) % MOD;
            }
        }

        memo[state] = count;
        return count;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        return dp(grid, k, grid[0][0], 0, 0);
    }
};
