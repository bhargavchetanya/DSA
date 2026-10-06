class Solution {
public:
    int minAddToMakeValid(string s) {
        int first=0;
        int second=0;
        int ans=0;
        for(char c:s){
            if(c=='('){
                first++;
            }
            else{
                second++;
            }
            if(second>first){
                ans++;
                second--;
            }
        }
        if(first>second)ans+=first-second;
        return ans;
    }
};