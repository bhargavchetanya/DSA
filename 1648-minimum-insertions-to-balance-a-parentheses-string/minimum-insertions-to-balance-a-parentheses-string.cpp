class Solution {
public:
    int minInsertions(string s) {
        stack<char>left;
        stack<char>right;
        int ans=0;
        for(char c:s){
            if(c=='('){
                if(left.size()==0&&right.size()==0){
                    left.push(c);
                }
                else if(left.size()!=0&&right.size()==0){
                    left.push(c);
                }
                else if(left.size()==0&&right.size()!=0){
                    left.push(c);
                    right.pop();
                    ans+=2;
                }
                else if(left.size()!=0&&right.size()!=0){
                    ans++;
                    right.pop();
                }
            }
            else{
                if(left.size()==0&&right.size()==0){
                    right.push(c);
                }
                else if(left.size()!=0&&right.size()==0){
                    right.push(c);
                }
                else if(left.size()==0&&right.size()!=0){
                    right.pop();
                    ans+=1;
                }
                else if(left.size()!=0&&right.size()!=0){
                    left.pop();
                    right.pop();
                }
            }
        }
        int size1=left.size();
        int size2=right.size();
        if(size1==0&&size2!=0)return ans+=2;
        return ans+=abs(2*size1-size2);
    }
};