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
    //https://leetcode.com/problems/path-sum-iii/
public:
    int pathSum(TreeNode* root, int targetSum) {
        typedef long long ll;
        typedef function<void(void*)> runner_t;
        int ans = 0;
        function<void(TreeNode*,runner_t)> run_all_nodes = [&](TreeNode*root, runner_t runner){
            if(!root) return;
            runner(root);
            run_all_nodes(root->left, runner);
            run_all_nodes(root->right, runner);
        };
        
        function<void(TreeNode*,ll)> path_sum = [&](TreeNode*root, ll t){
            if(!root) return;
            ll new_t = t-(ll)root->val;
            if(new_t==0) ans++;
            path_sum(root->left, new_t);
            path_sum(root->right, new_t);
        };
        
        runner_t runner=[&](void*p){  
            path_sum((TreeNode*)p,(ll)targetSum); 
        };
        
        run_all_nodes(root, runner);
        return ans;        
    }

    int pathSum_multithread(TreeNode* root, int targetSum) {
        mutex m;
        mutex mt;
        typedef long long ll;
        typedef function<void(void*)> runner_t;
        vector<thread> threads;
        
        int ans = 0;
        function<void(TreeNode*,runner_t)> run_all_nodes = [&](TreeNode*root, runner_t runner){
            if(!root) return;
            runner(root);
            run_all_nodes(root->left, runner);
            run_all_nodes(root->right, runner);
        };
        
        function<void(TreeNode*,ll)> path_sum = [&](TreeNode*root, ll t){
            if(!root) return;
            ll new_t = t-(ll)root->val;
            if(new_t==0) {
                m.lock();
                ++ans;
                m.unlock();
            }
            path_sum(root->left, new_t);
            path_sum(root->right, new_t);
        };
        
        runner_t runner=[&](void*p){  
            mt.lock();
            threads.push_back(thread(path_sum,(TreeNode*)p,(ll)targetSum));        
            mt.unlock();
            //path_sum((TreeNode*)p,(ll)targetSum); 
        };
        run_all_nodes(root, runner);
        
        for(auto &thread:threads) thread.join();
        
        return ans;        
    }
};