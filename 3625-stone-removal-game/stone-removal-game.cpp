class Solution {
public:
    bool canAliceWin(int n) {
        int m=10;
        bool flag=true;
        if(m>n)return false;
        while(m>0){
            if(m>n&&m%2==0){
                return false;
            }
            else if(m>n&&m%2!=0){
                return true;
            }
            n-=m;
            m-=1;
        }
        return true;
    }
};