class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>st;
        for(int i=0;i<k;i++)st.insert(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>cnt(k,0);
        for(int i=0;i<arrival.size();i++){
            while(!pq.empty() && pq.top().first<=arrival[i]){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty())continue;
            auto it=st.lower_bound(i%k);
            if(it==st.end())it=st.begin();
            int server=*it;
            cnt[server]++;
            st.erase(it);
            pq.push({arrival[i]+load[i],server});
        }
        int maxi=*max_element(cnt.begin(),cnt.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(cnt[i]==maxi)ans.push_back(i);
        }
        return ans;
    }
};