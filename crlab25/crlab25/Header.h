#pragma once

#include <deque>
#include <iostream>

/*
    Задача:
    Дан дек D с нечетным количеством элементов N (N >= 5).

    Требуется:
    - добавить в начало дека пять его средних элементов
    - порядок этих элементов должен сохраниться
    - использовать один вызов функции-члена insert

    Дополнительно:
    - элементы контейнера — целые числа
    - для заполнения контейнера использовать итератор и конструктор контейнера
    - для вывода использовать итератор
    - должен быть дружественный интерфейс
    - ввод организовать разными способами:
        1) с клавиатуры
        2) случайно
        3) из файла
*/

/*
    Класс-обертка над деком
*/
class DequeTask
{
private:
    std::deque<int> Data;

public:
    DequeTask();
    DequeTask(const std::deque<int>& Source);

    // Загрузка данных с клавиатуры
    bool ReadFromKeyboard();

    // Загрузка случайных данных
    bool ReadRandom(int Count);

    // Загрузка данных из файла
    bool ReadFromFile(const char* FileName);

    // Добавление пяти средних элементов в начало
    void InsertMiddleFive();

    // Проверка корректности размера
    bool IsValid() const;

    // Печать в обратном порядке
    void PrintReverse() const;

    // Дружественный интерфейс для обычного вывода
    friend std::ostream& operator<<(std::ostream& Out, const DequeTask& D);
};