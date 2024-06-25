#include "BookShop.h"
using namespace std;

namespace BookShop
{
		BookShop::BookShop() : Book(), cost(0) {}

		BookShop::BookShop(Book& book, int cost) : Book(book), cost(cost) {}

		BookShop::~BookShop()
		{
			cost = 0;
			std::cout << "Уничтожение объекта. Дестуктор класса BookShop." << std::endl;
		}

		BookShop::BookShop(const BookShop& other) : BookShop((Book&)other, other.cost) {}

		BookShop& BookShop::operator=(const BookShop& other)
		{
			if (this != &other) {
				title = other.title;
				author = other.author;
				year = other.year;
				cost = other.cost;
			}
			return *this;
		}

		bool BookShop::operator==(const BookShop& other) const
		{
			return author == other.author && other.cost == cost && title == other.title && year == other.year;
		}

		bool BookShop::operator!=(const BookShop& other) const
		{
			return !(*this == other);
		}

		const std::string BookShop::ToString() const
		{
			string result;
			result.append(Book::ToString() + " Цена: " + std::to_string(cost));
			return result;
		}

		const bool BookShop::tryToMakeDiscount(int currentYear)
		{
			if (currentYear - year > 5)
			{
				cost = cost * 0.80;
				return true;
			}
			return false;
		}

		const int BookShop::getCost() const
		{
			return cost;
		}

		std::ostream& operator<<(std::ostream& os, const BookShop& bookShop)
		{
			os << bookShop.ToString();
			return os;
		}
		std::istream& operator>>(std::istream& is, BookShop& bookShop)
		{
			std::cout << "Введите название книги: ";
			std::getline(is, bookShop.title);
			std::cout << "Введите автора книги: ";
			std::getline(is, bookShop.author);
			std::cout << "Введите год издания книги: ";
			is >> bookShop.year;
			std::cout << "Введите стоимость книги: ";
			is >> bookShop.cost;
			is.ignore();
			return is;
		}
}
