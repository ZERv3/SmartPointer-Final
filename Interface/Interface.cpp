#include "Interface.h"

void showMenu() {
    std::cout << "Выберите команду:\n";
    std::cout << "1. Выполнить функциональные тесты\n";
    std::cout << "2. Выполнить нагрузочные тесты\n";
    std::cout << "3. Завершить программу\n";
    std::cout << "Введите номер команды: ";
}

void testLoadShowMenu() {
    std::cout << "\n\tКуда нужно вывести результат тестов?:\n";
    std::cout << "\t1. В консоль:\n";
    std::cout << "\t2. В файл:\n";
    std::cout << "\t3. Отмена:\n";
    std::cout << "\tВведите номер команды: ";
}

void testLoadAskStart() {
    std::cout << "\tС какого количества начнется отсчет?: ";
}
void testLoadAskEnd() {
    std::cout << "\tС какого количества закончится отсчет?: ";
}
void testLoadAskStep() {
    std::cout << "\tСколько шагов нужно сделать?: ";
}
void testLoadAskOutput() {
    std::cout << "\tНапишите название файла: ";
}

int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        std::cin >> choice;

        // Проверка, что ввод корректен
        if (std::cin.fail() || choice < min || choice > max) {
            std::cin.clear();  // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер ввода
            std::cout << "Некорректный ввод. Пожалуйста, введите номер команды от " << min << " до " << max << ": ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер на случай лишнего ввода
            return choice;
        }
    }
}

void testLoadMenu() {
    int choice;
    bool running = true;
    bool ConsoleOutput = 1;

    while (running) {
        testLoadShowMenu();
        choice = getValidatedInput(1, 3);

        switch (choice) {
            case 1:
                ConsoleOutput = 1;
            break;
            case 2:
                ConsoleOutput = 0;
            break;
            case 3:
                std::cout << "\tВыход из нагрузочных тестов\n\n";
                running = false;
            break;
        }

        if(running){
            int start, end, step;
            testLoadAskStart();
            start = getValidatedInput(0, std::numeric_limits<int>::max());

            testLoadAskEnd();
            end = getValidatedInput(0, std::numeric_limits<int>::max());

            testLoadAskStep();
            step = getValidatedInput(0, std::numeric_limits<int>::max());

            if (ConsoleOutput) {
                testLoadConsoleView(start, end, step);
            }
            else {
                std::string output;
                testLoadAskOutput();
                std::cin >> output;
                testLoadFileView(start, end, step, output);
            }
        }

    }
}

void menu() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        choice = getValidatedInput(1, 3);  // Ожидаем выбор команды от 1 до 3

        switch (choice) {
            case 1:
                testFuncConsoleView();
            break;
            case 2:
                testLoadMenu();
            break;
            case 3:
                std::cout << "Завершение программы...\n";
            running = false;
            break;
        }
    }
}

