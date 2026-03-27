#include "Header.h"

int main()
{
	setlocale(LC_ALL, "ru");
    DequeTask D;

    int Choice;
    std::cout << "Выберите способ ввода:\n";
    std::cout << "1 - с клавиатуры\n";
    std::cout << "2 - случайные числа\n";
    std::cout << "3 - из файла\n";
    std::cin >> Choice;

    bool bOk = false;

    if (Choice == 1)
    {
        // FIX_ME: ввод с клавиатуры вынесен в отдельный метод
        bOk = D.ReadFromKeyboard();
    }
    else if (Choice == 2)
    {
        int Count;
        std::cout << "Введите количество элементов (нечетное и >= 5): ";
        std::cin >> Count;

        // FIX_ME: генерация случайных значений вынесена в отдельный метод
        bOk = D.ReadRandom(Count);
    }
    else if (Choice == 3)
    {
        // FIX_ME: чтение из файла вынесено в отдельный метод
        bOk = D.ReadFromFile("a.txt");
    }

    if (!bOk)
    {
        std::cout << "Ошибка ввода данных\n";
        return 1;
    }

    std::cout << "Исходный дек: " << D << "\n";

    // FIX_ME: вставка пяти средних элементов выполняется отдельным методом
    D.InsertMiddleFive();

    std::cout << "Дек после вставки: " << D << "\n";

    std::cout << "Обратный вывод: ";
    D.PrintReverse();

    return 0;
}