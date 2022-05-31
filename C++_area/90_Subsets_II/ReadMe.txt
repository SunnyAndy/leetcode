

main logic is coming from the  Subset I 

https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50

golden version from leet code 

class Solution_g {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(begin(nums), end(nums));
    dfs(nums, 0, {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, int s, vector<int>&& path,
           vector<vector<int>>& ans) {
    ans.push_back(path);

    for (int i = s; i < nums.size(); ++i) {
      if (i > s && nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      dfs(nums, i + 1, move(path), ans);
      path.pop_back();
    }
  }
};



