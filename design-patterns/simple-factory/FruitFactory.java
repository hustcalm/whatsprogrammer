public class FruitFactory {

    public static Fruit newInstance(String name) 
        throws BadFruitException {
        // 如果name等于"apple"(忽略大小写)，则返回苹果。
        if ("apple".equalsIgnoreCase(name)) {
            return new Apple();
        // 如果name等于"grape"(忽略大小写)，则返回葡萄。
        } else if ("grape".equalsIgnoreCase(name)) {
            return new Grape();
        // 如果name等于"strawberry"(忽略大小写)，则返回草莓。
        } else if ("strawberry".equalsIgnoreCase(name)) {
            return new Strawberry();
        // 其它情况，则抛出异常。
        } else {
            throw new BadFruitException("Bad fruit request!");
        }
    }
}
