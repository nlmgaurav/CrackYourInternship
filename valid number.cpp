class Solution {
public:
    bool isNumber(string s) 
    {
        int n = s.size();
        int i = 0;

        // Remove leading whitespaces
        while (i < n && isspace(s[i])) i++;

        // Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool isNumeric = false;
        bool isDotEncountered = false;
        bool isEEncountered = false;

        while (i < n) {
            char ch = s[i];

            if (isdigit(ch)) {
                isNumeric = true;
            } 
            else if (ch == '.') {
                if (isEEncountered || isDotEncountered) return false;
                isDotEncountered = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                if (isEEncountered || !isNumeric) return false;
                isEEncountered = true;
                isNumeric = false; 
            } 
            else if (ch == '+' || ch == '-') {
                if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } 
            else {
                break;
            }
            i++;
        }

        while (i < n && isspace(s[i])) i++;

        return isNumeric && i == n;
    }
};