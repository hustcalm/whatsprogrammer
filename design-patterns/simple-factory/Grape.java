// Grape仅仅只实现Fruit的函数接口。
public class Grape extends Fruit {
    public void grow() {
        System.out.println("Grape grow()");
    }
    public void harvest() {
        System.out.println("Grape harvest()");
    }
    public void plant() {
        System.out.println("Grape plant()");
    }
}
