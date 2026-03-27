#include "Header.h"

#include <vector>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <ctime>

DequeTask::DequeTask()
{
}

DequeTask::DequeTask(const std::deque<int>& Source)
{
    Data = Source;
}

bool DequeTask::IsValid() const
{
    return Data.size() >= 5 && Data.size() % 2 == 1;
}

bool DequeTask::ReadFromKeyboard()
{
    int Count;
    std::cout << "Введите количество элементов (нечетное и >= 5): ";
    std::cin >> Count;

    if (Count < 5 || Count % 2 == 0)
    {
        return false;
    }

    std::vector<int> Temp;
    Temp.reserve(Count);

    std::cout << "Введите элементы:\n";

    // FIX_ME: данные сначала считываются во временный контейнер,
    // а затем дек создается через конструктор от итераторов
    for (int i = 0; i < Count; i++)
    {
        int Value;
        std::cin >> Value;
        Temp.push_back(Value);
    }

    Data = std::deque<int>(Temp.begin(), Temp.end());
    return true;
}

bool DequeTask::ReadRandom(int Count)
{
    if (Count < 5 || Count % 2 == 0)
    {
        return false;
    }

    std::vector<int> Temp;
    Temp.reserve(Count);

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // FIX_ME: случайные данные сначала помещаются во временный контейнер,
    // потом дек создается через конструктор от итераторов
    for (int i = 0; i < Count; i++)
    {
        Temp.push_back(std::rand() % 100);
    }

    Data = std::deque<int>(Temp.begin(), Temp.end());
    return true;
}

bool DequeTask::ReadFromFile(const char* FileName)
{
    std::ifstream Input(FileName);

    if (!Input.is_open())
    {
        return false;
    }

    std::vector<int> Temp;

    // FIX_ME: чтение из файла организовано через итераторы потока
    std::istream_iterator<int> Begin(Input);
    std::istream_iterator<int> End;

    for (; Begin != End; ++Begin)
    {
        Temp.push_back(*Begin);
    }

    Data = std::deque<int>(Temp.begin(), Temp.end());

    return IsValid();
}

void DequeTask::InsertMiddleFive()
{
    if (!IsValid())
    {
        return;
    }

    int Middle = static_cast<int>(Data.size() / 2);

    std::deque<int>::iterator First = Data.begin() + (Middle - 2);
    std::deque<int>::iterator Last = Data.begin() + (Middle + 3);

    // FIX_ME: используется один вызов insert
    Data.insert(Data.begin(), First, Last);
}

void DequeTask::PrintReverse() const
{
    // FIX_ME: обратный вывод сделан через обратные итераторы
    for (std::deque<int>::const_reverse_iterator It = Data.rbegin(); It != Data.rend(); ++It)
    {
        std::cout << *It << " ";
    }

    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& Out, const DequeTask& D)
{
    // FIX_ME: обычный вывод сделан через итераторы и дружественный интерфейс
    for (std::deque<int>::const_iterator It = D.Data.begin(); It != D.Data.end(); ++It)
    {
        Out << *It << " ";
    }

    return Out;
}