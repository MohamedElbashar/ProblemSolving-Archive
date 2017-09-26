import java.math.BigInteger;
import static java.math.BigInteger.*;
import java.util.Scanner;

public class Main {
	/*
	 * +2 +4 +6 +8 Sequence : 2 -> 4 -> 8 -> 14 -> 22 -> .... n : 1 2 3 4 5
	 * 
	 * Summation 2(x-1) = x^2 - x x = n-1
	 * 
	 * Hence = (n-1)^2 - (n-1) + 2(first term)
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger x;
		while (sc.hasNext()) {
			x = sc.nextBigInteger();
			if (!x.equals(BigInteger.ZERO)) {
				BigInteger n = x.subtract(BigInteger.ONE);

				System.out.println(n.pow(2).add(n).add(BigInteger.valueOf(2)));
			} else {
				System.out.println(1);
			}
		}
	}

}