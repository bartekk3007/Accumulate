#include <iostream>

class Record
{
	public:
	double unit_price;
	int units;
	Record(double price, int quantity) : unit_price(price), units(quantity)
	{

	}
	/*
	double operator()(const Record& a, const Record& b)
	{
		
	}
	*/
	~Record()
	{
		std::cout << "Destructor called with units_price " << unit_price << " and units " << units << '\n';
	}
};