#include "Interface.h"

void showMenu() {
    std::cout << "Выберите команду:\n";
    std::cout << "1. Выполнить функциональные тесты\n";
    std::cout << "2. Выполнить нагрузочные тесты\n";
    std::cout << "3. Запустить ручное тестирование\n";
    std::cout << "4. Завершить программу\n";
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
void testLoadAskOutputFileName() {
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

bool isValidName(const std::string& name) {
    if (name.empty()) {
        return false;
    }
    bool hasLetter = false;
    for (char c : name) {
        if (!std::isalnum(c)) {
            return false;
        }
        if (std::isalpha(c)) {
            hasLetter = true;
        }
    }
    return hasLetter;
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
                std::string outputFileName;
                testLoadAskOutputFileName();
                std::cin >> outputFileName;
                while(!isValidName(outputFileName))
                {
                    std::cout << "\tНекорректное название для файла\n";
                    testLoadAskOutputFileName();
                    std::cin >> outputFileName;
                }
                testLoadFileView(start, end, step, outputFileName);
            }
        }

    }
}

void HandsShowMenu(){
    std::cout << "\n\tРУЧНОЕ ТЕСТИРОВАНИЕ:\n";
    std::cout << "\t1) Добавить указатель\n";
    std::cout << "\t2) Убрать указатель\n";
    std::cout << "\t3) Найти указатель\n";
    std::cout << "\t4) Вывести список указателей\n";
    std::cout << "\t5) Выйти из ручного тестирования\n";
    std::cout << "\tВведите номер команды: ";
}

void HandsAskValue(){
    std::cout << "\n\t\tВведите значение указателя: ";
}

void HandsMenu(){
    SmartPointer::LinkedList<std::string> LinkedListSmrtPtr;

    int choice;
    int index;
    std::string value;
    bool running = true;

    while(running){
        HandsShowMenu();
        choice = getValidatedInput(1, 6);

        switch(choice){
            case 1:
                HandsAskValue();
                std::cin >> value;
                LinkedListSmrtPtr.push_front(value);
            break;
            case 2:
                LinkedListSmrtPtr.pop_front();
            break;
            case 3:
                HandsAskValue();
                std::cin >> value;
                index = LinkedListSmrtPtr.find(value);
                if(index != -1){
                    std::cout << "\tУказатель расположен на " << index << " позиции\n";
                }
                else std::cout << "\tДанный указатель не был найден в списке\n";

            break;
            case 4:
                LinkedListSmrtPtr.print();
            break;
            case 5:
                running = false;
            break;
        }
    }

}

void menu() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        choice = getValidatedInput(1, 4);  // Ожидаем выбор команды от 1 до 4

        switch (choice) {
            case 1:
                testFuncConsoleView();
            break;
            case 2:
                testLoadMenu();
            break;
            case 3:
                HandsMenu();
            break;
            case 4:
                std::cout << "Завершение программы...\n";
            running = false;
            break;
        }
    }
}

