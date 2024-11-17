// Proga2_3semestr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <windows.h>

#include <iostream>
#include <string>
#include <cstring>

#define MAX_NAME_LENGTH 50
#define MAX_APPEARANCE_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define RESIDENTS_COUNT 3

class Appearance {
private:
    char hairColor[MAX_NAME_LENGTH];
    char clothes[MAX_APPEARANCE_LENGTH];

public:
    Appearance() {
        strcpy(hairColor, "");
        strcpy(clothes, "");
    }

    void setHairColor(const char* color) {
        strncpy(hairColor, color, MAX_NAME_LENGTH);
        hairColor[MAX_NAME_LENGTH - 1] = '\0';
    }

    void setClothes(const char* clothing) {
        strncpy(clothes, clothing, MAX_APPEARANCE_LENGTH);
        clothes[MAX_APPEARANCE_LENGTH - 1] = '\0';
    }

    const char* getHairColor() const {
        return hairColor;
    }

    const char* getClothes() const {
        return clothes;
    }
};

class Resident {
private:
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[3]; // Идентификационный номер из 2 цифр
    Appearance appearance;
    char phone[MAX_PHONE_LENGTH];

public:
    
    Resident() {
        firstName[0] = '\0';
        lastName[0] = '\0';
        id[0] = '\0';
        phone[0] = '\0';
    }
    Resident(const char* firstName, const char* lastName, const char* id, const Appearance& appearance, const char* phone) {
        setFirstName(firstName);
        setLastName(lastName);
        setID(id);
        setAppearance(appearance);
        setPhone(phone);
    }

    void setFirstName(const char* name) {
        strncpy(firstName, name, MAX_NAME_LENGTH);
        firstName[MAX_NAME_LENGTH - 1] = '\0';
    }

    void setLastName(const char* name) {
        strncpy(lastName, name, MAX_NAME_LENGTH);
        lastName[MAX_NAME_LENGTH - 1] = '\0';
    }

    void setID(const char* identification) {
        strncpy(id, identification, 2);
        id[2] = '\0';
    }

    void setAppearance(const Appearance& ap) {
        appearance = ap;
    }

    void setPhone(const char* number) {
        strncpy(phone, number, MAX_PHONE_LENGTH);
        phone[MAX_PHONE_LENGTH - 1] = '\0';
    }

    const char* getFirstName() const {
        return firstName;
    }

    const char* getLastName() const {
        return lastName;
    }

    const char* getID() const {
        return id;
    }

    Appearance& getAppearance() { //Для возврата ссылки
        return appearance;
    }

    const char* getPhone() const {
        return phone;
    }
};

class VisitorPass {
private:
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[3]; // Идентификационный номер из 2 цифр
    Appearance appearance;

public:
    VisitorPass() {
        strcpy(firstName, "");
        strcpy(lastName, "");
        strcpy(id, "");
    }
    VisitorPass(const char* firstName, const char* lastName, const char* id, const Appearance& appearance) {
        setFirstName(firstName);
        setLastName(lastName);
        setID(id);
        setAppearance(appearance);
    }
    void setFirstName(const char* name) {
        strncpy(firstName, name, MAX_NAME_LENGTH);
        firstName[MAX_NAME_LENGTH - 1] = '\0';
    }

    void setLastName(const char* name) {
        strncpy(lastName, name, MAX_NAME_LENGTH);
        lastName[MAX_NAME_LENGTH - 1] = '\0';
    }

    void setID(const char* identification) {
        strncpy(id, identification, 2);
        id[2] = '\0';
    }

    void setAppearance(const Appearance& ap) {
        appearance = ap;
    }

    const char* getFirstName() const {
        return firstName;
    }

    const char* getLastName() const {
        return lastName;
    }

    const char* getID() const {
        return id;
    }

    Appearance& getAppearance() { // Для возврата ссылки
        return appearance;
    }
};

