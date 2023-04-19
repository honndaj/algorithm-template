#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int>& nums, int l, int r, vector<int>& t){
    if(r-l <= 1) return;
    int mid = (l+r)>>1, i = l, j = mid, x = l;
    merge_sort(nums, l, mid, t);
    merge_sort(nums, mid, r, t);
    while(i < mid && j < r) {
        if(nums[i] <= nums[j]) {
            t[x++] = nums[i++];
        }
        else t[x++] = nums[j++];
    }
    while(i < mid) t[x++] = nums[i++];
    while(j < r) t[x++] = nums[j++];
    for(int x = l; x < r; x++) nums[x] = t[x];
}