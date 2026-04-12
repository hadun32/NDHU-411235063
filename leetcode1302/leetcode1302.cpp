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
    int deepestLeavesSum(TreeNode* root) {
        int maxD = 0;//D==深度
        int ans = 0;
        dfs(root, 0, maxD, ans);//初始深度=0
        return ans;
    }

private:
    void dfs(TreeNode* node, int nowD, int& maxD, int&ans){
        if(node == nullptr){
            return;
        }

        if(node->left == nullptr && node->right == nullptr){//是不是葉節點
            if(nowD>maxD){
                maxD = nowD;
                ans = node->val;
            }
            else if(nowD == maxD){
            ans+=node->val;
            }
        }
        else { //不是就繼續走
            dfs(node->left, nowD + 1, maxD, ans);
            dfs(node->right, nowD + 1, maxD, ans);
        }
    }    
};