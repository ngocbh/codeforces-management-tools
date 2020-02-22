<<<<<<< Updated upstream
import java.util.Scanner;

public class incpair {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		int [] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		
		System.out.print(Seq(arr, k));

	}
	
	private static int Seq(int arr[], int k) {
		int q = 0;
		int sum = 0;
		
		for (int i = 0; i < arr.length; i++) {
			for(int j=i; j<arr.length; j++) {
				sum += arr[j];
				if(sum % k == 0) {
					q++;
				}
			}
			sum = 0;
			
		}
		return q;
    }

}
=======
import java.util.Scanner;

public class incpair {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		int [] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		
		System.out.print(Seq(arr, k));

	}
	
	private static int Seq(int arr[], int k) {
		int q = 0;
		int sum = 0;
		
		for (int i = 0; i < arr.length; i++) {
			for(int j=i; j<arr.length; j++) {
				sum += arr[j];
				if(sum % k == 0) {
					q++;
				}
			}
			sum = 0;
			
		}
		return q;
    }

}
>>>>>>> Stashed changes
