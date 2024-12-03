import java.util.ArrayList;
import java.util.List;

public class Menu {
    private List<Dish> dishes;

    public Menu() {
        dishes = new ArrayList<>();
    }

    public void addDish(Dish dish) {
        if (dishes.size() < 10) {
            dishes.add(dish);
        } else {
            System.out.println("Меню переполнено!");
        }
    }

    public void print() {
        System.out.println("Меню:");
        for (Dish dish : dishes) {
            dish.print();
        }
        System.out.println();
    }

    public Dish getDish(int index) {
        if (index >= 0 && index < dishes.size()) {
            return dishes.get(index);
        }
        return null;
    }
}
