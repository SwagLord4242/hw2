#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Book : public Product{
	public:
		Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;

	private:
		std::string author_;
		std::string isbn_;

};
#endif