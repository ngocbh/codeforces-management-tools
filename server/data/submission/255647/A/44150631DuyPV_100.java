import java.util.Scanner;

public class XauLap {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String a = "";
        a += str.charAt(0);

        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) != a.charAt(a.length()-1))
                a += str.charAt(i);
        }

        System.out.println(a);

        sc.close();
    }
}
