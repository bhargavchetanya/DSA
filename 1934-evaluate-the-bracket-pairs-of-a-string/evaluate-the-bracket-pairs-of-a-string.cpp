class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        int left=0;
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        int n=s.length();
        while(left<n){
            while(left<n&&s[left]!='('){
                ans+=s[left];
                left++;
            }
            if(left==n)break;
            string temp="";
            if(s[left]=='(')left++;
            while(left<n&&s[left]!=')'){
                temp+=s[left];
                left++;
            }
            if(s[left]==')')left++;
        if(mp.find(temp)==mp.end())ans+='?';
        else ans+=mp[temp];
        }
        return ans;
    }
};