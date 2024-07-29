class Solution {
public:
    void left_Just(vector<string>& result, vector<string>& line, int currCharWidth, int maxWidth){
        string s = "";
        for(auto word : line){
            s += word + " ";
        }
        s.pop_back(); // Remove the last space. (Especially for cases where s.size() > maxWidth)
        while(s.size() < maxWidth)  // Fill up remaining spaces
            s += " ";
        result.push_back(s);
        return;
    }

    void full_Just(vector<string>& result, vector<string>& line, int currCharWidth, int maxWidth){
        string s = "";
        int count = line.size();
        if(count == 1){ // Only single word in the current line even if not the last line?  -> Left Justify 
            left_Just(result, line, currCharWidth, maxWidth);
            return;
        }

        int remainingSpaces = maxWidth - currCharWidth;
        int fixed = remainingSpaces / (count - 1);
        int extra = remainingSpaces % (count - 1);
        
        string blank(fixed, ' '); 
        string blank_p1(fixed + 1, ' '); 
        for(auto word : line){
            if(extra){
                s += word + blank_p1; // Extra spaces till the time there is no more variable space left
                extra--;
            }
            else {
                s += word + blank; // Fixed spaces
            }
        }
        while(s.size() > maxWidth) // Remove the extra spaces at the end
            s.pop_back();
        result.push_back(s);
        return;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int currCharWidth = 0; // Counts the total character size (For checking remaining spaces)
        int currWidth = 0; // Iterator going from 0 to maxWidth
        vector<string> line;
        int i = 0;
        while(i < words.size()){
            int size = words[i].size();
            if(currWidth + size - 1 < maxWidth){ // Does the word fit in the current line ? 
                line.push_back(words[i]);
                currWidth = currWidth + size + 1;
                currCharWidth += size;
                if(currWidth >= maxWidth){ // Does our pointer go out of bounds once we fit the last word?
                    if(i == words.size() - 1){ // Is this the last word? -> Left Justify
                        left_Just(result, line, currCharWidth, maxWidth);
                    }
                    else { // If not last word -> full Justify
                        full_Just(result, line, currCharWidth, maxWidth);
                    }
                    line.clear();
                    currWidth = 0;
                    currCharWidth = 0;
                }
                else {
                    if(i == words.size() - 1){ // If the pointer is within the bounds and we have already fit the last word in the line.
                        left_Just(result, line, currCharWidth, maxWidth); // Last word -> left justify
                        line.clear();
                        currWidth = 0;
                        currCharWidth = 0;
                    }
                }
                i++;
            }
            else { // If we cannot fit the current word in the line, full justify the current line.
                full_Just(result, line, currCharWidth, maxWidth);
                line.clear();
                currWidth = 0;
                currCharWidth = 0;
            }
        }
        return result;
    }
};