class Solution {
public:
    int f(int a,int b){
        int a1=max(a,b);
        int b1=min(a,b);
        while(b1!=0){
            int r=a1%b1;
            a1=b1;
            b1=r;
        }
        return a1;
    }

    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int num1=0;
                int num2=nums[j]%10;
                string s1=to_string(nums[i]);
                s1=s1[0];
                num1=stoi(s1);
                if(f(num1,num2)==1)ans++;
            }
        }
        return ans;
    }
};