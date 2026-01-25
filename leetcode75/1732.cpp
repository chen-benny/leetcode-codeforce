class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        /*
         * Return the highest altitude of a point
         * gain[]: gain[i] is the net gain in altitude
         *
         * prefix-sum: gain[i] := net change, accum to altitude itself
         * need max altitude, trace state is enough
         * T: O(n), S: O(1)
         */
        int altitude = 0;
        int maxAltitude = 0;

        for (int g : gain) {
            altitude += g;
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};
