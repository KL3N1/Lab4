public class Main {
    public static void main(String[] args) {
        Menu menu = new Menu();
        menu.addDish(new Dish("Борщ", 250.0f, 1));
        menu.addDish(new Dish("Пельмени", 300.0f, 1));
        menu.print();

        Client client = new Client("Иван Иванов", "89005555555");
        Employee employee = new Employee("Сергей Петров", 101);

        Order order1 = new Order(client, employee);
        order1.addDish(menu.getDish(0));
        order1.addDish(menu.getDish(1));
        order1.print();

        Order order2 = new Order(client, employee);
        order2.addDish(menu.getDish(0));

        Order[] orders = {order1, order2}; // Массив объектов
        for (Order order : orders) {
            order.print();
        }

        System.out.printf("Всего заказов: %d%n", Order.getTotalOrders());

        OrderInfo info = order1.getOrderInfo();
        info.printInfo();

        if (order1.isMoreExpensive(order2)) {
            System.out.println("Первый заказ дороже.");
        } else {
            System.out.println("Второй заказ дороже или равен.");
        }
    }
}
