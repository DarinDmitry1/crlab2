#pragma once

#include <iostream>

/*
    Задача:
    Дан циклический двусвязный линейный список и указатель на первый элемент.

    Требуется:
    - удалить все элементы, у которых левый и правый сосед совпадают
    - первый и последний элементы считаются соседями
    - вернуть указатель на последний элемент полученного списка

    Условия:
    - все динамические структуры реализовать через классы
    - STL не использовать
    - должен быть стандартный набор методов:
        добавление
        удаление
        вывод
    - ввод данных с клавиатуры
*/

/*
    Класс циклического двусвязного списка
*/
class DoubleList
{
public:
    /*
        Узел списка
    */
    class Node
    {
    public:
        int Data;
        Node* Next;
        Node* Prev;

        Node(int Value);
    };

private:
    Node* Head;

public:
    DoubleList();
    ~DoubleList();

    // Добавление элемента в конец списка
    void PushBack(int Value);

    // Удаление всех элементов списка
    void Clear();

    // Вывод списка
    void Print() const;

    // Удаление элемента по указателю
    Node* DeleteNode(Node* Current);

    // Удаление всех элементов, у которых соседи равны
    Node* RemoveEqualNeighbors();

    // Проверка на пустоту
    bool IsEmpty() const;

    // Получить последний элемент
    Node* GetTail() const;

    // FIX_ME: добавлен дружественный интерфейс для вывода списка
    friend std::ostream& operator<<(std::ostream& Out, const DoubleList& List);
};