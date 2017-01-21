#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		double dis2 = x * x + y * y;
		int c = ceil(PI * dis2 / 100);
		cout << "Property " << i << ": This property will begin eroding in year " << c << ".\n";
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
