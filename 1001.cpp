#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string mul(string x, string y)
{
	int store[200] = {};
	string ans(x.size() + y.size(), '0');
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < y.size(); j++)
		{
			store[i + j + 1] += (x[i] - '0') * (y[j] - '0');
		}
	}
	for (int i = x.size() + y.size() - 1; i >= 0; i--)
	{
		store[i - 1] += store[i] / 10;
		store[i] %= 10;
		ans[i] = store[i] + '0';
	}
	while (ans[0] == '0' && ans.size() > 0) ans.erase(0, 1);
	return ans;
}

int main()
{
	string x; int y;
	// 高精度系列
	while (cin >> x >> y)
	{
		string newstring = x.substr(0, x.find(".")) + x.substr(x.find(".") + 1);
		string savestring = newstring;
		int shouldlength = x.size() - x.find(".") - 1;
		shouldlength *= y;
		// cout << newstring << endl;
		for (int i = 1; i <= y - 1; i++)
		{
			savestring = mul(newstring, savestring);
			// cout << savestring << endl;
		}
		
	}
	return 0;
}
