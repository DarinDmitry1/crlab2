#include "Header.h"

TQueue::TQueue()
{
    Head = nullptr;
    Tail = nullptr;
}

void Enqueue(TQueue& Q, int Value)
{
    PNode* NewNode = new PNode{ Value, nullptr };

    // FIX_ME: если очередь не пустая, новый элемент добавляется после хвоста
    if (Q.Tail != nullptr)
    {
        Q.Tail->Next = NewNode;
    }
    else
    {
        // FIX_ME: если очередь была пустой, новый элемент становится и головой тоже
        Q.Head = NewNode;
    }

    Q.Tail = NewNode;
}

int Dequeue(TQueue& Q)
{
    // FIX_ME: добавлена защита от удаления из пустой очереди
    if (Q.Head == nullptr)
    {
        return 0;
    }

    PNode* Temp = Q.Head;
    int Value = Temp->Data;

    Q.Head = Q.Head->Next;

    // FIX_ME: если после удаления очередь стала пустой,
    // обязательно обнуляем и Tail
    if (Q.Head == nullptr)
    {
        Q.Tail = nullptr;
    }

    delete Temp;
    return Value;
}

void PrintQueue(const TQueue& Q)
{
    PNode* Current = Q.Head;

    // FIX_ME: добавлен стандартный метод вывода очереди
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }

    std::cout << "\n";
}

void PrintAddresses(const TQueue& Q)
{
    // FIX_ME: вывод адресов начала и конца сделан в отдельной функции
    std::cout << "Адрес начала: " << Q.Head << "\n";
    std::cout << "Адрес конца: " << Q.Tail << "\n";
}