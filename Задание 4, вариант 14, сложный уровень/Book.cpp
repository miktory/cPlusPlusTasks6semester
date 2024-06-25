#include "Book.h"
#include <string>

namespace Book
{
    Book::Book() : title(""), author(""), year(0) {}
   
    Book::Book(const std::string& title, const std::string& author, int year)
        : title(title), author(author), year(year) {}
    
    Book::Book(const Book& other)
        : title(other.title), author(other.author), year(other.year) {}
   
    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
        }
        return *this;
    }

    bool Book::operator==(const Book& other) const {
        return title == other.title && author == other.author && year == other.year;
    }

    bool Book::operator!=(const Book& other) const {
        return !(*this == other);
    }

    Book::~Book()
    {
        year = 0;
        title.clear();
        author.clear();
        std::cout << "Уничтожение объекта. Дестуктор класса Book." << std::endl;
    }

    const int Book::getAge(int currYear) const
    {
        return currYear - this->year;
    }

    const int Book::getTotalDays(int currYear) const
    {
        return getAge((currYear - this-> year) * 365);
    }

    const std::string& Book::getAuthor() const
    {
        return this->author;
    }

    const std::string& Book::getTitle() const
    {
        return this->title;
    }

    const int Book::getYear() const
    {
        return this->year;
    }


    const std::string Book::ToString() const
    {
        std::string result;
        result.append("Книга: " + title + " Автор: " + author + " Год: " + std::to_string(year));
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.ToString();
        return os;
    }

    std::istream& operator>>(std::istream& is, Book& book) {
        std::cout << "Введите название книги: ";
        std::getline(is, book.title);
        std::cout << "Введите автора книги: ";
        std::getline(is, book.author);
        std::cout << "Введите год издания книги: ";
        is >> book.year;
        is.ignore();
        return is;
    }
}
