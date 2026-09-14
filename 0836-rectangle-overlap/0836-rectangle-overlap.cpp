class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
         if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }

        // Step 2: Check standard non-overlapping conditions
        if (rec1[2] <= rec2[0] || // rec1 is completely left of rec2
            rec1[0] >= rec2[2] || // rec1 is completely right of rec2
            rec1[3] <= rec2[1] || // rec1 is completely below rec2
            rec1[1] >= rec2[3])   // rec1 is completely above rec2 
        {
            return false; // They do not overlap
        }

        return true; // They overlap

    }
};