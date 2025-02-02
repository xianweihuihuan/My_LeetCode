class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ret;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int tmp = numbers[left] + numbers[right];
            if (tmp < target)
            {
                left++;
            }
            else if (tmp > target)
            {
                right--;
            }
            else
            {
                ret.push_back(left);
                ret.push_back(right);
                return ret;
            }
        }
        return ret;
    }
};