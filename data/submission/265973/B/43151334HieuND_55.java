<<<<<<< Updated upstream
import java.util.Scanner;

public class Rat {
	int d, n;
	int map[][] = new int[101][101];
	
	int rs;
	int x0, y0;
	void input() {
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			int x, y, c;
			x = sc.nextInt();
			y = sc.nextInt();
			c = sc.nextInt();
			map[x][y] = c;
		}
		sc.close();
	}
	
	int boom(int x, int y) {
		int num = 0;
		for (int i = x - d; i <= x + d; i++) {
			if (x - d < 0 || x + d > 100) continue;
			for (int j = y - d; j <= y + d; j++) {
				if (y - d < 0 || y + d > 100) continue;
				num += map[i][j];				
			}
		}
		return num;
	}
	void solve() {
		rs = 0;
		x0 = -1;
		y0 = -1;
		
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				int count = boom(i, j);
				if (rs < count) {
					rs = count;
					x0 = i;
					y0 = j;
				}
			}
		}
		System.out.println(x0 + " " +y0+ " " +rs);
	}
	
	public static void main(String[] args) {
		Rat ra = new Rat();
		ra.input();
		ra.solve();
	}
}
=======
import java.util.Scanner;

public class Rat {
	int d, n;
	int map[][] = new int[101][101];
	
	int rs;
	int x0, y0;
	void input() {
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			int x, y, c;
			x = sc.nextInt();
			y = sc.nextInt();
			c = sc.nextInt();
			map[x][y] = c;
		}
		sc.close();
	}
	
	int boom(int x, int y) {
		int num = 0;
		for (int i = x - d; i <= x + d; i++) {
			if (x - d < 0 || x + d > 100) continue;
			for (int j = y - d; j <= y + d; j++) {
				if (y - d < 0 || y + d > 100) continue;
				num += map[i][j];				
			}
		}
		return num;
	}
	void solve() {
		rs = 0;
		x0 = -1;
		y0 = -1;
		
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				int count = boom(i, j);
				if (rs < count) {
					rs = count;
					x0 = i;
					y0 = j;
				}
			}
		}
		System.out.println(x0 + " " +y0+ " " +rs);
	}
	
	public static void main(String[] args) {
		Rat ra = new Rat();
		ra.input();
		ra.solve();
	}
}
>>>>>>> Stashed changes
