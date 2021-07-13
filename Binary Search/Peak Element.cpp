// Peak Element

#include <iostream>
using namespace std;

int findPeakElement(vector<int>& nums, int n) {
    int l = 0,h = n-1, mid;
    
    while(l <= h){
        mid = (l + h) >> 1;
        if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])){
            return mid;
        }
        else if(mid + 1 < n && nums[mid] < nums[mid + 1]){
            l= mid + 1;
        }
        else h = mid - 1;
    }

    return l; 
}

int main(){
    int n; cin >> n;
    std :: vector<int> nums;
    for(int i = 0;i < n; i++) cin >> nums[i];

    cout << findPeakElement(nums, n) << '\n';
}