#pragma once
#include<iostream>

namespace AbstractObject
{
    class AbstractObject {
    public:
        virtual const std::string ToString() const = 0;
        virtual ~AbstractObject() {
            std::cout << "Уничтожение объекта. Деструктор абстрактного класса." << std::endl;
        }
    };
}
