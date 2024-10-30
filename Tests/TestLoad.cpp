#include "Tests.h"

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



