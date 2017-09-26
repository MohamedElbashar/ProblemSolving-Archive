import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int c = sc.nextInt();
		BigInteger x, y, n;
		while (c-- > 0) {
			x = BigInteger.valueOf(sc.nextInt());
			y = BigInteger.valueOf(sc.nextInt());
			n = BigInteger.valueOf(sc.nextInt());
			pw.println(x.modPow(y, n));
		}
		pw.close();
	}
}