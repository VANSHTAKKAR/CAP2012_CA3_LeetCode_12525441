class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            int h;

            if (i == n) {
                h = 0;
            }
            else {
                h = heights[i];
            }

            while (!st.empty() && h < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                int area = height * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};
