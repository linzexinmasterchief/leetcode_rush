//https://leetcode-cn.com/problems/reverse-integer
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int new_num = 0;
        while (abs(x) > 0){
            int digit = x % 10;
            x = x / 10;
            if (new_num > INT_MAX / 10 || new_num < INT_MIN / 10){
                new_num = 0;
            }else{
                new_num = new_num * 10 + digit;
            }
            
        }
        if (new_num < -pow(2, 31) || new_num > pow(2, 31) - 1){
            new_num = 0;
        }
        return new_num;
    }
};

int main(){
    Solution s = Solution();
    int ans = s.reverse(1929384);
    cout << ans << endl;
    return 0;
}