class SparseVector {
    //https://leetcode.com/problems/dot-product-of-two-sparse-vectors
public:
    vector<int> *pV;
    int n;
    SparseVector(vector<int> &nums) {
        pV = &nums;
        n = nums.size();
    }
    
    vector<int>& getVector() {
        vector<int> &v = *pV;
        return v;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<int> &v = *pV;
        vector<int> &w = vec.getVector();
        
        int ans = 0; 
        for(int i = 0; i < n; i++) {
            ans += v[i] * w[i];
        }
        return ans; 
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);