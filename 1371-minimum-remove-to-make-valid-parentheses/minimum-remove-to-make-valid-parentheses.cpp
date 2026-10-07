class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string final="";
        int n=s.length();
        int open=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                final+='(';
                open++;
            }
            else if(s[i]==')'){
                if(open>close){
                    final+=')';
                    close++;
                }
                else{
                    continue;
                }
            }
            else{
                final+=s[i];
            }
        }
        int j=final.size()-1;  
        int o=0;
        int c=0;
        if(open>close){
            for(int i=final.size()-1;i>=0;i--){
                if(final[i]!='('&&final[i]!=')')continue;
                if(final[i]==')'){
                    c++;
                }
                else if(final[i]=='('){
                    if(o<c){
                        o++;
                    }
                    else{
                        final.erase(i,1);
                    }
                }
            }
        }
        return final;
    }
};