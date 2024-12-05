#include <iostream>
#include <string>

#define MAX_DISHES 10
#define MAX_ORDERS 5

class Dish {
private:
    std::string name;
    float price;
    int quantity;

public:
    Dish(const std::string& dish_name, float dish_price, int dish_quantity)
        : name(dish_name), price(dish_price), quantity(dish_quantity) {}

    void print() const {
        printf("Блюдо: %s, Цена: %.2f, Количество порций: %d\n", name.c_str(), price, quantity);
    }

    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    const std::string& getName() const { return name; }
};

class Menu {
private:
    Dish* dishes[MAX_DISHES];
    int dish_count;

public:
    Menu() : dish_count(0) {}

    void addDish(Dish* dish) {
        if (dish_count < MAX_DISHES) {
            dishes[dish_count] = dish;
            dish_count++;
        }
        else {
            printf("Меню переполнено!\n");
        }
    }

    void print() const {
        printf("Меню:\n");
        for (int i = 0; i < dish_count; i++) {
            dishes[i]->print();
        }
        printf("\n");
    }

    Dish* getDish(int index) const {
        if (index >= 0 && index < dish_count) {
            return dishes[index];
        }
        return nullptr;
    }
};

class Client {
private:
    std::string name;
    std::string phone;

public:
    Client(const std::string& client_name, const std::string& client_phone)
        : name(client_name), phone(client_phone) {}

    void print() const {
        printf("Клиент: %s, Телефон: %s\n", name.c_str(), phone.c_str());
    }

    const std::string& getName() const { return name; }
};

class Employee {
private:
    std::string name;
    int id;

public:
    Employee(const std::string& employee_name, int employee_id)
        : name(employee_name), id(employee_id) {}

    void print() const {
        printf("Официант: %s, ID: %d\n", name.c_str(), id);
    }

    const std::string& getName() const { return name; }
};


class Order {
private:
    static int totalOrders;  // Статическое поле для подсчёта заказов
    std::string clientName;
    Dish* orderedDishes[MAX_ORDERS];
    int orderCount;
    float totalPrice;

public:
    // Конструктор
    Order(const std::string& client)
        : clientName(client), orderCount(0), totalPrice(0.0f) {
        totalOrders++;
    }

    ~Order() {
        totalOrders--;  // Уменьшаем общее количество заказов
    }

    void addDish(Dish* dish) {
        if (orderCount < MAX_ORDERS) {
            orderedDishes[orderCount] = dish;
            totalPrice += dish->getPrice() * dish->getQuantity();
            orderCount++;
        }
        else {
            printf("Заказ переполнен!\n");
        }
    }

    void print() const {
        printf("Заказ клиента: %s\n", clientName.c_str());
        printf("Блюда в заказе:\n");
        for (int i = 0; i < orderCount; i++) {
            orderedDishes[i]->print();
        }
        printf("Общая стоимость: %.2f\n", totalPrice);
    }

    // Статический метод
    static int getTotalOrders() {
        return totalOrders;
    }

    // Возврат стоимости через указатель
    void getTotalPricePtr(float* ptr) const {
        if (ptr) {
            *ptr = totalPrice;
        }
    }

    // Возврат стоимости через ссылку
    void getTotalPriceRef(float& ref) const {
        ref = totalPrice;
    }

    // Использование оператора this
    bool isMoreExpensive(const Order& other) const {
        return this->totalPrice > other.totalPrice;
    }

    // Перегрузка оператора +
    Order operator+(const Order& other) const {
        Order combinedOrder(clientName + " & " + other.clientName);
        combinedOrder.totalPrice = this->totalPrice + other.totalPrice;
        for (int i = 0; i < this->orderCount; i++) {
            combinedOrder.addDish(this->orderedDishes[i]);
        }
        for (int i = 0; i < other.orderCount; i++) {
            combinedOrder.addDish(other.orderedDishes[i]);
        }
        return combinedOrder;
    }

    // Префиксный оператор ++
    Order& operator++() {
        if (orderCount < MAX_ORDERS) {
            addDish(new Dish("Пустое блюдо", 0.0, 1));
        }
        return *this;
    }

    // Постфиксный оператор ++
    Order operator++(int) {
        Order temp = *this;
        ++(*this);
        return temp;
    }

    // Дружественная функция
    friend void displayOrderDetails(const Order& order);
};

// Инициализация статического поля
int Order::totalOrders = 0;

// Дружественная функция
void displayOrderDetails(const Order& order) {
    printf("Дружественная функция: Клиент: %s, Общая стоимость: %.2f\n",
        order.clientName.c_str(), order.totalPrice);
}

int main() {

    setlocale(LC_ALL, "Russian");

    // Создаём заказы
    Order order1("Иван Иванов");
    Order order2("Петр Петров");

    // Добавляем блюда
    Dish* borsh = new Dish("Борщ", 250.0, 1);
    Dish* pelmeni = new Dish("Пельмени", 300.0, 2);
    order1.addDish(borsh);
    order1.addDish(pelmeni);

    Dish* soup = new Dish("Суп", 150.0, 1);
    order2.addDish(soup);

    // Вывод заказов
    order1.print();
    order2.print();

    // Статическое поле и метод
    printf("Всего заказов: %d\n", Order::getTotalOrders());

    // Возврат через указатель
    float pricePtr;
    order1.getTotalPricePtr(&pricePtr);
    printf("Стоимость заказа (через указатель): %.2f\n", pricePtr);

    // Возврат через ссылку
    float priceRef;
    order1.getTotalPriceRef(priceRef);
    printf("Стоимость заказа (через ссылку): %.2f\n", priceRef);

    // Использование оператора this
    if (order1.isMoreExpensive(order2)) {
        printf("Первый заказ дороже.\n");
    }
    else {
        printf("Второй заказ дороже или равен.\n");
    }

    // Перегрузка оператора +
    Order combinedOrder = order1 + order2;
    combinedOrder.print();

    // Префиксный и постфиксный ++
    ++order1;
    order1.print();
    order1++;
    order1.print();

    // Дружественная функция
    displayOrderDetails(order1);

    // Удаляем блюда
    delete borsh;
    delete pelmeni;
    delete soup;

    return 0;
}
