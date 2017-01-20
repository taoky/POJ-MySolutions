/*
C++ AC Only (Visual C++ 6.0)
TLE when in G++
Maybe more optimization is needed.
*/

#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
using namespace std;

map <string, int> mc;
char realtion1[] = "2223334445556667", realtion2[] = "77888999";

inline char trans (char x)
{
	//assert(x != 'Q');
	//assert(x != 'Z');
	if (x < 'Q')
		return realtion1[x - 'A'];
	else
		return realtion2[x - 'R'];
}

/* inline int deal (string x)
{
	int ans = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '-') continue;
		if (isdigit(x[i])) ans = ans * 10 + x[i] - '0';
		else ans = ans * 10 + trans(x[i]);
	}
	return ans;
} */

char thisch[7];
inline void deal (string &x)
{
	int pointer = 6;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		if (x[i] == '-') continue;
		if (isdigit(x[i])) thisch[pointer--] = x[i];
		else thisch[pointer--] = trans(x[i]);
	}
	for (int i = pointer; i >= 0; i--)
	{
		thisch[i] = 0;
	}
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
		deal(x);
		// cout << to << endl;
		string sto = thisch;
		// cout << thisch << endl;
		mc[sto]++; //This way may lead to TLE?

		/* map <string, int>::iterator isappear = mc.find(sto);
		if (isappear == mc.end())
		{
			mc.insert(map <string, int>::value_type(sto, 1));
		}
		else
		{
			// mc[sto]++;
			isappear->second++;
		} */
	}
	bool isOut = false;
	for (map <string, int>::iterator iter = mc.begin(); iter != mc.end(); ++iter)
	{
		if (iter->second > 1)
		{
			string x1 = iter->first;
			int x2 = iter->second;
			isOut = true;
			cout << x1[0] << x1[1] << x1[2] << "-";
			cout << x1[3] << x1[4] << x1[5] << x1[6] << " ";
			cout << x2 << endl;
		}
	}
	if (!isOut) cout << "No duplicates." << endl;
	return 0;
}
