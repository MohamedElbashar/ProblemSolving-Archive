import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while (sc.hasNext()) {
			int N = sc.nextInt();
			BigInteger BN = BigInteger.valueOf(N);
			int RN = Integer.parseInt(new StringBuffer(BN.toString()).reverse()
					.toString());
			BigInteger BRN = BigInteger.valueOf(RN);
			if (!BN.isProbablePrime(10)) {
				System.out.println(N + " is not prime.");
			} else if (N != RN && BRN.isProbablePrime(10)) {
				System.out.println(N + " is emirp.");
			} else {
				System.out.println(N + " is prime.");
			}
		}
		pw.close();

	}
}