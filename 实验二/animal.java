package animal1;

public class animal {
protected String name = "/0";
protected int legs = 0;

public animal(){

}
public animal(String name,int legs){
	this.name = name;
	this.legs = legs;
}
public void MakeSound() {
	System.out.println("¶¯Îï½Ð");
}
public void PrintName() {
	System.out.println(this.name);
}
public void PrintLegs() {
	System.out.println(this.legs);
}
}

