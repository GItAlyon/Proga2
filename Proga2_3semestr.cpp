// Proga2_3semestr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_APPEARANCE_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define RESIDENTS_COUNT 10

typedef struct {
    char hairColor[MAX_NAME_LENGTH];
    char clothes[MAX_APPEARANCE_LENGTH];
} Appearance;

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[9]; // Идентификационный номер из 8 цифр
    Appearance appearance;
    char phone[MAX_PHONE_LENGTH];
} Resident;

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[9]; // Идентификационный номер из 8 цифр
    Appearance appearance;
} VisitorPass;

typedef struct {
    Resident resident;
    int isMatch;
} CheckResult;


// Функция инициализации изначальных данных жильцов
void initializeResidents(Resident residents[]) {
    //0
    strcpy(residents[0].firstName, "Иван");
    strcpy(residents[0].lastName, "Иванов");
    strcpy(residents[0].id, "01");
    strcpy(residents[0].appearance.hairColor, "Коричневый");
    strcpy(residents[0].appearance.clothes, "Синий свитер");
    strcpy(residents[0].phone, "123456789");
    //1
    strcpy(residents[1].firstName, "пётр");
    strcpy(residents[1].lastName, "сидоров");
    strcpy(residents[1].id, "02");
    strcpy(residents[1].appearance.hairColor, "коричневый");
    strcpy(residents[1].appearance.clothes, "красная футболка");
    strcpy(residents[1].phone, "123456790");
    //2
    strcpy(residents[2].firstName, "Ivan");
    strcpy(residents[2].lastName, "Ivanov");
    strcpy(residents[2].id, "03");
    strcpy(residents[2].appearance.hairColor, "Brown");
    strcpy(residents[2].appearance.clothes, "Blue sweater");
    strcpy(residents[2].phone, "123456791");
    // ... Инициализируем остальных жильцов (для примера добавим только одного)
}

// Функция ввода данных жильца, который пришёл на проверку
void inputVisitorPass(VisitorPass* visitor) {
    printf("Введите имя: ");
    gets_s(visitor->firstName);
    printf("Введите фамилию: ");
    gets_s(visitor->lastName);
    printf("Введите идентификационный номер (8 цифр): ");
    gets_s(visitor->id);
    printf("Введите цвет волос: ");
    gets_s(visitor->appearance.hairColor);
    printf("Введите одежду: ");
    gets_s(visitor->appearance.clothes);
}

// Функция проверки данных
CheckResult checkVisitor(const Resident residents[], VisitorPass visitor) {
    CheckResult result;
    int match = 1;
    int a = strcmp(residents[1].appearance.clothes, visitor.appearance.clothes);
    printf("%d", a);
    for (int i = 0; i < RESIDENTS_COUNT; i++) {
        if (strcmp(residents[i].firstName, visitor.firstName) == 0 &&
            strcmp(residents[i].lastName, visitor.lastName) == 0 &&
            strcmp(residents[i].id, visitor.id) == 0 &&
            strcmp(residents[i].appearance.hairColor, visitor.appearance.hairColor) == 0 &&
            strcmp(residents[i].appearance.clothes, visitor.appearance.clothes) == 0) {
            result.resident = residents[i];
            match = 1;
            break;
        }
        else {
            match = 0;
        }
    }
    result.isMatch = match;
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Resident residents[RESIDENTS_COUNT];
    VisitorPass visitor;

    initializeResidents(residents);

    // Ввод данных пришедшего жильца
    inputVisitorPass(&visitor);

    // Проверка данных
    CheckResult result = checkVisitor(residents, visitor);

    // Вывод результата проверки
    if (result.isMatch) {
        printf("Данные совпадают! Добро пожаловать, %s %s!\n", result.resident.firstName, result.resident.lastName);
    }
    else {
        printf("Данные не совпадают! Возможно, это монстр-двойник!\n");
    }

    return 0;
}





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
