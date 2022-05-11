//solution 1
//time: O(n)
//space: O(1)
class Solution {
public:
    int countVowelStrings(int n) {
        array<int, 5> vowels;
        fill(vowels.begin(),vowels.end(),1);
        while (n--) {
            for (int i=1; i<vowels.size(); i++) {
                vowels[i] += vowels[i-1];
            }
        }
        return vowels.back();
    }
};



