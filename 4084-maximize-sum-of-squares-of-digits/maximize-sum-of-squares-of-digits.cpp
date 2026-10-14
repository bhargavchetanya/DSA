class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int count=0;
        while(sum>=9&&count<num){
            ans.push_back('9');
            count++;
            sum-=9;
        }
        if(sum>0&&count<num){
            ans.push_back(char('0'+sum));
            sum=0;
            count++;
        }
        while(count<num&&sum==0){
            ans.push_back('0');
            count++;
        }
        if(count==num&&sum==0)return ans;
        return "";
    }
};