class Solution {
public:

    char solve(int a,int i){
        if(a==1&&i==0) return 'I';
        if(a==5&& i==0) return 'V';
        if(a==1&&i==1) return 'X';
        if(a==5&&i==1) return 'L';
        if(a==1&&i==2) return 'C';
        if(a==5&&i==2) return 'D';
        if(a==1&&i==3) return 'M';
        return 's';
    }

    string intToRoman(int num) {
        int a=0;
        string ans;
        int i=0;
        while(num!=0){
            a=num%10;
            if(a==0){
                i++;
                num=num/10;
                continue;
            }
            if(a==4){
                ans.push_back(solve(5,i));
                ans.push_back(solve(1,i));
                i++;
                num=num/10;
                continue;
            }
            if(a==9){
                ans.push_back(solve(1,i+1));
                ans.push_back(solve(1,i));
                i++;
                num=num/10;
                continue;
            }
            if(a<4){
                for(int j=0;j<a%5;j++){
                    ans.push_back(solve(1,i));
                }
                i++;
                num=num/10;
                continue;
            }
            if(a==5){
                ans.push_back(solve(a,i));
                i++;
                num=num/10;
                continue;
            }
            if(a<9){
                for(int j=0;j<a%5;j++){
                    ans.push_back(solve(1,i));
                }
                ans.push_back(solve(5,i));
                i++;
                num=num/10;
                continue;
            }


        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};