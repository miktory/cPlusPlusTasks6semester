#include <iostream>
#include "Book.h"
#include "BookShop.h"
#include <string>
#include <windows.h>

int main()
{

    // Межин Матвей. Задание 4, Вариант 14, Высокий уровень (файлы 5_1, 6_1)
    std::setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // ввод кириллицы
    SetConsoleOutputCP(1251);

    cout << "Демонстрация функционала класса Book" << std::endl;
    Book::Book testBook = Book::Book("Гарри Поттер и философский камень", "Дж.К. Роулинг", 1997);
    std::cout << testBook << std::endl;
    std::cin >> testBook;
    std::cout << testBook << std::endl;
    std::cout << std::endl;

    cout << "Демонстрация функционала класса BookShop" << std::endl;
    BookShop::BookShop bookShopTest = BookShop::BookShop(testBook, 100);
    std::cout << bookShopTest << std::endl;
    std::cout << std::boolalpha << (testBook == (Book::Book&)bookShopTest) << std::endl; // Downcast BookShop в Book и сравнение с книгой, которая была передана в конструктор
    
    std::cout << "Цена до скидки: " << std::to_string(bookShopTest.getCost()) << std::endl;
    bookShopTest.tryToMakeDiscount(2024);  // Запрос скидки. Цена упадёт на 20%, т.к. возраст книги более 5 лет
    std::cout << "Цена после скидки: " << std::to_string(bookShopTest.getCost()) << std::endl;

    std::cin >> bookShopTest;
    std::cout << bookShopTest << std::endl;
    Book::Book test = Book::Book("Test", "Test", 2003);
    BookShop::BookShop bookShopTest2 = BookShop::BookShop(test, 50);
    std::cout << std::boolalpha << (bookShopTest == bookShopTest2) << std::endl; // Сравнение с другим экземпляром BookShop. 

    // Деструкторы будут вызваны автоматически, т.к. экземпляры классов созданы на стеке. 


}