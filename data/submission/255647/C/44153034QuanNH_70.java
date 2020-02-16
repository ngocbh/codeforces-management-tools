import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	public static int fee(int a, int b) {
		return (int) Math.pow((double) (a - b), 2);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int feeTotal = 0;
		int n = Integer.parseInt(in.readLine());
		ArrayList<Integer> thos = new ArrayList<Integer>();
		ArrayList<Integer> khachs = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(in.readLine());
			thos.add(temp);
		}
		Collections.sort(thos);
		for (int i = 0; i < n; i++) {
			int temp2 = Integer.parseInt(in.readLine());
			khachs.add(temp2);
		}
		Collections.sort(khachs);
		for (int i = 0; i < n; i++) {
			feeTotal+= fee(thos.get(i), khachs.get(i));
		}
		System.out.println(feeTotal);
	}
}