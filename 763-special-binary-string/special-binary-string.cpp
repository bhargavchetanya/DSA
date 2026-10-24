class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>arr;
        int n=s.length();
        int count=0;
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')count++;
            else count--;
            if(count==0){
                string news=s.substr(start+1,i-start-1);
                arr.push_back('1'+makeLargestSpecial(news)+'0');
                start=i+1;
            }
        }
        string ans="";
        sort(arr.begin(),arr.end(),greater<>());
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
        }
        return ans;
    }
};