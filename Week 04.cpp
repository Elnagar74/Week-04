// problem 01

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};

// problem 02

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (st.empty())
                st.push(s[i]);
            else {
                if (s[i] == st.top())
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        return s;
    }
};

// problem 03

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                else if (c == ')' && st.top() == '(')
                    st.pop();
                else if (c == '}' && st.top() == '{')
                    st.pop();
                else if (c == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

// problem 04

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        int p2 = 0;
        for (int p1 = 0; p1 < haystack.size(); p1++) {
            int temp = p1;
            while (haystack[p1] == needle[p2]) {
                p1++, p2++;
                if (p2 == needle.size())
                    return temp;
            }
            p1 = temp, p2 = 0;
        }
        return -1;
    }
};

// problem 05

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int prefix_product = 1;

        for (size_t i = 0; i < n; ++i) {
            ans[i] = prefix_product;
            prefix_product *= nums[i];
        }

        int suffix_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix_product;
            suffix_product *= nums[i];
        }
        return ans;

    }
};
