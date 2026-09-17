class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int n=tokens.size();
        int left=0;
        int right=n-1;
        int absmax=0;
        while(left<n&&right<n&&left<=right){
            if(tokens[left]<=power){
                ans+=1;
                power-=tokens[left];
                left++;
            }
            else{
                if(ans<1)break;
                ans-=1;
                power+=tokens[right];
                right--;
            }
            absmax=max(ans,absmax);
        }
        return absmax;
    }
};