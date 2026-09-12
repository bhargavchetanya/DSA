class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        vector<long long> ans;
        while(x!=0){
            ans.push_back(x%10);
            x=x/10;
        }
        int start=0;
        int end = ans.size()-1;
        while(start<end){
            if(ans[start]!=ans[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};