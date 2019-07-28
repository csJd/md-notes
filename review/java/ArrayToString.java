import java.util.Arrays;

public class ArrayToString {
    public static void main (String[] args) {
        int[] intArray = {1, 2, 3, 4, 5};
        System.out.println(intArray);
        System.out.println(Arrays.toString(intArray));
        /*output
        [I@2a139a55
        [1, 2, 3, 4, 5]
        */

        double[] doubleArray = {1, 2, 3, 4, 5};
        System.out.println(doubleArray);
        System.out.println(Arrays.toString(doubleArray));
        /*output
        [D@15db9742
        [1.0, 2.0, 3.0, 4.0, 5.0]
        */
    }
}
