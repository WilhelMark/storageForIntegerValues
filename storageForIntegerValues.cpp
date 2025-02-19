#include <iostream>
#include <vector>

int main() {
    const int BUFFER_SIZE = 20; // Размер кольцевого буфера
    std::vector<int> buffer(BUFFER_SIZE); // Вектор фиксированного размера
    int head = 0; // Индекс для вставки нового элемента
    int count = 0; // Текущее количество элементов в буфере

    while (true) {
        std::cout << "input number: ";
        int input;
        std::cin >> input;

        if (input == -1) { // Завершаем ввод и выводим содержимое буфера
            std::cout << "output: ";
            for (int i = 0; i < count; ++i) {
                // Выводим элементы в порядке их добавления
                std::cout << buffer[(head + i) % BUFFER_SIZE] << " ";
            }
            std::cout << std::endl;
            continue; // Возвращаемся к вводу новых данных
        }

        // Добавляем элемент в буфер по индексу head
        buffer[head] = input;

        // Смещаем индекс head по кругу
        head = (head + 1) % BUFFER_SIZE;

        // Увеличиваем счетчик элементов, но не превышаем размер буфера
        if (count < BUFFER_SIZE) {
            ++count;
        }
    }

    return 0;
}
