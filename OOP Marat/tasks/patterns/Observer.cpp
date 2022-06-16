#include <iostream>
#include <vector>

class Multiplication;

// Издатель. Число, участвующее в умножении. Посылает сигнал, когда изменяется значение.
class Multiplier {
private:
    std::vector<Multiplication *> subscribers;
    int value;

public:
    Multiplier(int value);

    void subscribe(Multiplication *multiplication);

    void unsubscribe(Multiplication *multiplication);

    void notify();

    void setValue(int new_value);

    int getValue();
};

// Подписчик. Результат умножения нескольких издателей. Изменяется при изменении любого из издателей.
class Multiplication {
private:
    int mul_result;
    std::vector<Multiplier *> publishers;

public:
    void addPublisher(Multiplier *publisher);

    void removePublisher(Multiplier *publisher);

    void update();

    void print();
};


Multiplier::Multiplier(int value) {
    this->value = value;
    this->subscribers = {};
}

// Подписать произведение к данному числу
void Multiplier::subscribe(Multiplication *multiplication) {
    this->subscribers.push_back(multiplication);
    multiplication->addPublisher(this);
    multiplication->update();
}

// Отписать произведение от данного числа
void Multiplier::unsubscribe(Multiplication *multiplication) {
    multiplication->removePublisher(this);
    int i = 0;
    while (this->subscribers[i] != multiplication && i < this->subscribers.size()) i++;
    if (i < this->subscribers.size())
        this->subscribers.erase(this->subscribers.begin() + i);
    multiplication->update();
}

void Multiplier::notify() {
    for (auto sub: this->subscribers) {
        sub->update();
    }
}

void Multiplier::setValue(int new_value) {
    this->value = new_value;
    this->notify();
}

int Multiplier::getValue() {
    return this->value;
}


// Добавляем к произведению новое проверяемое число
void Multiplication::addPublisher(Multiplier *publisher) {
    this->publishers.push_back(publisher);
}

// Убираем из произведения проверяемое число
void Multiplication::removePublisher(Multiplier *publisher) {
    int i = 0;
    while (this->publishers[i] != publisher && i < this->publishers.size()) i++;
    if (i < this->publishers.size())
        this->publishers.erase(this->publishers.begin() + i);
}

// Вычисляем произведение чисел
void Multiplication::update() {
    if (this->publishers.empty())
        this->mul_result = 0;
    else {
        this->mul_result = 1;
        for (auto mul: this->publishers) {
            this->mul_result *= mul->getValue();
        }
    }
}

void Multiplication::print() {
    std::cout << "My factors: ";
    for (auto num: this->publishers)
        std::cout << num->getValue() << " ";
    std::cout << "\nMy result: " << this->mul_result << "\n\n";
}


int main() {
    auto mul_1 = new Multiplication();
    auto mul_2 = new Multiplication();

    auto num_1 = new Multiplier(17);
    auto num_2 = new Multiplier(21);
    auto num_3 = new Multiplier(5);
    auto num_4 = new Multiplier(36);
    auto num_5 = new Multiplier(100);

    num_1->subscribe(mul_1);
    num_1->subscribe(mul_2);

    num_2->subscribe(mul_1);

    num_3->subscribe(mul_1);

    num_4->subscribe(mul_2);

    num_5->subscribe(mul_1);
    num_5->subscribe(mul_2);

    std::cout << "Initial results:\n";
    mul_1->print();
    mul_2->print();

    std::cout << "Unsubscribing 100:\n";
    num_5->unsubscribe(mul_1);
    num_5->unsubscribe(mul_2);
    mul_1->print();
    mul_2->print();

    std::cout << "Changing factor 36 to 123:\n";
    num_4->setValue(123);
    mul_1->print();
    mul_2->print();
}
