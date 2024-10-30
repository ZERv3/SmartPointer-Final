#pragma once

#include "../SmartPointer/SmartPointer.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

// Структура для тестов
struct TestStruct {
    int value;
    TestStruct(int v) : value(v) {}
};

//Нагрузочные тесты
double testSmrtPtrCreationPerformance(int numTests);
double testStdSharedPtrCreationPerformance(int numTests);

double testSmrtPtrCopyPerformance(int numTests);
double testStdSharedPtrCopyPerformance(int numTests);

double testSmrtPtrMovePerformance(int numTests);
double testStdSharedPtrMovePerformance(int numTests);

//Функциональные тесты
void testSmrtPtrCreationAndDestruction();
void testSmrtPtrAssignment();
void testSmrtPtrSelfAssignment();
void testSmrtPtrNullAssignment();
void testSmrtPtrMultiplePointers();

// TODO: переименовать Test под схему предыдущих названий - DONE

void testLoadConsoleView(int start, int end, int steps);
void testLoadFileView(int start, int end, int steps, const std::string& outputPath);
void testFuncConsoleView();
// Нужен ли вывод в файл?