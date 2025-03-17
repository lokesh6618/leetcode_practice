#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n, 1);
    int prefix = 1;

    for(int i = 0; i < n; i++){
        result[i] = prefix;
        prefix *= nums[i];
    }

    int sufix = 1;

    for(int i = n-1; i > -1; i--){
        result[i] *= sufix;
        sufix *= nums[i];
    }

    for(auto item : result){
        cout << item << " , " ;
    }

    cout << endl;

    return result;
}

int main()
{   
    vector<int> nums = {1,2,3,4};

    auto final = productExceptSelf(nums);
    int result = 0;


    cout << "done testing" << endl;
    return 0;
}

