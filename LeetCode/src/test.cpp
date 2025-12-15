#include <bits/stdc++.h>

using namespace std;



int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, maxH = 0;
    int ans = 0;

    for(int right = 1; right < n; right++){
        while(left < maxH && height[left] * (n - 1 - left) < ans) left++;
        
        ans = max(max((right - left) * min(height[right], height[left]), 
                    (right - maxH) * min(height[right], height[maxH])), ans);
        
        if(height[right] > height[maxH]) maxH = right;

        cout<<"maxH: "<<maxH<<" "<<endl;
        cout<<"left: "<<left<<endl;
        cout<<"ans: "<<ans<<endl;
        cout<<"left limit: "<<height[left] * (n - 1 - left)<<endl;
        cout<<endl; 
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> height{1,2,4,3};
    maxArea(height);
}
