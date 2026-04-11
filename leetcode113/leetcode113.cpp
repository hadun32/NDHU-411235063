/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& ans); //因為在class裡面所以不用先宣告
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }

    void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& ans){
        if (node == nullptr){
            return;
        }

        path.push_back(node->val);
        targetSum = targetSum - node->val;// 把走過的目標金額扣掉

        if(node->left == nullptr && node->right == nullptr && targetSum == 0){
        ans.push_back(path);
        }//是葉節點，金額也剛好扣完
        else{
            dfs(node->left, targetSum, path, ans);
            dfs(node->right, targetSum, path, ans);
        }//還沒到盡頭，繼續往左邊和右邊走

        path.pop_back();//重新再來一次
    }
};