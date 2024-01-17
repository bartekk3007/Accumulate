#include <iostream>
#include "Record.h"

class Functor
{
	public:
	double operator()(double v, const Record& r)
	{
		return v + r.unit_price * r.units;
	}
};