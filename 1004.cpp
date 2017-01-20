#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double eps = 1e-8;

int main()
{
	double ans = 0.0;
	for (int i = 0; i < 12; i++)
	{
		double x;
		cin >> x;
		ans += x;
	}
	ans /= 12;
	// Dealing with x.xxx round to x.xx
	// ans = floor(ans * 100 + 0.5) / 100;
	// if (ans * 100 - floor(ans * 100) >= 0.5) ans += 0.1;
	// cout << ans << endl;
	printf("$%.2f\n", ans + eps);
	return 0;
}
