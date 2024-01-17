#include <iostream>
#include <vector>
#include <numeric>
#include "Functor.h"

using namespace std;

double giveProduct(double v, const Record& r)
{
	return v + r.unit_price * r.units;
}

Record giveRecord(const Record& r1, const Record& r2)
{
	Record r(r1.unit_price + r2.unit_price, r1.units + r2.units);
	return r;
}

int main()
{
	Record r1(2.5, 4);
	Record r2(1.5, 6);
	Record r3(4.5, 2);
	Record r4(2.5, 2);

	vector<Record> vRec{r1, r2, r3, r4};

	double total1 = accumulate(vRec.begin(), vRec.end(), 0.0, giveProduct);
	double total2 = accumulate(vRec.begin(), vRec.end(), 0.0, Functor());
	double total3 = accumulate(vRec.begin(), vRec.end(), 0.0, [](double v, const Record& r)
		{
			return v + r.unit_price * r.units;
		});

	cout << total1 << ' ' << total2 << ' ' << total3 << '\n';

	Record rinit(0.0, 0);
	Record total4 = accumulate(vRec.begin(), vRec.end(), rinit, giveRecord);
	cout << total4.unit_price << ' ' << total4.units << '\n';

	return 0;
}