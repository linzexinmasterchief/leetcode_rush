#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {};

        for (int i = 0; i < nums.size(); i ++){
            auto n1 = nums.at(i);
            for (int j = 0; j < nums.size(); j ++){
                if (i == j) continue;
                auto n2 = nums.at(j);
                if (n1 + n2 == target){
                    ans.insert(ans.end(), i);
                    ans.insert(ans.end(), j);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};

int main(void){
    vector<int> v = {1, 2, 3, 4};

    auto s = Solution();
    auto ans = s.twoSum(v, 5);
    for (int i = 0; i < ans.size(); i ++){
        cout << ans.at(i) << endl;
    }
    return 0;
}