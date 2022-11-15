package hw1_5;
import java.util.Scanner;

public class hw_5 {
	public static void func(int n) {
		int sum = 0;
		for(int i=1;i<=n;i++)
		{
			sum+=i;
		}
		System.out.println(sum);
	}
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		func(n);
	}
}
