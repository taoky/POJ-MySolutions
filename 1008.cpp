#include <iostream>
#include <cstdlib>
using namespace std;

string tzol_l[21] = {"", "imix", "ik", "akbal", "kan", "chicchan",
											"cimi", "manik", "lamat", "muluk", "ok",
											"chuen", "eb", "ben", "ix", "mem", "cib",
											"caban", "eznab", "canac", "ahau"};

int haab_month_convert(string &s)
{
	string l[19] = {"pop", "no", "zip", "zotz", "tzec", "xul",
									"yoxkin", "mol", "chen", "yax", "zac", "ceh",
									"mac", "kankin", "muan", "pax", "koyab", "cumhu",
									"uayet"};
	for (int i = 0; i < 19; i++)
		if (l[i] == s)
			return i;
}

int habb (string day_hs, string month_hs, int year_h)
{
	day_hs.erase(day_hs.size() - 1);
	int day_h = atoi(day_hs.c_str());
	int month_h = haab_month_convert(month_hs);
	return 365 * year_h + month_h * 20 + day_h;;
}

void tzol (int daycount)
{
	int year_tz = (daycount) / 260;
	// daycount = daycount % 260;
	int day_tz_num = daycount % 13 + 1;
	string day_tz_name = tzol_l[daycount % 20 + 1];
	cout << day_tz_num << " " << day_tz_name << " " << year_tz << endl;
}

int main()
{
	int n;
	cin >> n;
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		int daycount = 0; // the day number before the input
		string day_hs, month_hs;
		int year_h;
		cin >> day_hs >> month_hs >> year_h;

		daycount = habb(day_hs, month_hs, year_h);
		// cout << daycount << endl;

		tzol(daycount);

	}
	return 0;
}
