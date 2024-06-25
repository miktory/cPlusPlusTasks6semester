#pragma once
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;
namespace BookShop
{
	class BookShop : public Book::Book {
	public:
		BookShop(Book& book, int cost);
		~BookShop() override;
        BookShop(const BookShop& other);
        BookShop& operator=(const BookShop& other);
        bool operator==(const BookShop& other) const;
        bool operator!=(const BookShop& other) const;
        friend std::ostream& operator<<(std::ostream& os, const BookShop& bookShop);
        friend std::istream& operator>>(std::istream& is, BookShop& bookShop);
        const std::string ToString() const override;
		const bool tryToMakeDiscount(int currentYear);
		const int getCost() const;
		
	private:
		BookShop();
		int cost;
	};
}
