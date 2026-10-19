class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            for(auto c:words[i]){
                int m=c-'a';
                temp[i]|=(1<<(m));
            }
        }
        int target=0;
        target|=1<<(x-'a');
        vector<int>ans;
        for(int i=0;i<n;i++){
            if((temp[i]&target)!=0) ans.push_back(i);
        }
        return ans;
    }
};