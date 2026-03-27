#include "Header.h"

int main()
{
    DoubleList List;

    int N;
    std::cout << "Введите количество элементов: ";
    std::cin >> N;

    // FIX_ME: ввод списка оставлен с клавиатуры по условию
    for (int i = 0; i < N; i++)
    {
        int Value;
        std::cout << "Введите число: ";
        std::cin >> Value;
        List.PushBack(Value);
    }

    std::cout << "Исходный список: ";
    std::cout << List << "\n";

    // FIX_ME: удаление всех элементов с одинаковыми соседями вынесено в отдельный метод
    DoubleList::Node* P2 = List.RemoveEqualNeighbors();

    std::cout << "Обработанный список: ";
    std::cout << List << "\n";

    if (P2 != nullptr)
    {
        std::cout << "Адрес последнего элемента P2: " << P2 << "\n";
        std::cout << "Значение последнего элемента: " << P2->Data << "\n";
    }
    else
    {
        std::cout << "Список пуст.\n";
    }

    return 0;
}