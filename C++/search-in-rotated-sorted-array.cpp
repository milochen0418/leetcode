
class Solution {
  // https://leetcode.com/problems/search-in-rotated-sorted-array
  public static int[] a = null;   
  public int search(int[] nums, int target) {
    int L = 0;
    int R = nums.length - 1; 
    int t = target; 
    a = nums;
    return rotSearch(L, R, t);
  }
   
  public int binSearch(int L, int R, int t) {
    if (L > R) return -1;
    if (t < a[L] || t > a[R]) return -1;
    int M = (L + R) / 2;
    if (a[M] < t) return binSearch(M + 1, R, t);
    if (t < a[M]) return binSearch(L, M - 1, t);
    return M; // case  (a[M] == t)
  }
  
  public int rotSearch(int L, int R, int t) {
    if (L > R) return -1;
    int M = (L + R) / 2;
    if (a[M] == t) return M;
        
    //case 1
    if (a[L] <= a[M] && a[M] <= a[R]) {
      if (a[L] <= t && t <= a[R]) {
        return binSearch(L, R, t);
      } else {
        return -1;
      }  
    } else {
      //case 2   

      if (a[L] <= a[M] && a[R] <= a[L]) {
        if (a[L] <= t && t <= a[M]) {
          //return rotSearch(L, M - 1, t);
            return binSearch(L, M - 1, t);
        } else {
          return rotSearch(M + 1, R, t);  
        }
      }    
      //case 3
      if (a[M] <= a[R] && a[L] >= a[R]) {
        if (a[M] <= t && t <= a[R]) {
          //return rotSearch(M + 1, R, t);
            return binSearch(M + 1, R, t);
        } else {
          return rotSearch(L, M - 1, t);
        }
      }  
      //case otherwise      
      return -2; //Un-expected Error. 
    }    
  }
}