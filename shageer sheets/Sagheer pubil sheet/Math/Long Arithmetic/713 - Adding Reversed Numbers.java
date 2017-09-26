import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Throwable {
		StringBuffer sb;
		int n;
		BigInteger x, y, ans;
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		n = sc.nextInt();
		while (n-- > 0) {
			sb = new StringBuffer(sc.next());
			x = new BigInteger(sb.reverse().toString());
			sb = new StringBuffer(sc.next());
			y = new BigInteger(sb.reverse().toString());
			ans = x.add(y);
			sb = new StringBuffer(ans.toString()).reverse();
			ans = new BigInteger(sb.toString());
			System.out.println(ans);
		}
	}
}