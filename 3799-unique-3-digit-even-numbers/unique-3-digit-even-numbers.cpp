class Solution {
public:
    void f(set<vector<int>>&s,vector<int>& digits,vector<int>&temp,vector<bool>&used){
        if(temp.size()==3){
            s.insert(temp);
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]==false){
                used[i]=true;
                temp.push_back(digits[i]);
                f(s,digits,temp,used);
                used[i]=false;
                temp.pop_back();
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        int count=0;
        int n=digits.size();
        set<vector<int>> s;
        vector<int>temp;
        vector<bool>used(n,false);
        for(int i=0;i<n;i++){
            if(digits[i]%2==0){
                used[i]=true;
                temp.push_back(digits[i]);
                f(s,digits,temp,used);
                used[i]=false;
                temp.pop_back();
            }
        }
        for(auto it:s){
            if(it[2]!=0)count++;
        }
        return count;
    }
};