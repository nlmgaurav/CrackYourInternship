class Solution {
public:
    string convertToTitle(int columnNumber) {
        string columnTitle = "";
        while (columnNumber) {
            columnTitle = char(((columnNumber - 1) % 26) + 'A') + columnTitle;
            columnNumber = (columnNumber - 1) / 26;
        }
        return columnTitle;
    }
};

/*apprch=>  it can be seen as conversion of decimal to binary where we continuosly divide 
number with 2 because base is 2(binary => 1/0)
but here it can be seen as base is 26 bcz alphabet has 26 letters*/
