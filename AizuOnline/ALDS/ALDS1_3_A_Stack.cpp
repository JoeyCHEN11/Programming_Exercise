#include <string>
#include <iostream>

using namespace std;
int S[100];
int top = 0;

int pop() {
	int v = S[top--];
	return v;
}

void push(int value) {
	S[++top] = value;
}

int main() {
	string s = "";
	while (cin>>s) {
		if (s[0]=='*') {
			int a = pop();
			int b = pop();
			push(a * b);
		}
		else if (s[0] == '+') {
			int a = pop();
			int b = pop();
			push(a + b);
		}
		else if (s[0] == '-') {
			int a = pop();
			int b = pop();
			push(b-a);
		}
		else {
			int x = stoi(s);
			push(x);
		}
	}
	cout << pop() << endl;
}