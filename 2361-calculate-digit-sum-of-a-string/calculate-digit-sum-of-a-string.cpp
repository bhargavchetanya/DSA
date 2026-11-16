class Solution {
public:
    string digitSum(string s, int k) {
        string ans = "";
        if(s.length()<=k)return s;
        while (s.length() > k) {
            int n=s.length();
            queue<int> q;
            for (int i = 0; i < n; i++) {
                q.push(s[i] - '0');
            }
            ans = "";
            int x = q.size() / k;
            int rem = (q.size()) % k;
            for (int i = 0; i < x; i++) {
                int count = 0;
                int temp = 0;
                while (count < k) {
                    temp += q.front();
                    q.pop();
                    count++;
                }
                ans += to_string(temp);
            }
            if(rem>0){
                int temp = 0;
                for (int i = 0; i < rem; i++) {
                    temp += q.front();
                    q.pop();
                }
            ans += to_string(temp);
            }
            s = ans;
        }
        return ans;
    }
};