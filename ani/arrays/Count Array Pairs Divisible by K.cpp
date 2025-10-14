//LC 1819. Count Pairs of Arrays Divisible by K
// https://leetcode.com/problems/count-pairs-of-arrays/
// Time Complexity: O(n)


class Solution {
public:
    int gcd(int a, int b) {
        if (a > b) {
            for (int i = a; i > 0; i--) {
                if (a % i == 0 && b % i == 0) {
                    return i;
                }
            }
        }
        if (b > a) {
            for (int i = b; i > 0; i--) {
                if (b % i == 0 && a % i == 0) {
                    return i;
                }
            }
        }
        if (b == a) {
            return b;
        }

        return 0;
    }

    long long countPairs(vector<int>& nums, int k) {
        long long count = 0;
        map<int, int> pairs;
        for (int i : nums) {
            int a = __gcd(i, k); // use pre-existing gcd function __gcd
            int want = k / a;
            for (auto it : pairs) {
                if (it.first % want == 0) {
                    count += it.second;
                }
            }
            pairs[a]++;
        }
        return count;
    }
};