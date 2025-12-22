#ifndef PLANT_HPP
#define PLANT_HPP

#include <string> // библиотека для работы со строками
using namespace std;

// Базовый класс для всех растений 
class Plant{  

protected:
    string name; // название
    int age; // возраст
    string generalCharacteristics; // основные характеристики(высота, цвет, вид)

public:
    // Конструктор с заданным name - именем, age - возрастом и generalCharacteristics - характеристикой
    Plant(const string& name, int age, const string& generalCharacteristics);

    // Виртуальный деструктор для корректного удаления объектов наследников
    virtual ~Plant();
    
    // Виртуальная функция роста растения
    virtual void grow() = 0;

    // Виртуальная функция фотосинтеза растения
    virtual void photosynthesis() const = 0;

    // Виртуальная функция размножения растения
    virtual void reproduce() = 0;

    // Метод вывода строкового представления объекта
    string toString() const;

    // Установка возраста растения с проверкой
    void setAge(int age);

    // Получения возраста 
    int getAge() const;

    // Получение название растения
    string getName() const;

    // Получение общей характеристики растения
    string getGeneralCharacteristics() const;
};

// Производный класс Tree, наследуемого от класс Plant
class Tree: public Plant{
    
    private:
    
    string leafType; // тип листьев
    string habitat;  // среда обитания

    public:

    // Коструктор  с заданным name - именем, age - возрастом и generalCharacteristics - характеристикой
    // а также с leafType - типом листьев и habitat - средой обитания
    Tree(const string& name, int age, const string& generalCharacteristics,
         const string& leafType, const string& habitat);

    // Переопределение виртуальных методов
    void grow() override; // рост растения

    void photosynthesis() const override; // фотосинтез растения
    
    void reproduce() override; // размножение растения
    
    // Рассчет объема производимого кислорода деревом
    double calculateOxygenVolume() const;
    
    // Геттер для типа листьев
    string getLeafType() const;
    
    // Геттер для среды обитания
    string getHabitat() const;
};

// Произвольный класс Cactus, наследуемого от Plant
class Cactus: public Plant{
    
    private:
    
    string potSize;  // размер горшка
    string location; // место нахождения 

    public:
    
    // Коструктор  с заданным name - именем, age - возрастом и generalCharacteristics - характеристикой
    // а также с potSize - размером горшка и location - местом нахождения
    Cactus(const string& name, int age, const string& generalCharacteristics,
           const string& potSize, const string& location);

    // Переопределение виртуальных методов
    void grow() override; // рост растения

    void photosynthesis() const override; // фотосинтез растения
    
    void reproduce() override; // размножение растения
    
    // Метод полива растения с параметром amount - количество воды
    void water(double amount);
    
    // Геттер для размера горшка
    string getPotSize() const;

    // Геттер для место нахождения
    string getLocation() const;
};

#endif