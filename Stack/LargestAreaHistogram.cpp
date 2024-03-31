#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallestElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}
vector<int> prevSmallestElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallestElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallestElement(heights, n);

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int area = l * b;
        cout << next[i] << prev[i] << endl;
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {0, 9};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
