class Solution {
public:
    string removeDigit(string number, char digit) {
        int n =number.size();
        int last = 0;
        for (int i=0; i<n; i++) {
            if (number[i] == digit) {
                if (i == n - 1) return number.substr(0,n-1);
                if (number[i] < number[i+1]) return number.substr(0,i) + number.substr(i+1,n-i-1);
                if (number[i] > number[i+1]) last = i;
            }
        }
        return number.substr(0,last) + number.substr(last+1,n-last-1);
    }
};

/*
if there is only one matched digit => that is the one
else (i matched)
check if the i+1 is > i ? if yes than this is the one
if i+1 == i => count the next one, since the result is the same
if i+1 < i => def not


e.g. 7274717 target is 7
274717
724717
727417
727471
=> if all smaller, pick the last one 

how about
7737
737
737
773

7372
372
732


*/