// Инициализация изначальных данных жильцов
void initializeResidents(Resident* residents) {
    Appearance ap;

    ap.setHairColor("Коричневый");
    ap.setClothes("Синий свитер");
    residents[0] = Resident("Иван", "Иванов", "01", ap, "123456789");

    ap.setHairColor("Коричневый");
    ap.setClothes("Красная футболка");
    residents[1] = Resident("Пётр", "Сидоров", "02", ap, "123456790");

    ap.setHairColor("Brown");
    ap.setClothes("Blue sweater");
    residents[2] = Resident("Ivan", "Ivanov", "03", ap, "123456791");
}

// Ввод данных жильца, который пришёл на проверку
void inputVisitorPass(VisitorPass& visitor) {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char id[3];
    char hairColor[MAX_NAME_LENGTH];
    char clothes[MAX_APPEARANCE_LENGTH];

    std::cout << "Введите имя: ";
    std::cin.getline(name, MAX_NAME_LENGTH);
    visitor.setFirstName(name);

    std::cout << "Введите фамилию: ";
    std::cin.getline(surname, MAX_NAME_LENGTH);
    visitor.setLastName(surname);

    std::cout << "Введите идентификационный номер (2 цифры): ";
    std::cin.getline(id, 3);
    visitor.setID(id);

    std::cout << "Введите цвет волос: ";
    std::cin.getline(hairColor, MAX_NAME_LENGTH);
    visitor.getAppearance().setHairColor(hairColor);

    std::cout << "Введите одежду: ";
    std::cin.getline(clothes, MAX_APPEARANCE_LENGTH);
    visitor.getAppearance().setClothes(clothes);
}

// Функция проверки данных
int checkVisitor(Resident* residents, VisitorPass visitor) {
    for (int i = 0; i < RESIDENTS_COUNT; i++) {
        if (strcmp(residents[i].getFirstName(), visitor.getFirstName()) == 0 &&
            strcmp(residents[i].getLastName(), visitor.getLastName()) == 0 &&
            strcmp(residents[i].getID(), visitor.getID()) == 0 &&
            strcmp(residents[i].getAppearance().getHairColor(), visitor.getAppearance().getHairColor()) == 0 &&
            strcmp(residents[i].getAppearance().getClothes(), visitor.getAppearance().getClothes()) == 0) {
            return 1; // Совпадение
        }
    }
    return 0; // Нет совпадения
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Resident* residents = new Resident[RESIDENTS_COUNT];
    VisitorPass visitor;

    initializeResidents(residents);

    // Ввод данных пришедшего жильца
    inputVisitorPass(visitor);

    // Проверяем данные
    if (checkVisitor(residents, visitor)) {
        std::cout << "\nДанные совпадают. Допуск разрешён.\n";
    }
    else {
        std::cout << "\nДанные не совпадают. Возможно, это монстр-двойник!\n";
    }
    delete[] residents; // Освобождаем память
    return 0;
}


