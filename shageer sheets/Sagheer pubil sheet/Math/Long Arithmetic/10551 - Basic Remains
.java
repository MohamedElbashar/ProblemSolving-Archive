import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while (true) {
			int b = sc.nextInt();
			if (b == 0)
				break;
			BigInteger p = new BigInteger(sc.next(), b);
			BigInteger m = new BigInteger(sc.next(), b);
			pw.println((p.mod(m)).toString(b));
		}
		pw.close();
	}
}