class Solution {
public:
    bool isPalindrome(int x) {
     int reversedNum = 0;
    
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    while (x > reversedNum) {
        reversedNum = reversedNum * 10 + x % 10;
        x = x / 10;
    }
    
    return x == reversedNum || x == reversedNum / 10;   
    }
};