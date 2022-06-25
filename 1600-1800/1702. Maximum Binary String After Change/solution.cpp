class Solution {
public:
    string maximumBinaryString(string binary) {
        int zeros = 0, ones = 0;
        for (auto& c: binary) {
            if (c == '0') {
                zeros++;
                c = '1';
            } else if (zeros == 0) {
                ones++;
            }
        }
        if (ones<binary.size()) 
            binary[ones+zeros-1] = '0';
        
        return binary;
    }
};

/*
as long there is 0 to the right of current 0, you can make the current 0 => 1
=> there will be only 1 0 left => the 


1. flipped all to the right => 000....001111
2. flipped all possible to the left => 111....110111
*/
