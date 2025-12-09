#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function with overflow check
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop function with underflow check
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Peek function
char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Precedence function
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    size_t len;   // use size_t for string length
    size_t i;     // loop variable also size_t
    int j = 0;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);  // works only without spaces

    len = strlen(infix);

    for (i = 0; i < len; i++) {
        char ch = infix[i];

        // If operand, directly add to postfix
        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }
        // If opening parenthesis, push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If closing parenthesis, pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && peek() == '(') {
                pop(); // pop '('
            }
        }
        // For operators
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}