#pragma once

#include "../SmartPointer/SmartPointer.h"
#include <iostream>

namespace SmartPointer {

    template <typename T>

    // Класс ячейки
    class Node {
    public:
        T data;
        SmrtPtr<Node<T>> next;

        Node(T value) : data(value), next(nullptr) {}
    };

    // Класс связного списка
    template <typename T>
    class LinkedList {
    private:
        SmrtPtr<Node<T>> head;
        int size;

    public:
        LinkedList() : head(nullptr), size(0) {}

        // Добавляем элемент в начало списка
        void push_front(T value) {
            SmrtPtr<Node<T>> newNode(new Node<T>(value));
            newNode->next = head;
            head = newNode;
            size++;
        }

        // Добавляем элемент в конец списка
        void push_back(T value) {
            SmrtPtr<Node<T>> newNode(new Node<T>(value));
            if (size > 0) {
                SmrtPtr<Node<T>> temp = head;
                while(temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            } else head = newNode;
            size++;
        }

        // Выводим список
        void print() const {
            SmrtPtr<Node<T>> current = head;
            while (current.get() != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }

        // Убираем элемент с начала списка
        void pop_front() {
            if (head.get() != nullptr) {
                SmrtPtr<Node<T>> temp = head;
                head = head->next;
                size--;
            }
        }

        // Убираем элемент с конца списка
        void pop_back() {
            if (size > 0) {
                SmrtPtr<Node<T>> temp = head;
                while(temp->next->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nullptr;
                size--;
            }
        }

        // Линейный поиск элемента
        int find(T value) const {
            SmrtPtr<Node<T>> current = head;
            int index = 0;
            while (current.get() != nullptr) {
                if (current->data == value) {
                    return index;
                }
                current = current->next;
                index++;
            }
            return -1;
        }

        //[[nodicard]] - значит всегда применяется где-то, не проигнорирован
        [[nodiscard]] int getSize() const {
            return size;
        }

        Node<T> getHead() const {
            return head;
        }

    };

}