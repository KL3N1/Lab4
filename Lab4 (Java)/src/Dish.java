public class Dish {
    private String name;
    private float price;
    private int quantity;

    public Dish(String name, float price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public void print() {
        System.out.printf("Блюдо: %s, Цена: %.2f, Количество: %d%n", name, price, quantity);
    }

    public float getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public String getName() {
        return name;
    }
}
