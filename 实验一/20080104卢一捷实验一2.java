package hw1_2;
import java.util.Scanner;

public class hw1_2 {
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		if(n>0||n<0)
		{
			for(int i=(n>0?n:-n)-1;i>0;i--)
			{
				n*=i;
			}
			System.out.print(n);
			if(n<0)
			{
				n*=Math.pow(1, n);
			}
		}
		else
		{
			System.out.print("illegal");
		}
	}
}