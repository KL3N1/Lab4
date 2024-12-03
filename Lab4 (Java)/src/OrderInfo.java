public class OrderInfo {
    private String clientName;
    private float totalPrice;

    public OrderInfo(String clientName, float totalPrice) {
        this.clientName = clientName;
        this.totalPrice = totalPrice;
    }

    public void printInfo() {
        System.out.printf("Клиент: %s, Общая стоимость заказа: %.2f%n", clientName, totalPrice);
    }
}
