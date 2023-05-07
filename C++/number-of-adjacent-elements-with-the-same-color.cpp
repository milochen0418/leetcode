class Solution {
    //https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> A = vector<int>(n,0);
        int m = queries.size();
        vector<int> ans = vector<int>(m,0);
        int prev_ans=0;
        for(int i = 0; i<m;i++) {
            vector<int> &q = queries[i];
            int index = q[0];
            int color = q[1];//new color
            if(color==A[index]) {//case new color the same as to the old color
                ans[i] = prev_ans;
                continue;
            }
            /*
            printf("i=%d old =>",i);
            for(int j=0;j<n;j++) {
                printf("%d,",A[j]);
            }
            printf("\n");
            */
            int old_color = A[index];
            A[index] = color; 
            /*
            printf("i=%d new =>",i);
            for(int j=0;j<n;j++) {
                printf("%d,",A[j]);
            }
            
            */
            
            
            
            if( (index-1<0 || A[index-1] == 0)&&(index+1>=n || A[index+1]==0)) {
                ans[i] = prev_ans; 
            } else if(index-1<0 || A[index-1] == 0) {
                if(A[index+1]==old_color) {
                    ans[i] = prev_ans-1;
                } else if(A[index+1]==A[index]){
                    ans[i] = prev_ans+1;
                } else {
                    ans[i] = prev_ans;
                }
            } else if(index+1>=n || A[index+1]==0) {
                if(A[index-1]==old_color) {
                    ans[i] = prev_ans-1;
                } else if(A[index-1]==A[index]){
                    ans[i] = prev_ans+1;
                } else {
                    ans[i] = prev_ans;
                }
            } else {
                if(A[index-1] == A[index+1]) {
                    printf("[case 1?1]");
                    int side_color = A[index+1];
                    if(side_color == old_color) { 
                        ans[i] = prev_ans - 2;
                    } else if(side_color == A[index]){
                        ans[i] = prev_ans + 2;
                    } else {
                        ans[i] = prev_ans;
                    }
                } else {
                    //1?2
                    printf("[case 1?2]");
                    int cnt = 0;
                    
                    if(old_color == A[index-1] || old_color == A[index+1]) {
                        cnt=cnt-1;//cnt -1 because old_color cannot contributed now
                    } 
                    if(A[index] == A[index-1] || A[index] == A[index+1]) {
                        cnt=cnt+1;//cnt +1 because new_color can contributed now
                    }
                    ans[i] = prev_ans+cnt;
                }
            }
            
            
            printf("\n");
            prev_ans = ans[i];
        }       
        return ans;
    }
    
    /*
    vector<int> colorTheArray_WrongUnderstandQuestion(int n, vector<vector<int>>& queries) {
        vector<int> A = vector<int>(n,0);
        int m = queries.size();
        vector<int> ans = vector<int>(m,0);
        int prev_ans=0;
        for(int i = 0; i<m;i++)  {
            
            vector<int> &q = queries[i];
            int index = q[0];
            int color = q[1];//new color
            if(color==A[index]) {//case new color the same as to the old color
                ans[i] = prev_ans;
                continue;
            }
            
            int old_color = A[index];
            A[index] = color; 
            
            //case no left (left color 0) and no right(right color 0)
            if( (index-1<0 || A[index-1] == 0)&&(index+1>=n || A[index+1]==0)) {
                ans[i] = prev_ans; 
            }
            //case no left or left's color is 0
            else if(index-1<0 || A[index-1] == 0) {
                if(old_color!=A[index+1] && A[index] != A[index+1]){
                    ans[i] = prev_ans;
                } else if(index+2<n && A[index+2] == A[index+1]){
                    ans[i] = prev_ans;
                } else {
                    if(old_color==A[index+1]) {
                        ans[i] = prev_ans-1;
                    } else {////A[index]==A[index+1]
                        ans[i] = prev_ans+1;
                    }                    
                }
            } 
            //case no right or right's color is 0
            else if(index+1>=n || A[index+1]==0) {
                if(old_color!=A[index-1] && A[index] != A[index-1]){ 
                    ans[i] = prev_ans;
                } else if(index-2>=0 && A[index-2] == A[index-1]){
                    ans[i] = prev_ans;
                } else {
                    if(old_color==A[index-1]) {
                        ans[i] = prev_ans-1;
                    } else {//A[index]==A[index-1]
                        ans[i] = prev_ans+1;
                    }                                        
                }
            } 
            //case right and left have been colored
            else {
                if(old_color !=A[index-1] && old_color != A[index+1]
                  && A[index] !=A[index-1] && A[index] != A[index+1]) {
                    ans[i] = prev_ans;  
                } else {
                    int no_left_influent = 0;
                    int no_right_influent = 0;
                    if(index-2>=0 && A[index-2] == A[index-1]) no_left_influent = 1;
                    if(index+2< n && A[index+2] == A[index+1]) no_right_influent= 1;
                    if(no_left_influent && no_right_influent) {
                        if(A[index-1] == A[index+1]) {
                            if(A[index] == A[index-1]) 
                                ans[i] =prev_ans-1;
                            else
                                ans[i] =prev_ans+1;
                        } else {
                            ans[i] = prev_ans;
                        } 
                    } else if(no_left_influent) {
                        if(old_color == A[index+1]) {
                            ans[i] = prev_ans-1;
                        } else if(A[index] == A[index+1]) {
                            ans[i] = prev_ans+1;
                        } else {
                            ans[i] = prev_ans;    
                        }
                    } else if(no_right_influent) {
                        if(old_color == A[index-1]) {
                            ans[i] = prev_ans-1;
                        } else if(A[index] == A[index-1]) {
                            ans[i] = prev_ans+1;
                        } else {
                            ans[i] = prev_ans;    
                        }
                    } else {//left and right will both influent
                        if(A[index-1] == A[index+1]) {//1?1
                            if(i==4) printf("go to 1?1 case\n");
                            int side_color=A[index+1];
                            if(side_color == old_color) {
                                ans[i] = prev_ans-1;
                            } else if(side_color==A[index]){
                                ans[i] = prev_ans+1;
                            } else {
                                ans[i] = prev_ans;
                            }
                        } else {
                            //1?2
                            int cnt = 0;
                            if(old_color == A[index-1] || old_color != A[index+1]) {
                                cnt-1;//cnt -1 because old_color cannot contributed now
                            } 
                            if(A[index] == A[index-1] || A[index] == A[index+1]) {
                                cnt+1;//cnt +1 because new_color can contributed now
                            }
                            ans[i] = prev_ans+cnt;
                        }
                    }
                    
                }
            }
            prev_ans = ans[i];            
        }
            
        return ans;
    }
    */
};