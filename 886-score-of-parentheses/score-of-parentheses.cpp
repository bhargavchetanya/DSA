class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int>levels(26,0);
        stack<int>st;
        int ans=0;
        int x=0;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]=='('){
                x++;
            }
            else{
                if(s[i-1]=='(')levels[x]++;
                else{
                    levels[x]+=2*(levels[x+1]);
                    levels[x+1]=0;
                }
                x--;
            }
            i++;
        }
        return levels[1];
    }
};