/*#define MAX_NAME_LENGTH 50
#define MAX_APPEARANCE_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define RESIDENTS_COUNT 10

class Appearance {
private:
    char hairColor[MAX_NAME_LENGTH];
    char clothes[MAX_APPEARANCE_LENGTH];

public:
    void setAppearance(const char* hair, const char* cloth) {
        strncpy(hairColor, hair, MAX_NAME_LENGTH);
        strncpy(clothes, cloth, MAX_APPEARANCE_LENGTH);
    }

    const char* getHairColor() const {
        return hairColor;
    }

    const char* getClothes() const {
        return clothes;
    }
};

class Resident {
private:
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[9]; // Идентификационный номер из 8 цифр
    Appearance appearance;
    char phone[MAX_PHONE_LENGTH];

public:
    void initialize(const char* first, const char* last, const char* identity, const char* hair, const char* cloth, const char* phoneNum) {
        strncpy(firstName, first, MAX_NAME_LENGTH);
        strncpy(lastName, last, MAX_NAME_LENGTH);
        strncpy(id, identity, 9); // 8 цифр и 1 для нуля
        appearance.setAppearance(hair, cloth);
        strncpy(phone, phoneNum, MAX_PHONE_LENGTH);
    }

    const char* getFirstName() const {
        return firstName;
    }

    const char* getLastName() const {
        return lastName;
    }

    const char* getId() const {
        return id;
    }

    const Appearance& getAppearance() const {
        return appearance;
    }

    const char* getPhone() const {
        return phone;
    }
};

class VisitorPass {
private:
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[9]; // Идентификационный номер из 8 цифр
    Appearance appearance;

public:
    void inputVisitorPass() {
        std::cout << "Введите имя: ";
        std::cin >> firstName;
        std::cout << "Введите фамилию: ";
        std::cin >> lastName;
        std::cout << "Введите идентификационный номер (8 цифр): ";
        std::cin >> id;
        std::cout << "Введите цвет волос: ";
        char hair[MAX_NAME_LENGTH];
        std::cin.ignore();
        std::cin.getline(hair, sizeof(hair));
        appearance.setAppearance(hair, "");
        std::cout << "Введите одежду: ";
        char clothes[MAX_APPEARANCE_LENGTH];
        std::cin.ignore();
        std::cin.getline(clothes, sizeof(clothes));
        appearance.setAppearance(clothes, "");
    }

    const char* getFirstName() const {
        return firstName;
    }

    const char* getLastName() const {
        return lastName;
    }

    const char* getId() const {
        return id;
    }

    const Appearance& getAppearance() const {
        return appearance;
    }
};

class SecurityCheck {
public:
    static int checkVisitor(const Resident residents[], const VisitorPass& visitor) {
        for (int i = 0; i < RESIDENTS_COUNT; i++) {
            if (strcmp(residents[i].getFirstName(), visitor.getFirstName()) == 0 &&
                strcmp(residents[i].getLastName(), visitor.getLastName()) == 0 &&
                strcmp(residents[i].getId(), visitor.getId()) == 0 &&
                strcmp(residents[i].getAppearance().getHairColor(), visitor.getAppearance().getHairColor()) == 0 &&
                strcmp(residents[i].getAppearance().getClothes(), visitor.getAppearance().getClothes()) == 0) {
                return 1; // Совпадение найдено
            }
        }
        return 0; // Совпадение не найдено
    }
};

// Функция инициализации изначальных данных жильцов
void initializeResidents(Resident residents[]) {
    residents[0].initialize("Иван", "Иванов", "00000001", "Коричневый", "Синий свитер", "123456789");
    residents[1].initialize("пётр", "сидоров", "02", "чёрный", "красная футболка", "123456790");
    residents[2].initialize("Ivan", "Ivanov", "00000003", "Brown", "Blue sweater", "123456791");
    // ... Инициализируем остальных жильцов
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Resident residents[RESIDENTS_COUNT];
    VisitorPass visitor;

    initializeResidents(residents);

    // Ввод данных посетителя
    visitor.inputVisitorPass();

    // Проверка
    if (SecurityCheck::checkVisitor(residents, visitor)) {
        std::cout << "\nДанные совпадают. Допуск разрешён.\n";
    }
    else {
        std::cout << "\nДанные не совпадают. Возможно, это монстр-двойник!\n";
    }

    return 0;
}*/




/*#define MAX_NAME_LENGTH 50
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
int checkVisitor(const Resident residents[], VisitorPass visitor) {
    for (int i = 0; i < RESIDENTS_COUNT; i++) {
        if (strcmp(residents[i].firstName, visitor.firstName) == 0 &&
            strcmp(residents[i].lastName, visitor.lastName) == 0 &&
            strcmp(residents[i].id, visitor.id) == 0 &&
            strcmp(residents[i].appearance.hairColor, visitor.appearance.hairColor) == 0 &&
            strcmp(residents[i].appearance.clothes, visitor.appearance.clothes) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Resident residents[RESIDENTS_COUNT];
    VisitorPass visitor;

    initializeResidents(residents);

    // Ввод данных пришедшего жильца
    inputVisitorPass(&visitor);

    // Вывод результата проверки
    if (checkVisitor(residents, visitor)) {
        printf("\nДанные совпадают. Допуск разрешён.\n");
    }
    else {
        printf("\nДанные не совпадают. Возможно, это монстр-двойник!\n");
    }

    return 0;
}*/





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
