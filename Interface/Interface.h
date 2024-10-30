#pragma once

#include "../Tests/Tests.h"

#include <iostream>
#include <limits>  // Для очистки ввода

void showMenu();
void testLoadMenu();
void testLoadShowMenu();
void testLoadAskStart();
void testLoadAskEnd();
void testLoadAskStep();

int getValidatedInput(int min, int max);
void menu();