import java.util.ArrayList;
import java.util.List;

public class Order {
    private static int totalOrders = 0; // Статическое поле
    private Client client;
    private Employee employee;
    private List<Dish> orderedDishes;
    private float totalPrice;

    public Order(Client client, Employee employee) {
        this.client = client;
        this.employee = employee;
        this.orderedDishes = new ArrayList<>();
        this.totalPrice = 0.0f;
        totalOrders++; // Увеличиваем общее число заказов
    }

    public static int getTotalOrders() { // Статический метод
        return totalOrders;
    }

    public void addDish(Dish dish) {
        if (orderedDishes.size() < 5) {
            orderedDishes.add(dish);
            totalPrice += dish.getPrice() * dish.getQuantity();
        } else {
            System.out.println("Заказ переполнен!");
        }
    }

    public void print() {
        System.out.printf("Заказ клиента: %s%n", client.getName());
        System.out.printf("Обслуживает официант: %s%n", employee.getName());
        System.out.println("Блюда в заказе:");
        for (Dish dish : orderedDishes) {
            dish.print();
        }
        System.out.printf("Общая стоимость заказа: %.2f%n%n", totalPrice);
    }

    public OrderInfo getOrderInfo() { // Возврат через вспомогательный класс
        return new OrderInfo(client.getName(), totalPrice);
    }

    public boolean isMoreExpensive(Order other) { // Использование this
        return this.totalPrice > other.totalPrice;
    }
}
