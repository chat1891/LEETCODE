#include <vector>
#include <algorithm>

/*
Logic:
    - sort both time slots
    - get intersect start and end, if no overlapping, intersect difference <0;
    - if intersect difference >= duration, found match


Time Complexity:
O(N log N + M log M)
- M is length of slots1; N is length of slots 2
-  sort is O(N log N + M log M)
-  two pointers  take O(M+N)

Space Complexity: 
O(1)
*/
class Solution
{
public:
    std::vector<int> minAvailableDuration(std::vector<std::vector<int>>& slots1, std::vector<std::vector<int>>& slots2, int duration)
    {
        int idx1 = 0;
        int idx2 = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        while (idx1 < slots1.size() && idx2 < slots2.size())
        {
            int intersectStart = std::max(slots1[idx1][0], slots2[idx2][0]);
            int intersectEnd = std::min(slots1[idx1][1], slots2[idx2][1]);
            // if no overlapping, end-start <0
            if (intersectEnd - intersectStart >= duration)
            {
                return { intersectStart, intersectStart + duration };
            }
            else if (slots1[idx1][1] < slots2[idx2][1])
            {
                idx1++;
            }
            else
            {
                idx2++;
            }
        }

        return{};
    }
};