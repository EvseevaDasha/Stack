#pragma once

#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <iostream>
#include <stdexcept>

using ValueType = double;

enum class StackContainer {
    Vector = 0,
    List,
};

class IStackImplementation;

class Stack
{
public:
    Stack(StackContainer container = StackContainer::Vector);
    
    Stack(const ValueType* valueArray, const size_t arraySize, 
          StackContainer container = StackContainer::Vector);

    explicit Stack(const Stack& copyStack);
    Stack& operator=(const Stack& copyStack);

    Stack(Stack&& moveStack) noexcept;
    Stack& operator=(Stack&& moveStack) noexcept;

    ~Stack();

    void push(const ValueType& value);
    // удаление с хвоста
    void pop();
    // посмотреть элемент в хвосте
    const ValueType& top() const;
    // проверка на пустоту
    bool isEmpty() const;
    // размер 
    size_t size() const;
private:
    // указатель на имплементацию (уровень реализации)
    IStackImplementation* _pimpl = nullptr;
    // тип контейнера, наверняка понадобится
    StackContainer _containerType;
};
