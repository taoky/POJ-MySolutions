#include <iostream>
#include <algorithm>
using namespace std;

const int P = 23, E = 28, I = 33;

int main()
{
	int p, e, i, d;
	int kase = 1;
	while (cin >> p >> e >> i >> d)
	{
		int origin_d = d;
		d++;
		if (p == -1) break;
		int pi = p, ei = e, ii = i;
		while (1)
		{
			while (pi < d) pi += P;
			while (ei < d) ei += E;
			while (ii < d) ii += I;
			if (pi == ei && ei == ii)
			{
				int ans = pi - origin_d;
				if (ans > 21252) ans = ans % 21252; // The ans will not be bigger than 21252.
				cout << "Case " << kase << ": the next triple peak occurs in " << ans << " days.\n";
				kase++;
				break;
			}
			else
				d = max(pi, max(ei, ii));
			// cout << pi << " " << ei << " " << ii << "dafdsfas" << endl;
		}
	}
	return 0;
}
