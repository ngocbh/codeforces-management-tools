import java.util.Scanner;

public class EasySeq {
	int N, K;
	int a[] = new int[10000];
	int Q;
	void input() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
	}
	
	void solve() {
		Q = 0;
		int sum;
		for (int i = 0; i < N; i++) {
			sum = 0;
			for (int j = i; j < N; j++) {
				sum += a[j];
				if (sum % K == 0) {
					Q++;
				}
			}
		}
		System.out.println(Q);
	}
	
	public static void main(String[] args) {
		EasySeq ae = new EasySeq();
		ae.input();
		ae.solve();
	}
}
