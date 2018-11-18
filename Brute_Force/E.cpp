#include <bits/stdc++.h>

using namespace std;

// pow(x, x) = x ^ x

int main () {
	// double x;
	// double eps = 0.000001;
	// double Mn = 10;
	// for(double i = 2.0; i<=3.0; i+=eps) {
	// 	double delta = fabs( pow(i, i) - 10 );
	// 	// fabs(i ^ i - 10)
	// 	// i ^ i 离 10 最“近” 的那个i
	// 	if(delta < Mn) {
	// 		Mn = delta;
	// 		x = i;
	// 	}
	// }
	// cout << fixed << setprecision(7) << x << "\n";
	// printf("%.7lf", x);
	// 123.123
	// 123.1
	// 123.1230
	double l = 2.0, r = 3.0;
	for(int i=1;i<=30;i++) {
		double mid = ( l + r ) / 2;
		if( pow(mid, mid) < 10) l = mid;
		else r = mid; 
	}
	printf("%.10lf\n", l);
	return 0;
}