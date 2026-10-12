class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>num(n,0);
        for(int i=0;i<n;i++){
            string s=words[i];
            int len=s.length();
            for(int j=0;j<len;j++){
                num[i]=(num[i]|(1<<(s[j]-'a')));
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((num[i]&num[j])==0){
                    int x=(words[i].length()*words[j].length());
                    maxi=max(maxi,x);
                }
            }
        }
        return maxi;
    }
};