#include<bits/stdc++.h>
using namespace std;

int main() {
  int n = 7;
  int num[7];
  //vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i]; 
  }
  //  sort(nums.begin(), nums.end()); //nums smallest to largest order
  cout << nums[0] << " " <<  nums[1] << " " << nums[6] - nums[0] - nums[1] << endl;
  //int maxNum = nums[6];
  //for (int a = 1; a <= maxNum; ++a)
    //for (int b = a; b <= maxNum; ++b)
      //for (int c = b; c <= maxNum; ++c) {
         ////a, b, c, a + b, a + c, b + c, a + b + c
         ////nums[0] == a
         ////nums[1] == b 
         ////nums[2] == c? a + b?
         ////nums[6] == a + b + c =>nums[6] - nums[0] - nums[1] = c
         //if (nums[0] == a && nums[1] == b && nums[6] - nums[0] - nums[1] == c) {
           //cout << a << " " << b << " " << c << endl;
           //return 0;
         //}
      //}
}
