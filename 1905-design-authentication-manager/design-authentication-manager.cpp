class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive){
        ttl_=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        expires_[tokenId]=currentTime+ttl_;
    }
    
    void renew(string tokenId, int currentTime) {
        auto it=expires_.find(tokenId);
        if(it==expires_.end());
        else{
            if(currentTime<it->second){
                it->second=currentTime+ttl_;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto it:expires_){
            if(it.second>currentTime)count++;
        }
        return count;
    }

private:
    int ttl_;
    unordered_map<string,int>expires_;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */