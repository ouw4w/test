#include "plant.hpp" // подключение заговочного файла
#include <iostream>  // стандартная библиотека для работы с потоками ввода-вывода
#include <string> // для работы со строками
#include <stdexcept> // для обработки исключений 
#include <sstream> // для работы со строковыми потоками
using namespace std;

// Конструктор с заданным name - именем, age - возрастом и generalCharacteristics - характеристикой
Plant::Plant(const string& name, int age, const string& generalCharacteristics): 
        name(name), age(age), generalCharacteristics(generalCharacteristics){

    // Проверка типа invalid_argument
    if (name.empty()){
        throw invalid_argument("Имя не может быть пустым!");
    }

    // Проверка типа invalid_argument
    if (age < 0){
        throw invalid_argument("Возраст не может быть отрицательным!");
    }

    // Информационное сообщение о создании объекта
    cout << "Создано растение: " << name << endl;
}

// Деструктор класс Plant и вызывается при уничтожении объекта
Plant::~Plant(){
    cout << "Удалено растение: " << name << endl;
}

// Метод для получения строкового представления объекта
// Возвращает: строку с информацией о растении
string Plant::toString() const{
    // создание строкого потока
    stringstream ss;

    ss << "Информация о растении: " << endl;
    ss << "Название: " << name << endl;
    ss << "Возраст: " << age << " лет" << endl;
    ss << "Основная характеристика: " << generalCharacteristics << endl;
    
    return ss.str(); // преобразования потока в строку
}

// Сеттер для установки возраста растения с параметром age - новый возраст
void Plant::setAge(int age){
    // Проверка типа invalid_argument
    if (age < 0){
        throw invalid_argument("Возраст не может быть отрицательным");
    }

    this->age = age; // Установка нового значения возраста
}

// Геттер для получения возраста растения
// Возвращает: возраст растения в месяцах
int Plant::getAge() const{
    return age;
}

// Геттер для получения названия растения
// Возвращает: название растения
string Plant::getName() const{
    return name;
}

// Геттер для получения общей характеристики растения
// Возвращает: описание характеристик растения
string Plant::getGeneralCharacteristics() const{
    return generalCharacteristics;
}

// Коструктор  с заданным name - именем, age - возрастом и generalCharacteristics - характеристикой
// а также с leafType - типом листьев и habitat - средой обитания
Tree::Tree(const string& name, int age, const string& generalCharacteristics,
        const string& leafType, const string& habitat): 
        // вызов конструктора базового класса
        Plant(name, age, generalCharacteristics), leafType(leafType), habitat(habitat){  

    // Проверка типа invalid_argument
    if (leafType.empty()){
        throw invalid_argument("Тип листьев не может быть пустым");
    }

    // Проверка типа invalid_argument
    if (habitat.empty()){
        throw invalid_argument("Среда обитания не может быть пустой");
    }

    // Информационное сообщение о создании дерева
    cout << "Создано дерево типа " << leafType << " / в среде обитания: " << habitat << endl;
}

// Реализация виртуального метода grow() для дерева
void Tree::grow(){
    int growthMonths = 1; // количество месяцев роста
    age += growthMonths; // Увеличение возраста дерева

    cout << "Название дерева: " << getName() << " выросло за " << growthMonths << " год(а)/лет" << endl;

    // Дополнительная информация в зависимости от типа листьев
    if (leafType == "Лиственные"){
        cout << "Лиственное дерево(береза, осина, рябина)" << endl;
    } else if (leafType == "Хвойные"){
    cout << "Хвойное дерево(ель, сосна, кедр)" << endl;}
}

// Реализация виртуального метода photosynthesis() для дерева
void Tree::photosynthesis() const {
    cout << "Дерево " << getName() << " осуществляет фотосинтез:" << endl;
    cout << " За счет типа листьев: " << leafType << endl;
    cout << " Поглощает CO2, выделяет O2" << endl;
    
    // Дополнительная информация в зависимости от типа
    if (leafType == "Лиственные") {
        cout << "  Широкие листья эффективно улавливают свет, а также каждый год осенью оподают с деревьев" << endl;
    } else if (leafType == "Хвойные") {
        cout << "  Хвойные ветки сохраняет влагу в холодном климате, которые также остаются каждый год одного цвета" << endl;
    }
}

// Реализация виртуального метода reproduce() для дерева
void Tree::reproduce() {
    cout << " Размножение происходит за счёт семен/шишек " << endl;
    
    if (leafType == "Лиственные") {
        cout << " У лиственных семена разносятся ветром или животными" << endl;
        cout << " Также могут давать плоды/желуди/орехи" << endl;
    } else if (leafType == "Хвойные") {
        cout << " У хвойных образуется шишки с семенами" << endl;
        cout << " А также семена высыпаются при созревании шишек" << endl;
    }
    
    cout << " Новые деревья могут вырасти в радиусе 100м" << endl;
}

