#include "Header.h"

Node::Node(int Value)
{
    Data = Value;
    Next = nullptr;
}

LinkedList::LinkedList()
{
    Head = nullptr;
}

void LinkedList::Add(int Value)
{
    Node* NewNode = new Node(Value);

    // FIX_ME: если список пустой, новый узел становится головой
    if (Head == nullptr)
    {
        Head = NewNode;
        return;
    }

    Node* Current = Head;

    // FIX_ME: стандартное добавление в конец списка
    while (Current->Next != nullptr)
    {
        Current = Current->Next;
    }

    Current->Next = NewNode;
}

void LinkedList::Clear()
{
    // FIX_ME: добавлен стандартный метод удаления всех элементов
    while (Head != nullptr)
    {
        Node* Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

void LinkedList::Print() const
{
    Node* Current = Head;

    // FIX_ME: добавлен стандартный метод вывода списка
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }

    std::cout << "\n";
}

void LinkedList::InsertBeforeEverySecond(int M)
{
    // FIX_ME: если список пустой или состоит из одного элемента,
    // вставка не требуется
    if (Head == nullptr || Head->Next == nullptr)
    {
        return;
    }

    Node* Current = Head;

    // FIX_ME: вставляем M перед каждым вторым элементом исходного списка:
    // было: a b c d e f
    // станет: a M b c M d e M f
    while (Current != nullptr && Current->Next != nullptr)
    {
        Node* Second = Current->Next;
        Node* NewNode = new Node(M);

        NewNode->Next = Second;
        Current->Next = NewNode;

        // FIX_ME: переходим к следующей паре исходных элементов
        Current = Second->Next;
    }
}

Node* LinkedList::GetLast() const
{
    if (Head == nullptr)
    {
        return nullptr;
    }

    Node* Current = Head;

    // FIX_ME: отдельный метод для получения адреса последнего элемента
    while (Current->Next != nullptr)
    {
        Current = Current->Next;
    }

    return Current;
}

bool LinkedList::IsEmpty() const
{
    return Head == nullptr;
}