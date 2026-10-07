class Solution {
public:
    void f(int i,set<string>&ans,string temp,int open,int close,
           int l,int r,string &s){
        if(i==s.size()){
            if(l==0&&r==0&&open==close)
                ans.insert(temp);
            return;
        }
        if(s[i]!='('&&s[i]!=')'){
            f(i+1,ans,temp+s[i],open,close,l,r,s);
            return;
        }
        if(s[i]=='('){
            if(l>0)
                f(i+1,ans,temp,open,close,l-1,r,s);

            f(i+1,ans,temp+'(',open+1,close,l,r,s);
        }
        else{
            if(r>0)
                f(i+1,ans,temp,open,close,l,r-1,s);

            if(close<open)
                f(i+1,ans,temp+')',open,close+1,l,r,s);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string>ans;
        int l=0,r=0;
        for(char x:s){
            if(x=='(')
                l++;
            else if(x==')'){
                if(l>0)
                    l--;
                else
                    r++;
            }
        }
        f(0,ans,"",0,0,l,r,s);
        return vector<string>(ans.begin(),ans.end());
    }
};