// Метод для вычисления объема производимого кислорода
double Tree::calculateOxygenVolume() const {
    //  формула: возраст * коэффициент
    double baseOxygen = age * 10.0;  
    
    // Коэффициент в зависимости от типа листьев
    double multiplier = 1.0;
    if (leafType == "Лиственные") {
        multiplier = 1.5;  // лиственные производят больше кислорода
    } else if (leafType == "Хвойные") {
        multiplier = 1.2;  // хвойные немного меньше
    }
    
    // Итоговый объем кислорода
    double oxygen = baseOxygen * multiplier;
    
    cout << "Дерево '" << getName() << "' производит примерно " 
         << oxygen << " литров кислорода в год" << endl;
    
    return oxygen; // возвращает объем кислорода
}

// Геттер для получения типа листьев дерева
string Tree::getLeafType() const {
    return leafType;
}

// Геттер для получения среды обитания дерева
string Tree::getHabitat() const {
    return habitat;
}

// Коструктор  с заданным name - именем, age - возрастом и generalCharacteristics - характеристикой
// а также с potSize - размером горшка и location - местом нахождения
Cactus::Cactus(const string& name, int age, const string& generalCharacteristics,
        const string& potSize, const string& location): 
        // вызов конструктора базового класса
        Plant(name, age, generalCharacteristics), potSize(potSize), location(location){

    // Проверка типа invalid_argument
    if (potSize.empty()) {
        throw invalid_argument("Ошибка: размер горшка не может быть пустым!");
    }
    // Проверка типа invalid_argument
    if (location.empty()) {
        throw invalid_argument("Ошибка: местоположение не может быть пустым!");
    }        

    cout << "Создан кактус в кашпо размером : " << potSize << " , который находится  " << location << endl;
}

// Реализация виртуального метода grow() для кактуса
void Cactus::grow(){

    int growthMonths = 1; // Количество месяцев роста
    age += growthMonths; // Увеличение возраста кактуса

    cout << "Кактус " << getName() << " растет " << growthMonths << endl;
    cout << " Очень медленный рост" << endl;

    // Влияние условий на рост
    if (location == "Солнечное место") {
        cout << " Благоприятные условия(солнце) хорошо способствуют росту кактуса" << endl;
    } else if (location == "Тень") {
        cout << " Плохие условия(тень), кактус почти не растет" << endl;
    }
    
    // Влияние размера горшка
    if (potSize == "Маленький") {
        cout << " Горшок мал: рост кактуса замедляется" << endl;
    } else if (potSize == "Большой") {
        cout << " Просторный горшок: хорошие условия для роста кактуса" << endl;
    }
}

// Реализация виртуального метода photosynthesis() для кактуса
void Cactus::photosynthesis() const {
    cout << "Кактус " << getName() << " использует CAM-фотосинтез:" << endl;
    cout << " Особый тип фотосинтеза для засушливых условий" << endl;
    cout << " Открывает устьица ночью, чтобы не терять влагу днем" << endl;
    cout << " Поглощает CO2 ночью и хранит его" << endl;
    cout << " Днем использует запасы CO2 для фотосинтеза" << endl;
    cout << " Может экономит воду в условиях пустыни" << endl;
}

// Реализация виртуального метода reproduce() для кактуса
void Cactus::reproduce() {
    
    cout << " Размножение происходит за счёт образования боковых отростков" << endl;
    cout << " Можно отломить детку и посадить в новый горшок" << endl;
    cout << " Также может размножаться семенами" << endl;
    cout << " Цветет редко, обычно ночью" << endl;
}

// Метод для описания процесса полива кактуса
void Cactus::water(double amount) {
    cout << " Полив кактуса " << getName() << ":" << endl;
    cout << " Количество воды: " << amount << " мл" << endl;
    
    // Правила полива кактусов
    if (amount > 200) {
        cout << " Обильный полив" << endl;
        cout << " Кактус запасает воду в стебле" << endl;
    } else if (amount > 50) {
        cout << " Умеренный полив" << endl;
    } else {
        cout << " Слишком мало воды для кактуса" << endl;
    }
    
    // Предупреждение о переливе
    if (amount > 300) {
        cout << " Слишком много воды, могут загнить корни кактуса!" << endl;
    }
}

// Геттер для получения размера горшка кактуса
string Cactus::getPotSize() const {
    return potSize;
}

// Геттер для получения местоположения кактуса
string Cactus::getLocation() const {
    return location;
}