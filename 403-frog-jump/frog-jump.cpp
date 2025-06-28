class Solution {
public:
    int dp[2001][2001];
    map<int, int> pos;
    int n;
    vector<int> stone;
    bool rec(int x, int k) {
        if (x >= n)
            return false;
        if (x == n - 1)
            return true;
        if (dp[x][k] != -1)
            return dp[x][k];
        bool ans = false;
        for (int i = -1; i < 2; i++) {
            if (i + k > 0 && pos.count(stone[x] + i + k))
                ans |= rec(pos[stone[x] + i + k], i + k);
        }
        dp[x][k] = ans;
        return ans;
    }
    bool canCross(vector<int>& stones) {
        stone = stones;
        n = stones.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
            pos[stones[i]] = i;
        return rec(0, 0);
    }
};