package hw_4;
import java.util.Scanner;

public class hw1_4 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		for(int i=1;i<n/2;i++) {
			if(n%i==0) {
				System.out.println(i);
			}
		}
	}
}
