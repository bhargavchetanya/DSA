class TimeMap {
public:
    map<string,set<pair<int,string>>>mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }

    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";

        auto &s=mp[key];

        for(auto it=s.rbegin();it!=s.rend();it++){
            if(it->first<=timestamp)
                return it->second;
        }

        return "";
    }
};