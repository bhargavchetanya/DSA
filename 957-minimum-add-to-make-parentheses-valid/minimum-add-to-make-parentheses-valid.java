class Solution {
    public int minAddToMakeValid(String s) {
        int first=0;
        int second=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                first++;
            }
            else{
                second++;
                if(second>first){
                    ans++;
                    second--;
                }
            }
        }
        ans+=first-second;
        return ans;
    }
}