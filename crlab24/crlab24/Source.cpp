#include "Header.h"

DoubleList::Node::Node(int Value)
{
    Data = Value;
    Next = nullptr;
    Prev = nullptr;
}

DoubleList::DoubleList()
{
    Head = nullptr;
}

DoubleList::~DoubleList()
{
    Clear();
}

void DoubleList::PushBack(int Value)
{
    Node* NewNode = new Node(Value);

    // FIX_ME: если список пустой, новый узел указывает сам на себя
    if (Head == nullptr)
    {
        Head = NewNode;
        NewNode->Next = NewNode;
        NewNode->Prev = NewNode;
        return;
    }

    Node* Tail = Head->Prev;

    // FIX_ME: стандартное добавление в конец циклического двусвязного списка
    Tail->Next = NewNode;
    NewNode->Prev = Tail;
    NewNode->Next = Head;
    Head->Prev = NewNode;
}

void DoubleList::Clear()
{
    // FIX_ME: добавлен стандартный метод удаления всех элементов
    if (Head == nullptr)
    {
        return;
    }

    Node* Current = Head->Next;

    while (Current != Head)
    {
        Node* Temp = Current;
        Current = Current->Next;
        delete Temp;
    }

    delete Head;
    Head = nullptr;
}

void DoubleList::Print() const
{
    // FIX_ME: добавлена защита от вывода пустого списка
    if (Head == nullptr)
    {
        std::cout << "Список пуст\n";
        return;
    }

    Node* Current = Head;

    do
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    } while (Current != Head);

    std::cout << "\n";
}

DoubleList::Node* DoubleList::DeleteNode(Node* Current)
{
    if (Current == nullptr)
    {
        return nullptr;
    }

    // FIX_ME: если в списке один элемент, после удаления список станет пустым
    if (Current->Next == Current)
    {
        delete Current;
        Head = nullptr;
        return nullptr;
    }

    Node* NextNode = Current->Next;

    Current->Prev->Next = Current->Next;
    Current->Next->Prev = Current->Prev;

    // FIX_ME: если удаляем голову, переносим Head
    if (Current == Head)
    {
        Head = NextNode;
    }

    delete Current;
    return NextNode;
}

DoubleList::Node* DoubleList::RemoveEqualNeighbors()
{
    if (Head == nullptr)
    {
        return nullptr;
    }

    bool bDeleted = true;

    // FIX_ME: повторяем проходы, пока есть удаления
    while (bDeleted && Head != nullptr && Head->Next != Head)
    {
        bDeleted = false;
        Node* Start = Head;
        Node* Current = Head;

        do
        {
            Node* NextAfterCurrent = Current->Next;

            // FIX_ME: удаляем элемент, если его левый и правый соседи равны
            if (Current->Prev->Data == Current->Next->Data)
            {
                DeleteNode(Current);
                bDeleted = true;

                // FIX_ME: если список опустел или остался один элемент, завершаем
                if (Head == nullptr || Head->Next == Head)
                {
                    break;
                }

                Start = Head;
                Current = Head;
            }
            else
            {
                Current = NextAfterCurrent;
            }
        } while (Head != nullptr && Current != Start);
    }

    if (Head == nullptr)
    {
        return nullptr;
    }

    // FIX_ME: по условию возвращаем указатель на последний элемент
    return Head->Prev;
}

bool DoubleList::IsEmpty() const
{
    return Head == nullptr;
}

DoubleList::Node* DoubleList::GetTail() const
{
    if (Head == nullptr)
    {
        return nullptr;
    }

    return Head->Prev;
}

std::ostream& operator<<(std::ostream& Out, const DoubleList& List)
{
    if (List.Head == nullptr)
    {
        Out << "Список пуст";
        return Out;
    }

    DoubleList::Node* Current = List.Head;

    do
    {
        Out << Current->Data << " ";
        Current = Current->Next;
    } while (Current != List.Head);

    return Out;
}