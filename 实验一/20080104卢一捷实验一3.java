package hw1_3;

public class hw1_3 {
	public static void main(String[] args) {
		int sum = 0;
		for(int i=3;i<=100;i+=3)
		{
			if(i%5!=0) {
				sum+=i;
			}
		}
		
		System.out.print(sum);
	}
}
