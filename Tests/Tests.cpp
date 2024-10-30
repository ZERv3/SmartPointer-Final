#include "Tests.h"

//--------------------
//ФУНКЦИОНАЛЬНЫЕ ТЕСТЫ
//--------------------

// Проверка создания и уничтожения указателя
void testSmrtPtrCreationAndDestruction() {
    SmrtPtr<int> ptr1(new int(10));
    assert(*ptr1 == 10);  // Проверяем, что значение корректно инициализировалось

    SmrtPtr<int> ptr2 = ptr1;  // Проверка копирования
    assert(*ptr2 == 10);       // Значение должно быть тем же
    assert(ptr1.getRefCount() == 2); // Проверяем счетчик ссылок

    // После выхода из функции `ptr1` и `ptr2` должны освободить память, т.к. ref_count станет 0
}

// Проверка привязки
void testSmrtPtrAssignment() {
    SmrtPtr<int> ptr1(new int(20));
    SmrtPtr<int> ptr2;

    ptr2 = ptr1;  // Оператор присваивания
    assert(*ptr2 == 20);           // Значение должно быть скопировано
    assert(ptr1.getRefCount() == 2); // Счетчик ссылок должен быть 2 после присваивания
}

// Проверка самоприсваивания (присваивание указателя самому себе)
void testSmrtPtrSelfAssignment() {
    SmrtPtr<int> ptr1(new int(30));
    ptr1 = ptr1;  // Самоприсваивание
    assert(*ptr1 == 30);           // Значение не должно измениться
    assert(ptr1.getRefCount() == 1); // Счетчик ссылок остается прежним
}

// Проверка присваивания nullptr
void testSmrtPtrNullAssignment() {
    SmrtPtr<int> ptr1(new int(40));
    ptr1 = SmrtPtr<int>(nullptr);  // Присваиваем nullptr

    assert(ptr1.get() == nullptr); // Проверяем, что указатель теперь null
}

// Проверка счетчика ссылок
void testSmrtPtrMultiplePointers() {
    SmrtPtr<int> ptr1(new int(50));
    SmrtPtr<int> ptr2 = ptr1;
    SmrtPtr<int> ptr3 = ptr1;

    assert(*ptr1 == 50);
    assert(*ptr2 == 50);
    assert(*ptr3 == 50);
    assert(ptr1.getRefCount() == 3); // Проверяем, что счетчик ссылок равен 3
}

//-----------------
//НАГРУЗОЧНЫЕ ТЕСТЫ
//-----------------

