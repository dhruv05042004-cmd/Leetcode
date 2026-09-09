class Solution {
public:
    void backtrack(string curr, int open, int close, int n, vector<string>& res) {
        // Base case
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        // Add '('
        if (open < n) {
            backtrack(curr + '(', open + 1, close, n, res);
        }
        // Add ')'
        if (close < open) {
            backtrack(curr + ')', open, close + 1, n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }
};