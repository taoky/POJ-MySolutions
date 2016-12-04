#include <iostream>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

map <string, int> mc;
char realtion1[] = "2223334445556667", realtion2[] = "77888999";

inline int trans (char x)
{
	if (x < 'Q')
		return realtion1[x - 'A'] - '0';
	else
		return realtion2[x - 'R'] - '0';
}

inline int deal (string x)
{
	int ans = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '-') continue;
		if (isdigit(x[i])) ans = ans * 10 + x[i] - '0';
		else ans = ans * 10 + trans(x[i]);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string x;
		cin >> x;
		int to = deal(x);
		// cout << to << endl;
		char s[8]; sprintf(s, "%d", to); string sto = s;
		// mc[sto]++; This way may lead to TLE?
		map <string, int>::iterator isappear = mc.find(sto);
		if (isappear == mc.end())
		{
			mc.insert(map <string, int>::value_type(sto, 1));
		}
		else
		{
			mc[sto]++;
		}
	}
	bool isOut = false;
	for (map <string, int>::iterator iter = mc.begin(); iter != mc.end(); iter++)
	{
		string x1 = iter->first;
		int x2 = iter->second;
		if (x2 == 1) continue;
		isOut = true;
		cout << x1[0] << x1[1] << x1[2] << "-";
		cout << x1.substr(3) << " ";
		cout << x2 << endl;
	}
	if (!isOut) cout << "No duplicates." << endl;
	return 0;
}
