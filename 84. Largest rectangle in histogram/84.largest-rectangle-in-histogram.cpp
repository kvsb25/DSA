class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st; // [{index, val}]
        int ans = 0; // max area
        int n = heights.size();

        for(int i = 0; i<n; i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){

                auto [index, val] = st.top();
                st.pop();
                ans = max(ans, val*(i-index));

                start = index;
            }
            st.push({start, heights[i]});
        }

        // for bars that can be extended till the last of the input histogram
        // the stack will be filled with those bars because we never encountered a smaller bar than them.
        while(!st.empty()){
            auto [index, val] = st.top();
            st.pop();
            ans = max(ans, val*(n-index));
        }

        return ans;
    }
};

// Intuition:
// We keep bars in increasing height order so every bar in stack is still "expandable" to the right.
// The moment a smaller bar appears, it means taller bars cannot extend further — so we finalize
// their maximum rectangle using current index as the right limit and the stored start as left limit.
// The `start` variable carries the left boundary backward, ensuring each bar remembers how far it
// can extend left when shorter bars are removed.







//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// the bar which can be extended further is pushed into the stack with its starting index. 
// the bar cannot be extended if its next bar is smaller than it. 
// If we don't know what is next we just push to stack assuming that the bar can be extended. 
// So, at each index we are at (of the input array) the stack tells us what all bars can be extended till that index. 
// To verify that those bars can be extended till the current index, we compare the bar at the current index with the 
// one on top of the stack: 
//      1. if it is larger than the st.top() bar [curr>st.top()] this means that st.top() can be further extended, so we push it into the stack. We also push it into the stack because we don't know what what's next (assuming the current can also be extended). 
//      2: if it is smaller than st.top(), we compute areas for all those bars that can be extended till the current. So, we pop and compute the area (for all the bars that can be extended till the current) until the current becomes larger or equal to st.top(). We make the starting index of current equal to the starting index of the most recently poped element (after which the current became greater than st.top()) as current could be extended till that index from it's curr index (in the left direction).