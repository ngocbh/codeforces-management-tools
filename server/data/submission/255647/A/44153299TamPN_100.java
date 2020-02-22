import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Xaulap {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String input = new String();
		String output = "";
		input = in.readLine();
		for (int i = 0; i < input.length()-1; i++) {
			if (input.charAt(i)!= input.charAt(i+1)) {
				output+=input.charAt(i);
			}
		}
		output+=input.charAt(input.length()-1);
		System.out.println(output);
	}
}