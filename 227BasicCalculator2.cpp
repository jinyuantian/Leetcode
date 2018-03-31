class Solution {
public:
    int calculate(string s) {
        stack<char> operator_stack;
        stack<int> num_stack;
        int i = 0;

        while(i < s.size()){

            if(s[i] == ' '){
                i++;
                continue;
            }

            if(isdigit(s[i])){
                int j = i;
                while(j < s.size() && isdigit(s[j])) j++;
                num_stack.push(stoi(s.substr(i, j-i)));
                i = j;
            }

            else if(s[i] == '*' || s[i] == '/'){
                while(operator_stack.size() && (operator_stack.top() == '*' || operator_stack.top() == '/')){
                    char op = operator_stack.top();
                    operator_stack.pop();
                    calculate(num_stack, op);
                }
                operator_stack.push(s[i]);
                i++;
            }
            else{
                while(operator_stack.size()){
                    char op = operator_stack.top();
                    operator_stack.pop();
                    calculate(num_stack, op);
                }
                operator_stack.push(s[i]);
                i++;
            }
        }

        while(operator_stack.size()){
            char op = operator_stack.top();
            operator_stack.pop();
            calculate(num_stack, op);
        }

        return num_stack.top();
    }

    void calculate(stack<int>& num_stack, char op){
        if(op == '+'){
            int x = num_stack.top();
            num_stack.pop();
            int y = num_stack.top();
            num_stack.pop();
            num_stack.push(x+y);
        }
        else if(op == '-'){
            int x = num_stack.top();
            num_stack.pop();
            int y = num_stack.top();
            num_stack.pop();
            num_stack.push(y-x);
        }
        else if(op == '*'){
            int x = num_stack.top();
            num_stack.pop();
            int y = num_stack.top();
            num_stack.pop();
            num_stack.push(x*y);
        }
        else if(op == '/'){
            int x = num_stack.top();
            num_stack.pop();
            int y = num_stack.top();
            num_stack.pop();
            num_stack.push(y/x);
        }

    }
};
