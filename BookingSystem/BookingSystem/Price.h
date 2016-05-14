#pragma once

#include<string>

/* Value amount used to describe price. Has helper appropriate helper functions
*/
struct Price {
	int _amount;

	Price()
		: _amount(0) {}
	Price(int amount)
	 : _amount(amount){}

	/* Get the Price as a string
	*/
	std::string getPrice() {
		return std::to_string(_amount / 100) + '.' + std::to_string(_amount % 100);
	}
	/* Add operator
	*/
	Price operator+(const Price& other) {
		return Price(other._amount + this->_amount);
	}
	/* Add operator
	*/
	Price& operator+=(const Price& other) {
		this->_amount += other._amount;
		return *this;
	}
	/* Subtract operator
	*/
	Price operator-(const Price& other) {
		return Price(other._amount + this->_amount);
	}
	/* Subtract operator
	*/
	Price& operator-=(const Price& other) {
		this->_amount -= other._amount;
		return *this;
	}

};