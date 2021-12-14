
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto& num: nums) {
            if ( k<2 || num > nums[k-2]) {
                nums[k++] = num;
            }
        }
        return k;
    }
};



/*


K[] nums[]

int k = 0; 
int i = 0; 

for (int i; i < nums.size(); i++) {
	if ( k < 2) {
		K[k++] = A[i];
	} else if( K[k-2] < A[i]){
		K[k] = A[i]
		k++;
	}
}


Idea :
Research what number shouldn't put and observer its role                            
1 1 1 2 2 3 3 3 4 4 5 6 6 6 6 
    x         x           x x 

When i < 2 K[i] = A[i], k++, i++
When A[i] == K[k-2], then don't use --> i++ directly 
When A[i] == K[k-2], then use it, let K[k] == A[i].  k++, i++
*/