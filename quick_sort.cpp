#include <vector>
#include<iostream>
using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if(r-l <= 1) return;
    int picked = rand()%(r-l) + l;
    swap(nums[l], nums[picked]);
    int pivot = nums[l], i = l, j = r-1;
    while(i < j) {
        while(i < j && nums[j] > pivot) j--;
        if(i < j) {
            nums[i++] = nums[j];
        }
        while(i < j && nums[i] <= pivot) i++;
        if(i < j) {
            nums[j--] = nums[i];
        }
    }
    nums[i] = pivot;
    quick_sort(nums, l, i);
    quick_sort(nums, i + 1, r);
}