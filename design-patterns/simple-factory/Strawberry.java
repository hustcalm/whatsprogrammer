// Strawberry实现Fruit的函数接口，并且Strawberry中有私有方法log
public class Strawberry extends Fruit {

    public void grow() {
        log("Strawberry grow()");
    }
    public void harvest() {
        log("Strawberry harvest()");
    }
    public void plant() {
        log("Strawberry plant()");
    }
    private void log(String msg) {
        System.out.println(msg);
    }
}
