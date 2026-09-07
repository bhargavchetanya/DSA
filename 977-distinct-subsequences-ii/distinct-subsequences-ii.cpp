class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        vector<long long>freq(26,0);
        int ans=0;
        for(char c:s){
            int news=(ans+1)%mod;
            ans=(ans+news-freq[c-'a']+mod)%mod;
            freq[c-'a']=news;
        }
        return ans;
    }
};