// Функция теста создания объектов для SmrtPtr
double testSmrtPtrCreationPerformance(int numTests) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        SmrtPtr<TestStruct> ptr(new TestStruct(i));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция теста создания объектов для std::shared_ptr
double testStdSharedPtrCreationPerformance(int numTests) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        std::shared_ptr<TestStruct> ptr = std::make_shared<TestStruct>(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция теста копирования для SmrtPtr
double testSmrtPtrCopyPerformance(int numTests) {
    SmrtPtr<TestStruct> original(new TestStruct(0));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        SmrtPtr<TestStruct> copy = original;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция теста копирования для std::shared_ptr
double testStdSharedPtrCopyPerformance(int numTests) {
    std::shared_ptr<TestStruct> original = std::make_shared<TestStruct>(0);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        std::shared_ptr<TestStruct> copy = original;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция теста перемещения для SmrtPtr
double testSmrtPtrMovePerformance(int numTests) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        SmrtPtr<TestStruct> original(new TestStruct(i));
        SmrtPtr<TestStruct> moved = std::move(original);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция теста перемещения для std::shared_ptr
double testStdSharedPtrMovePerformance(int numTests) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        std::shared_ptr<TestStruct> original = std::make_shared<TestStruct>(i);
        std::shared_ptr<TestStruct> moved = std::move(original);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

//------------
//ВЫВОД ТЕСТОВ
//------------

void testFuncConsoleView() {
    try {
        testSmrtPtrCreationAndDestruction();
    } catch (const std::runtime_error& e) {  // Ловим исключение
        std::cerr << "Ошибка: создание и удаление" << e.what() << std::endl;
    }

    try {
        testSmrtPtrAssignment();
    } catch (const std::runtime_error& e) {  // Ловим исключение
        std::cerr << "Ошибка: создание и удаление" << e.what() << std::endl;
    }

    try {
        testSmrtPtrCreationAndDestruction();
    } catch (const std::runtime_error& e) {  // Ловим исключение
        std::cerr << "Ошибка: создание и удаление" << e.what() << std::endl;
    }

    try {
        testSmrtPtrCreationAndDestruction();
    } catch (const std::runtime_error& e) {  // Ловим исключение
        std::cerr << "Ошибка: создание и удаление" << e.what() << std::endl;
    }

    std::cout << "\n\tВсе тесты пройдены\n" << std::endl;
}

void testLoadConsoleView(int start, int end, int steps) {
    int step_size = (end - start) / (steps - 1);  // Вычисляем шаг

    for (int i = 0; i < steps; ++i) {
        int numTests = start + i * step_size;  // Количество тестов на каждом шаге

        // Получаем времена выполнения для SmrtPtr
        double smrtPtrCreationTime = testSmrtPtrCreationPerformance(numTests);
        double smrtPtrCopyTime = testSmrtPtrCopyPerformance(numTests);
        double smrtPtrMoveTime = testSmrtPtrMovePerformance(numTests);

        // Получаем времена выполнения для std::shared_ptr
        double sharedPtrCreationTime = testStdSharedPtrCreationPerformance(numTests);
        double sharedPtrCopyTime = testStdSharedPtrCopyPerformance(numTests);
        double sharedPtrMoveTime = testStdSharedPtrMovePerformance(numTests);

        // Вычисляем процентное соотношение
        double creationRatio = (smrtPtrCreationTime / sharedPtrCreationTime) * 100;
        double copyRatio = (smrtPtrCopyTime / sharedPtrCopyTime) * 100;
        double moveRatio = (smrtPtrMoveTime / sharedPtrMoveTime) * 100;

        // Печатаем количество итераций и заголовки "Create", "Copy", "Move"
        std::cout << std::setw(12) << numTests
                  << std::setw(16) << "Create"
                  << std::setw(16) << "Copy"
                  << std::setw(16) << "Move"
                  << std::endl;

        // Печатаем данные для SmrtPtr
        std::cout << std::setw(12) << "SmrtPtr:"
                  << std::setw(16) << smrtPtrCreationTime
                  << std::setw(16) << smrtPtrCopyTime
                  << std::setw(16) << smrtPtrMoveTime
                  << std::endl;

        // Печатаем данные для std::shared_ptr
        std::cout << std::setw(12) << "shared_ptr:"
                  << std::setw(16) << sharedPtrCreationTime
                  << std::setw(16) << sharedPtrCopyTime
                  << std::setw(16) << sharedPtrMoveTime
                  << std::endl;

        // Печатаем процентное соотношение
        std::cout << std::setw(12) << "%"
                  << std::setw(16) << creationRatio << "%"
                  << std::setw(16) << copyRatio << "%"
                  << std::setw(16) << moveRatio << "%"
                  << std::endl;

        // Разделительная линия между итерациями
        std::cout << std::string(60, '-') << std::endl;
    }
}

void testLoadFileView(int start, int end, int steps, const std::string& outputPath) {
    // Открываем файл для записи
    std::ofstream outFile("../Output/"+outputPath+".dat");
    if (!outFile) {
        std::cerr << "Ошибка открытия файла: " << outputPath << std::endl;
        return;
    }

    //     // Записываем результаты в файл в формате .dat
    //     outFile << numTests << " " << smrtPtrCreationTime << " " << smrtPtrCopyTime << std::endl;
    // }

    int step_size = (end - start) / (steps - 1);  // Вычисляем шаг

    for (int i = 0; i < steps; ++i) {
        int numTests = start + i * step_size;  // Количество тестов на каждом шаге

        // Получаем времена выполнения для SmrtPtr
        double smrtPtrCreationTime = testSmrtPtrCreationPerformance(numTests);
        double smrtPtrCopyTime = testSmrtPtrCopyPerformance(numTests);
        double smrtPtrMoveTime = testSmrtPtrMovePerformance(numTests);

        // Получаем времена выполнения для std::shared_ptr
        double sharedPtrCreationTime = testStdSharedPtrCreationPerformance(numTests);
        double sharedPtrCopyTime = testStdSharedPtrCopyPerformance(numTests);
        double sharedPtrMoveTime = testStdSharedPtrMovePerformance(numTests);

        // Вычисляем процентное соотношение
        double creationRatio = (smrtPtrCreationTime / sharedPtrCreationTime) * 100;
        double copyRatio = (smrtPtrCopyTime / sharedPtrCopyTime) * 100;
        double moveRatio = (smrtPtrMoveTime / sharedPtrMoveTime) * 100;

        // Печатаем количество итераций и заголовки "Create", "Copy", "Move"
        outFile << std::setw(12) << numTests
                  << std::setw(16) << "Create"
                  << std::setw(16) << "Copy"
                  << std::setw(16) << "Move"
                  << std::endl;

        // Печатаем данные для SmrtPtr
        outFile << std::setw(12) << "SmrtPtr:"
                  << std::setw(16) << smrtPtrCreationTime
                  << std::setw(16) << smrtPtrCopyTime
                  << std::setw(16) << smrtPtrMoveTime
                  << std::endl;

        // Печатаем данные для std::shared_ptr
        outFile << std::setw(12) << "shared_ptr:"
                  << std::setw(16) << sharedPtrCreationTime
                  << std::setw(16) << sharedPtrCopyTime
                  << std::setw(16) << sharedPtrMoveTime
                  << std::endl;

        // Печатаем процентное соотношение
        outFile << std::setw(12) << "%"
                  << std::setw(16) << creationRatio << "%"
                  << std::setw(16) << copyRatio << "%"
                  << std::setw(16) << moveRatio << "%"
                  << std::endl;

        // Разделительная линия между итерациями
        outFile << std::string(60, '-') << std::endl;
    }

    outFile.close();
    std::cout << "Данные успешно записаны в файл " << outputPath << std::endl;
}



