#include <iostream>
#include <ctime>

// Человек. Потенциально имеет металлические предметы
class Human {
public:
    bool has_metal;
    Human() {
        this->has_metal = (rand() % 100) >= 95;  // 5%, что человек проносит металлические предметы
    }
};

// Металлодетектор. Является синглтоном
class MetalDetectorSystem {
private:
    static MetalDetectorSystem* instance;
    int violation_count;  // Счётчик количества нарушений
    MetalDetectorSystem() {
        this->violation_count = 0;
    }

public:
    static MetalDetectorSystem* getInstance() {
        if (MetalDetectorSystem::instance == nullptr) {
            MetalDetectorSystem::instance = new MetalDetectorSystem();
        }
        return instance;
    }

    // Проверяет человека на наличие металла
    bool checkMetal(const Human& human) {
        if (human.has_metal) {
            std::cout << "wee-woo-wee-woo\n";
            this->violation_count++;
            return true;
        }
        return false;
    }

    int getCount() {
        return this->violation_count;
    }
};
MetalDetectorSystem* MetalDetectorSystem::instance = nullptr;


// Вход в здание. Оснащён металлодетектором
class Entrance {
private:
    MetalDetectorSystem* metal_detector;

public:
    Entrance(MetalDetectorSystem* metal_detector) {
        this->metal_detector = metal_detector;
    }

    void acceptPeople(int n_people) {
        for (int i = 0; i < n_people; i++) {
            Human person;
            this->metal_detector->checkMetal(person);
        }
    }

    void printResults() {
        std::cout << "Entrance #" << this << "\n";
        std::cout << "Metal Detector #" << this->metal_detector << "\n";
        std::cout << "People caught: " << this->metal_detector->getCount() << "\n\n";
    }
};


int main() {
    srand(time(nullptr));  // Сеем зерно рандома

    // Создаём входы в здание
    Entrance entrance_a(MetalDetectorSystem::getInstance());
    Entrance entrance_b(MetalDetectorSystem::getInstance());
    Entrance entrance_c(MetalDetectorSystem::getInstance());

    // Последовательно принимаем людей и проверяем, что работает единственный металлодетектор
    entrance_a.acceptPeople(100);
    entrance_a.printResults();

    entrance_b.acceptPeople(75);
    entrance_b.printResults();

    entrance_c.acceptPeople(150);
    entrance_c.printResults();
}