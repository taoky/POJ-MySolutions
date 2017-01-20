#include <iostream>
using namespace std;

int main()
{
	double thisnum;
	while (cin >> thisnum)
	{
		if (thisnum == 0.0) break;
		double total = 0.0;
		int c = 0;
		while (total <= thisnum)
		{
			c++;
			total += 1.0 / (c + 1);
		}
		cout << c << " card(s)" << endl;
	}
	return 0;
}
