import java.util.Scanner;
import java.math.BigInteger;

class BigInt {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		BigInteger fact = BigInteger.ONE;
		for (int i = 1; i <= n; i++) {
			fact = fact.multiply(BigInteger.valueOf(i));
		}
		System.out.print(fact);
		System.out.println();
	}
}