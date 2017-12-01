#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Stack
{
	int sz;
	T buffer[80010];
	Stack() { sz = 0; }
	void push_back(T x)
	{
		buffer[sz++] = x;
	}
	bool empty() { return !sz; }
	void pop_back()
	{
		sz--;
	}
	int size()
	{
		return sz;
	}
	T back()
	{
		return buffer[sz - 1];
	}
	T operator[](int i) { return buffer[i]; }
};

bool higher_priority(char a, char b)
{
	if ((a == '*' || a == '/') && (b == '+' || b == '-')) return true;
	return false;
}

int main()
{
	string s, t("");
	cin >> s;
	Stack <char> stack;
	int cur;
	char c, x;
	for (int i(0); i < s.size(); ++i)
	{
		c = s[i];
		if (c == '(') stack.push_back(c);
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (stack.back() == '(' || !stack.size()) stack.push_back(c);
			else
			{
				if (higher_priority(c, stack.back())) stack.push_back(c);
				else
				{
					x = stack.back();
					while (stack.size() && x != '(' && !higher_priority(c, x))
					{
						t += x;
						stack.pop_back();
						if (stack.size()) x = stack.back();
					}
					stack.push_back(c);
				}
			}
		}
		else if (c >= '0' && c <= '9')
		{
			while (c >= '0' && c <= '9')
			{
				t += c;
				++i;
				c = s[i];
			}
			--i;
			t += ' ';
		}
		else if (c == ')')
		{
			x = stack.back();
			while (x != '(')
			{
				t += x;
				t += ' ';
				stack.pop_back();
				x = stack.back();
			}
			stack.pop_back();
		}
	}
	while (stack.size())
	{
		t += stack.back();
		t += ' ';
		stack.pop_back();
	}
	int ans(0), one, two;
	Stack <int> st;
	for (int i(0); i < t.size(); ++i)
	{
		c = t[i];
		if (c == ' ') continue;
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			one = st.back();
			st.pop_back();
			two = st.back();
			st.pop_back();
			if (c == '+') st.push_back(one + two);
			else if (c == '-') st.push_back(two - one);
			else if (c == '*') st.push_back(one * two);
			else st.push_back(two / one);
		}
		else
		{
			cur = 0;
			while (c >= '0' && c <= '9')
			{
				cur = cur * 10 + c - '0';
				++i;
				c = t[i];
			}
			st.push_back(cur);
		}
	}
	cout << st.back();
	cin.get();
	cin.get();
	return 0;
}