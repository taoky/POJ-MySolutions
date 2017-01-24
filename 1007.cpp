#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct DNA
{
	string s;
	int sortedness;
} d[100];

int calc(string &s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] > s[j]) num++;
		}
	}
	return num;
}

bool cmp (DNA x, DNA y)
{
	return x.sortedness < y.sortedness;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> d[i].s;
		d[i].sortedness = calc(d[i].s);
	}
	sort(d, d + m, cmp);
	for (int i = 0; i < m; i++)
	{
		cout << d[i].s << endl;
	}
	return 0;
}
