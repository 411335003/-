class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        for (int i = 0; i <= n2 - n1; i++) {
            if (s1_count == window_count) return true;
            if (i + n1 < n2) {
                window_count[s2[i] - 'a']--; 
                window_count[s2[i + n1] - 'a']++; 
            }
        }

        return false;
    }
};