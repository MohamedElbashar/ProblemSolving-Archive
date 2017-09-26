import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		while (n-- > 0) {
			BigInteger p = sc.nextBigInteger();
			String ch = sc.next();
			BigInteger q = sc.nextBigInteger();
			BigInteger GCD_pq = p.gcd(q);
			pw.println(p.divide(GCD_pq) + " / " + q.divide(GCD_pq));

		}
		pw.close();

	}
}