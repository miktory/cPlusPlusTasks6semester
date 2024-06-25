#pragma once
#include <iostream>
#include "AbstractObject.h"
using namespace AbstractObject;

namespace Book
{
    class Book: AbstractObject {
    public:
        Book(const std::string& title, const std::string& author, int year);
        Book(const Book& other);
        Book& operator=(const Book& other);
        bool operator==(const Book& other) const;
        bool operator!=(const Book& other) const;
        ~Book() override;
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
        friend std::istream& operator>>(std::istream& is, Book& book);
        const int getAge(int currYear) const;
        const int getTotalDays(int currYear) const;
        const std::string& getAuthor() const;
        const std::string& getTitle() const;
        const int getYear() const;
        const std::string ToString() const override;

    protected:
        Book();
        std::string title;
        std::string author;
        int year;
    };
}
