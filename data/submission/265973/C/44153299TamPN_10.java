<<<<<<< Updated upstream
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int n, Q;
		int temp = (int) (Math.pow(10, 9) + 7);
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = (int) Integer.parseInt(in.readLine());
		if (n == 1) {
			Q = 1;
		} else if (n == 2) {
			Q = 4;
		} else if (n > 2) {
			Q = 4 + (n - 2) * 3;
		} else {
			Q = 0;
		}
		System.out.println(Q % temp);
	}
=======
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int n, Q;
		int temp = (int) (Math.pow(10, 9) + 7);
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = (int) Integer.parseInt(in.readLine());
		if (n == 1) {
			Q = 1;
		} else if (n == 2) {
			Q = 4;
		} else if (n > 2) {
			Q = 4 + (n - 2) * 3;
		} else {
			Q = 0;
		}
		System.out.println(Q % temp);
	}
>>>>>>> Stashed changes
}