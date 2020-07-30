import java.math.BigInteger;
import java.util.Scanner;

/**
 * _112
 */
public class _112 {
    public static void main(String[] args) {
        try(Scanner scanner = new Scanner(System.in)){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            BigInteger left = BigInteger.valueOf(a).pow(b);
            BigInteger right = BigInteger.valueOf(b).pow(a);
            System.out.println(left.subtract(right));
        }
    }
}