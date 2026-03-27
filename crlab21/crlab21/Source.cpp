#include "Header.h"

#include <iostream>

Node::Node(int Value)
{
    Data = Value;
    Next = nullptr;
}

Stack::Stack()
{
    Top = nullptr;
}

void Stack::Push(int Value)
{
    Node* NewNode = new Node(Value);

    // FIX_ME: новый элемент добавл€етс€ в начало (вершину)
    NewNode->Next = Top;
    Top = NewNode;
}

void Stack::Pop()
{
    // FIX_ME: добавил стандартную операцию удалени€
    if (Top == nullptr)
    {
        return;
    }

    Node* Temp = Top;
    Top = Top->Next;
    delete Temp;
}

void Stack::Print() const
{
    Node* Current = Top;

    // FIX_ME: вывод элементов стека
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }

    std::cout << "\n";
}

void Stack::PrintAddress() const
{
    // FIX_ME: вывод адреса вершины стека (P2)
    std::cout << "јдрес вершины: " << Top << "\n";
}

int Stack::GetTop() const
{
    // FIX_ME: добавил корректную проверку
    if (Top != nullptr)
    {
        return Top->Data;
    }

    return 0; // FIX_ME: раньше было 1 Ч это ошибка
}

bool Stack::IsEmpty() const
{
    return Top == nullptr;
}