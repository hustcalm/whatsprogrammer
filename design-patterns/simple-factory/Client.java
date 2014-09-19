public class Client {

    public static void main(String[] args) {
        try {
            Fruit apple = FruitFactory.newInstance("Apple");
            apple.plant();
            apple.grow();
            apple.harvest();

            Fruit grape = FruitFactory.newInstance("Grape");
            grape.plant();
            grape.grow();
            grape.harvest();

            Fruit strawberry = FruitFactory.newInstance("strawberry");
            strawberry.plant();
            strawberry.grow();
            strawberry.harvest();

            Fruit error = FruitFactory.newInstance("error");
            error.plant();
            error.grow();
            error.harvest();
        } catch (BadFruitException e) {
            e.printStackTrace();
        }
    }
}
