#include "Tests.h"

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
