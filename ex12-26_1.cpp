class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int ret = 0;
        for (auto &e : tokens)
        {
            if ("+" == e || "-" == e || "*" == e || "/" == e)
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (e[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else
            {
                st.push(stoi(e));
            }
        }
        return st.top();
    }
};