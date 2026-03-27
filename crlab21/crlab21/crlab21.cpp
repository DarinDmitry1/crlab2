#include "Header.h"

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
    Stack S;

    int N;
    std::cout << "Введите количество элементов: ";
    std::cin >> N;

    // FIX_ME: ввод элементов вынесен в main
    for (int i = 0; i < N; i++)
    {
        int Value;
        std::cout << "Введите число: ";
        std::cin >> Value;

        S.Push(Value);
    }

    std::cout << "Текущий стек: ";
    S.Print();

    S.PrintAddress();

    int D;
    std::cout << "Введите D: ";
    std::cin >> D;

    // FIX_ME: добавление нового элемента
    S.Push(D);

    std::cout << "Новый стек: ";
    S.Print();

    // FIX_ME: вывод нового адреса вершины (P2)
    S.PrintAddress();

    if (!S.IsEmpty())
    {
        std::cout << "Вершина: " << S.GetTop() << "\n";
    }

    return 0;
}