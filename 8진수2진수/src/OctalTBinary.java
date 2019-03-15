import java.util.Scanner;

/**
 * 이 방식이 아니라, String으로 풀어야 해결됨. 길이 제한 때문에
 * */

public class OctalTBinary {
	final static int MIN_LEN = 100;
	int min_len = MIN_LEN;
	int octal;
	int binary;
	int buf;

	OctalTBinary(int octal) {
		this.octal = octal;
	}

	int change() {
		while (octal > 0) {
			buf = octal % 10;
			octal /= 10;
			binary = binary + min_len * (buf / 4) + (buf % 4 / 2) * min_len / 10 + (buf % 4 % 2) * min_len / 100;
			min_len *= 1000;
		}
		return binary;
	}

	public static void main(String[] args) {
		while (true) {
			Scanner sc = new Scanner(System.in);
			int num = sc.nextInt();
			OctalTBinary otb = new OctalTBinary(num);
			System.out.println(otb.change());
		}
	}
}
