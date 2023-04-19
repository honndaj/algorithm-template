#include <vector>
using namespace std;

//区间左闭右开
//找到第一个大于等于x的
int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l+r)>>1;
            if(target <= nums[mid]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }

//找到第一个大于x的
int upper_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l < r) {
        int mid = (l+r)>>1;
        if(target < nums[mid]){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}