#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
    LinkedList List;

    int N;
    std::cout << "Введите количество элементов списка: ";
    std::cin >> N;

    // FIX_ME: ввод списка оставлен с клавиатуры по условию
    for (int i = 0; i < N; i++)
    {
        int Value;
        std::cout << "Введите число: ";
        std::cin >> Value;
        List.Add(Value);
    }

    int M;
    std::cout << "Введите значение M: ";
    std::cin >> M;

    std::cout << "Исходный список: ";
    List.Print();

    // FIX_ME: вставка вынесена в отдельный метод класса
    List.InsertBeforeEverySecond(M);

    std::cout << "Список после вставки: ";
    List.Print();

    Node* P2 = List.GetLast();

    if (P2 != nullptr)
    {
        // FIX_ME: выводим адрес последнего элемента списка P2
        std::cout << "Адрес последнего элемента P2: " << P2 << "\n";
        std::cout << "Значение последнего элемента: " << P2->Data << "\n";
    }
    else
    {
        std::cout << "Список пуст.\n";
    }

    // FIX_ME: освобождение памяти вынесено в отдельный метод
    List.Clear();

    return 0;
}