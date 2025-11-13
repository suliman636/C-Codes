#include <iostream>
#include <string>
using namespace std;

//===================== CharStack Class ======================
class CharStack {
private:
    char *arr;
    int top;
    int capacity;

public:
    // Constructor
    CharStack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    // Destructor
    ~CharStack() {
        delete[] arr;
    }

    // Push
    void Push(char x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    // Pop
    void Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    // Top element
    char Top() {
        if (isEmpty())
            return '\0';
        return arr[top];
    }

    // Check Empty
    bool isEmpty() {
        return (top == -1);
    }
};
//============================================================


// Function to check operator
bool isOperator(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^') {
        return true;
    }
    return false;
}

// Function to check delimiters
bool isDelimeter(char character) {
    if (character == ' ' || character == ',' || character == '\t' || character == '.' ||
        character == ';' || character == ':' || character == '?' ||
        character == '>' || character == '<' || character == '&' ||
        character == '%' || character == '$' || character == '@' || character == '!') {
        return true;
    }
    return false;
}

// If not operator or parenthesis, assume operand
bool isOperand(char character) {
    if (!isOperator(character) && character != '(' && character != ')') {
        return true;
    }
    return false;
}

// Compare operator precedence
int compareOperators(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        return -1; // op1 is higher than op2
    } else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {
        return 1; // op2 is higher than op1
    } else if ((op1 == '^') && (op2 == '*' || op2 == '/' || op2 == '+' || op2 == '-')) {
        return -1; // op1 is higher than op2
    } else if ((op1 == '*' || op1 == '/' || op1 == '+' || op1 == '-') && (op2 == '^')) {
        return 1; // op2 is higher than op1
    }
    return 0; // equal precedence
}

//============================================================
int main() {
    // Empty character stack and blank postfix string.
    CharStack *opStack = new CharStack(100);
    string postFixString = "";

    char input[100];
    cout << "\n\n\tEnter an Infix expression: ";
    cin.get(input, 100); // input with white spaces

    char *cPtr = input; // pointer to input string

    // Process input string
    while (*cPtr) {
        if (isDelimeter(*cPtr)) {
            cPtr++;
            continue;
        }
        // Operand
        else if (isOperand(*cPtr)) {
            postFixString += *cPtr;
        }
        // Left parenthesis
        else if (*cPtr == '(') {
            opStack->Push(*cPtr);
        }
        // Right parenthesis
        else if (*cPtr == ')') {
            while (!opStack->isEmpty()) {
                if (opStack->Top() == '(') {
                    opStack->Pop();
                    break;
                }
                postFixString += opStack->Top();
                opStack->Pop();
            }
        }
        // Operator
        else if (isOperator(*cPtr)) {
            char t = opStack->Top();
            while (!opStack->isEmpty() && t != '(' && compareOperators(t, *cPtr) <= 0) {
                postFixString += t;
                opStack->Pop();
                t = opStack->Top();
            }
            opStack->Push(*cPtr);
        }
        cPtr++;
    }

    // Pop remaining operators
    while (!opStack->isEmpty()) {
        postFixString += opStack->Top();
        opStack->Pop();
    }

    // Show postfix
    cout << "\n\tThe Postfix expression is: " << postFixString << endl;

    delete opStack;
    return 0;
}
