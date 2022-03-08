class Solution {
    //https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
    //article https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/discuss/1830191/C%2B%2B-or-2-approach-or-left-start-O(n2)-and-right-start-O(n)?fbclid=IwAR3BI57HQSReU5hxmBnlNEJz9jJIkVN9smMpo-2dY-QFTtNKYTMLZxavQ-s
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5134393469916436/
public:
    vector<int> replaceElements(vector<int>& arr) {
        //Input:  [17,18, 5, 4, 6, 1]
        //Output: [18, 6, 6, 6, 1,-1]
        int max_val = -1;
        int n = arr.size();
        for(int i = n-1; i>=0;i--) { 
            if(arr[i]>max_val) {
                swap(arr[i],max_val);
            } else {
                arr[i] = max_val;
            }
        }
        return arr;        
    }
    
    vector<int> answer_lefttoright(vector<int>& arr) {
        //Input:  [17,18, 5, 4, 6, 1]
        //Output: [18, 6, 6, 6, 1,-1]
        int n = arr.size();
        int max_val, max_idx = 0;
        for(int i = 0; i<n; i++) {
            if(i>=max_idx) {
                max_val = -1;
                for(int j=i+1; j<n;j++) {
                    if(arr[j] > max_val) {
                        max_idx = j;
                        max_val = arr[j];
                    }
                }
            }
            arr[i] = max_val;            
        }
        return arr;
    }
    
};