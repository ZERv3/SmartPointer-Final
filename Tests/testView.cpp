#include "tests.h"

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
        double sharedPtrCreationTime = testSharedPtrCreationPerformance(numTests);
        double sharedPtrCopyTime = testSharedPtrCopyPerformance(numTests);
        double sharedPtrMoveTime = testSharedPtrMovePerformance(numTests);

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
    std::ofstream outFile("../"+outputPath);
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
        double sharedPtrCreationTime = testSharedPtrCreationPerformance(numTests);
        double sharedPtrCopyTime = testSharedPtrCopyPerformance(numTests);
        double sharedPtrMoveTime = testSharedPtrMovePerformance(numTests);

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
