class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int outer=0;
        for(char c:s){
            if(c=='('){
                outer++;
                if(outer==1)continue;
                ans+=c;
            }
            else{
                if(outer==1){
                    outer--;
                    continue;
                }
                outer--;
                ans+=c;
            }
        }
        return ans;
    }
};