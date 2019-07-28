import java.util.Arrays;

public class Lambda {
    public static void main(String[] args) {
        String[] sArray = {"one", "two", "three", "four"};

        //sort(T[] a, Comparater<T> c);
        Arrays.sort(sArray, (first, second) -> first.length() - second.length());
        System.out.println(Arrays.toString(sArray));

        /*output
        [one, two, four, three]
        */
    }
}
