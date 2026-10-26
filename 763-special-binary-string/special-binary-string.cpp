class Solution {
public:
    string makeLargestSpecial(string s) {
        int n=s.length();
        vector<string>ans;
        int count=0;
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            else count--;
            if(count==0){
                int end=i-1;
                string news=s.substr(start+1,end-start);
                ans.push_back('1'+makeLargestSpecial(news)+'0');
                start=i+1;
            }
        }
        sort(ans.rbegin(),ans.rend());
        string final="";
        for(int i=0;i<ans.size();i++){
            final+=ans[i];
        }
        return final;
    }
};