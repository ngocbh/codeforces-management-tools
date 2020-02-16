import java.util.Scanner;

public class ChuSo {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long S = sc.nextLong();
        sc.close();

        long so = 1;
        String chuSo = String.valueOf(so);
        char ch = '0';
        long count = 0;
        while (count < S) {
            for (int i = 0; i < chuSo.length(); i++) {
                if (chuSo.charAt(i) != ch) {
                    count++;
                    ch = chuSo.charAt(i);
                }
            }
            so++;
            chuSo = String.valueOf(so);
        }

        System.out.println(so-1);
    }
}
