package hw1_6;
import java.util.Scanner;

public class hw6 {
	public static void func(int n) {
		int sum = 1;
		for(int i=1;i<=n;i++)
		{
			sum*=i;
		}
		System.out.println(sum);
	}
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		func(n);
	}
}
