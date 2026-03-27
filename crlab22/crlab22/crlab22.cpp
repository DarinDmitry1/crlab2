#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
    TQueue Q;

    int N;
    std::cout << "Введите количество элементов очереди: ";
    std::cin >> N;

    // FIX_ME: по условию ввод должен быть с клавиатуры
    for (int i = 0; i < N; i++)
    {
        int Value;
        std::cout << "Введите число: ";
        std::cin >> Value;
        Enqueue(Q, Value);
    }

    std::cout << "Исходная очередь: ";
    PrintQueue(Q);

    std::cout << "Извлеченные элементы: ";

    // FIX_ME: извлекаем первые 5 элементов с помощью Dequeue
    for (int i = 0; i < 5; i++)
    {
        if (Q.Head != nullptr)
        {
            std::cout << Dequeue(Q) << " ";
        }
        else
        {
            break;
        }
    }

    std::cout << "\n";
    std::cout << "Оставшаяся очередь: ";
    PrintQueue(Q);

    // FIX_ME: выводим адреса начала и конца результирующей очереди
    PrintAddresses(Q);

    return 0;
}