public class Client {
    private String name;
    private String phone;

    public Client(String name, String phone) {
        this.name = name;
        this.phone = phone;
    }

    public void print() {
        System.out.printf("Клиент: %s, Телефон: %s%n", name, phone);
    }

    public String getName() {
        return name;
    }
}
