#include <iostream>
#include <chrono>

#include <cassert>
#include "test_structure.h"
#include "../SmartPointer/SmartPointer.h"
#include "../Sequences/LinkedList.h"

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
double testSharedPtrCreationPerformance(int numTests) {
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
double testSharedPtrCopyPerformance(int numTests) {
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
double testSharedPtrMovePerformance(int numTests) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTests; ++i) {
        std::shared_ptr<TestStruct> original = std::make_shared<TestStruct>(i);
        std::shared_ptr<TestStruct> moved = std::move(original);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}



