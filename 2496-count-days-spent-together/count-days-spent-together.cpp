class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days={31,28,31,30,31,30,31,31,30,31,30,31};
        int aam=stoi(arriveAlice.substr(0,2));
        int alm=stoi(leaveAlice.substr(0,2));
        int bam=stoi(arriveBob.substr(0,2));
        int blm=stoi(leaveBob.substr(0,2));
        int aad=stoi(arriveAlice.substr(3,2));
        int ald=stoi(leaveAlice.substr(3,2));
        int bad=stoi(arriveBob.substr(3,2));
        int bld=stoi(leaveBob.substr(3,2));
        pair<int,int>miniarrive;
        pair<int,int>minileave;
        if(aam>bam){
            miniarrive={aam,aad};
        }
        else if(aam==bam){
            if(aad>bad)miniarrive={aam,aad};
            else miniarrive={bam,bad};
        }
        else{
            miniarrive={bam,bad};
        }
        if(alm<blm){
            minileave={alm,ald};
        }
        else if(alm==blm){
            if(ald<bld)minileave={alm,ald};
            else minileave={blm,bld};
        }
        else{
            minileave={blm,bld};
        }
        if(miniarrive.first>minileave.first)return 0;
        else if(miniarrive.first==minileave.first){
            if(miniarrive.second<=minileave.second){
                return minileave.second-miniarrive.second+1;
            }
            else return 0;
        }
        else{
            int day=0;
            for(int i=miniarrive.first+1;i<minileave.first;i++){
                day+=days[i-1];
            }
            day+=days[miniarrive.first-1]-miniarrive.second+1;
            day+=minileave.second;
            return day;
        }
        return 0;
    }
};