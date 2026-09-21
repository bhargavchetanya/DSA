class Solution {
public:
    vector<int>countDigits(int n){
        vector<int>temp;
        while(n>0){
            temp.push_back(n%10);
            n/=10;
        }
        return temp;
    }

    int minimumSum(int num) {
        vector<int>numbers(4);
        numbers=countDigits(num);
        sort(numbers.begin(),numbers.end());
        return((numbers[0]*10+numbers[3])+(numbers[1]*10+numbers[2]));
    }
};