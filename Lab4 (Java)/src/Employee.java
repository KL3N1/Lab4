public class Employee {
    private String name;
    private int id;

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public void print() {
        System.out.printf("Официант: %s, ID: %d%n", name, id);
    }

    public String getName() {
        return name;
    }
}
