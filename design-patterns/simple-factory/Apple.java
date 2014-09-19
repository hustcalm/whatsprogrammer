// Apple实现Fruit的函数接口，并且Apple中有私有成员age和私有方法log。
public class Apple extends Fruit {
    private int age;

    public void grow() {
        log("Apple grow()");
    }
    public void harvest() {
        log("Apple harvest()");
    }
    public void plant() {
        log("Apple plant()");
    }
    public void setAge(int age) {
        this.age = age;
    }
    public int getAge() {
        return age;
    }
    private void log(String msg) {
        System.out.println(msg);
    }
}
