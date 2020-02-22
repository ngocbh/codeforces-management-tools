import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int d, n, x, y, c;
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		n = sc.nextInt();
		ArrayList<Integer> mouseHouse = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			x = sc.nextInt();
			y = sc.nextInt();
			c = sc.nextInt();
			mouseHouse.add(x);
			mouseHouse.add(y);
			mouseHouse.add(c);
		}
		for (int i = 0; i < mouseHouse.size(); i++) {
			System.out.println((mouseHouse.get(i) + mouseHouse.get(i + 3))/2);
			System.out.println((mouseHouse.get(i+1) + mouseHouse.get(i + 4))/2);
			System.out.println((mouseHouse.get(i+2) + mouseHouse.get(i + 5)));
			return;
		}
	}
}
