#include <iostream>
#include <random>
#include "shuffle_array.h"

void swap(int *a, int *b) { // функция свапа элементов, работает за о(1)
    int temp = *a; //  О(1) присваивание по адресу
    *a = *b; // О(1) присваивание по адресу
    *b = temp; // О(1) присваивание по адресу
    // Время работы: O(1) - независимо от входных данных, функция выполняет три операции: три присваивания по адресу
}

void shuffleArray(int* &array, int &size) {
    // функция перемешивания массива с помощью алгоритма Фишера
    std::random_device rd; // Создаем генератор случайных чисел за О(1)
    std::mt19937 gen(rd()); // Инициализируем генератор случайных чисел за О(1)

    for (int i = size - 1; i > 0; --i) {// проходимся с конца массива до начала, все за О(1)
        // присваивание, сравнение, декремент - все за О(1)
        // сам цикл работает за n иттераций -> о(N)
        std::uniform_int_distribution<> distrib(0, i); // Создание равномерного распределения
        int j = distrib(gen); // Генерируем случайный индекс О(1)
        swap(&array[i], &array[j]); // Свапаем элементы местами(перемешиваем) за О(1), так как по ссылке
    }
}
//Время работы:
    // Лучший случай: O(n)
    // Средний случай: O(n)
    // Худший случай: O(n)

// Функция для тестирования алгоритма перемешивания
bool testShuffle(int expected_Size, const int *expected_Array) { // принимает ожидаемый размер и ожидаемый массив
    int *arr = new int[expected_Size]; // Создаем копию массива для перемешивания
    for (int i = 0; i < expected_Size; i++) { // пробегаемся по всему скопированному массиву
        arr[i] = expected_Array[i]; // копированный элемент равняется ожидаемому =)))))))
    }

    shuffleArray(arr, expected_Size); // перемешиваем массив ожидаемого размера

    // Проверяем наличие всех элементов исходного массива в перемешанном
    bool allFound = true; // Сделаем флаг, что все элементы изначально найдены
    for (int i = 0; i < expected_Size; i++) { // пробегаемся по всему ожидаемому массиву
        bool found = false; // помечаем что это элемент изначально не найден
        for (int j = 0; j < expected_Size; j++) {// пробегаемся по всему ожидаемому массиву
            if (arr[j] == expected_Array[i]) { // Проверяем, есть ли элемент в перемешанном массиве
                found = true; // элемент найден в перемешанном массиве
                break;
            }
        }
        if (!found) { // если элемент не найден в перемешанном массиве
            allFound = false; // то все элементы не найдены =)
            std::cerr << "Error: element " << expected_Array[i] << " not found in shuffle."
                      << std::endl; // выводим ошибку какой элемент не найден
        }
    }

    delete[] arr; // Освобождаем память, выделенную под копии массива
    return allFound; // Возвращаем флаг найдены все элементы или нет
}

// Функция запуска тестов
bool runTests() {
    // Массив с отрицательными числами
    int arr1[] = {-1, -2, -3, -4, -5}; // Ожидаемый массив
    int size1 = sizeof(arr1) / sizeof(arr1[0]); // Ожидаемый размер
    if (!testShuffle(size1, arr1)) {
        return false; // Тест не пройден
    }

    // Массив из 100 чисел
    int arr2[100]; // Ожидаемый массив
    int size2 = sizeof(arr2) / sizeof(arr2[0]); // Ожидаемый размер
    for (int i = 0; i < size2; i++) {
        arr2[i] = i;
    }
    if (!testShuffle(size2, arr2)) {
        return false; // Тест не пройден
    }

    // Массив с числами больше 1000
    int arr3[] = {1001, 1002, 1003, 1004, 1005}; // Ожидаемый массив
    int size3 = sizeof(arr3) / sizeof(arr3[0]); // Ожидаемый размер
    if (!testShuffle(size3, arr3)) {
        return false; // Тест не пройден
    }

    // Массив с повторами
    int arr4[] = {1, 1, 2, 2, 3, 3}; // Ожидаемый массив
    int size4 = sizeof(arr4) / sizeof(arr4[0]); // Ожидаемый размер

    if (!testShuffle(size4, arr4)) {
        return false; // Тест не пройден
    }

    // Пустой массив
    int arr5[] = {}; // Ожидаемый массив
    int size5 = sizeof(arr5) / sizeof(arr5[0]); // Ожидаемый размер
    if (!testShuffle(size5, arr5)) {
        return false; // Тест не пройден

    }

    // Массив с большим количеством элементов (1000)
    int arr6[1000]; // Ожидаемый массив
    int size6 = sizeof(arr6) / sizeof(arr6[0]); // Ожидаемый размер
    for (int i = 0; i < size6; i++) {
        arr6[i] = i;
    }

    if (!testShuffle(size6, arr6)) {
        return false; // Тест не пройден
    }

    // Массив с одинаковыми числами
    int arr7[] = {5, 5, 5, 5, 5}; // Ожидаемый массив
    int size7 = sizeof(arr7) / sizeof(arr7[0]); // Ожидаемый размер
    if (!testShuffle(size7, arr7)) {
        return false; // Тест не пройден
    }

    // Массив с чередующимися числами
    int arr8[] = {1, 2, 1, 2, 1, 2}; // Ожидаемый массив
    int size8 = sizeof(arr8) / sizeof(arr8[0]); // Ожидаемый размер
    if (!testShuffle(size8, arr8)) {
        return false; // Тест не пройден
    }

    // Массив с отрицательными и положительными числами
    int arr9[] = {-10, 0, 10, -20, 20}; // Ожидаемый массив
    int size9 = sizeof(arr9) / sizeof(arr9[0]); // Ожидаемый размер
    if (!testShuffle(size9, arr9)) {
        return false; // Тест не пройден
    }

    return true; // Все тесты пройдены
}

