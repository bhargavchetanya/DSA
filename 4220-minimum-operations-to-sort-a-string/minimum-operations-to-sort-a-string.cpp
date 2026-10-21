class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(n==2&&s[0]>s[1])return -1;
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s)return 0;
        else{
            temp=s.substr(0,n-1);
            sort(temp.begin(),temp.end());

            if(temp==s.substr(0,n-1)){
                if(s[n-1]<temp[0]&&s[n-1]<temp[n-2]){
                    return 2;
                }
                if(s[n-1]>=temp[0]){
                    return 1;
                }
                else{
                    return -1;
                }
            }
            else{
                string temp2=s.substr(1,n);
                sort(temp2.begin(),temp2.end());
                if(s[n-1]>=s[0]&&temp[0]==s[0])return 1;
                if(s[n-1]>=temp[n-2])return 1;
                if(s[0]<=temp2[n-2])return 2; 
                if(s[n-1]>=temp[0]){
                    return 2;
                }
                if(s[n-1]<temp[0]&&s[n-1]<temp[n-2]){
                    return 3;
                }
                else{
                    return -1;
                }
            }
        }
    }
};