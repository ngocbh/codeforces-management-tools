import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int N, K, count = 0;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		for (int i = 0; i < N; i++) {
			int sum = arr[i];
			if (sum % K == 0) {
				count += 1;
			}
			for (int j = i + 1; j < N; j++) {
				sum += arr[j];
				if (sum % K == 0) {
					count += 1;
				}
			}
		}
		System.out.println(count);
	}
}
