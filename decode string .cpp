string decodeString(string s)
{
    string ans = "";
    int num = 0;
    stack<pair<string, int>> stk; // Stack to store the string between [] and the number of times it needs to be generated
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
            num = (num * 10) + (s[i] - 48); // Since the number can be 2 digit or more we are generating the number
        else if (isalpha(s[i]))             // IF given character is al[habet we build the string
            ans += s[i];
        else if (s[i] == '[') // The moment the first [ is encountered we push the substring and the number generated to the stack
        {
            stk.push({ans, num});
            ans = ""; // making the substring variable blank and number zero to prepare it for the next iteration
            num = 0;
        }
        else if (s[i] == ']') // As a ] is encountered we generate the given substring according to 'k' times given on stack top.We add the string at stack top and generated string so that it may be processed again if required
        {
            string tmp = ans;
            for (int i = 1; i < stk.top().second; i++)
                tmp += ans;
            ans = stk.top().first + tmp;
            stk.pop();
        }
    }

    return ans;
}