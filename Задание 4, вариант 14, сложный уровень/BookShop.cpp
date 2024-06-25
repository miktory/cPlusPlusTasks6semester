#include "BookShop.h"
using namespace std;

namespace BookShop
{
		BookShop::BookShop() : Book(), cost(0) {}

		BookShop::BookShop(Book& book, int cost) : Book(book), cost(cost) {}

		BookShop::~BookShop()
		{
			cost = 0;
			std::cout << "����������� �������. ��������� ������ BookShop." << std::endl;
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
			result.append(Book::ToString() + " ����: " + std::to_string(cost));
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
			std::cout << "������� �������� �����: ";
			std::getline(is, bookShop.title);
			std::cout << "������� ������ �����: ";
			std::getline(is, bookShop.author);
			std::cout << "������� ��� ������� �����: ";
			is >> bookShop.year;
			std::cout << "������� ��������� �����: ";
			is >> bookShop.cost;
			is.ignore();
			return is;
		}
}
