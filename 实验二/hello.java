package animal1;

public class hello {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		animal zoo[] = new animal[3];
		zoo[0] = new cat("cat_A");
		zoo[1] = new duck("duck_B");
		zoo[2] = new dolphin("dolphin_C");
		
		for(int i=0;i<3;i++) {
			zoo[i].PrintName();
			zoo[i].MakeSound();
			zoo[i].PrintLegs();
			System.out.println("\n");
		}
	}

}
