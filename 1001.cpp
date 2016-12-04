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
		if (shouldlength >= savestring.size())
		{
			cout << ".";
			for (int i = 1; i <= shouldlength - savestring.size(); i++)
			{
				cout << 0;
			}
			for (int i = savestring.size() - 1; i >= 0; i--)
			{
				if (savestring[i] == '0') // remove 0s from the back of savestring
					savestring.erase(i, 1);
				else break;
			}
			cout << savestring << endl;
		}
		else
		{
			string first = savestring.substr(0, savestring.size() - shouldlength);
			string second = savestring.substr(savestring.size() - shouldlength);
			cout << first;
			for (int i = second.size() - 1; i >= 0; i--)
			{
				if (second[i] == '0') // remove 0s from the back of savestring
					second.erase(i, 1);
				else break;
			}
			if (!second.empty())
			{
				cout << ".";
				cout << second << endl;
			}
			else cout << endl;
		}
	}
	return 0;
}
