package Day1215;

public class Student {
	   //实体类 五部走   私有属性  无参构造 有参构造 封装方法 重写toString()
		private String name ; 
		private int age ;
		private double score;
		private String classNum;
		public Student() {
			super();
		}
		public Student(String name, int age, double score, String classNum) {
			super();
			this.name = name;
			this.age = age;
			this.score = score;
			this.classNum = classNum;
		}
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public int getAge() {
			return age;
		}
		public void setAge(int age) {
			this.age = age;
		}
		public double getScore() {
			return score;
		}
		public void setScore(double score) {
			this.score = score;
		}
		public String getClassNum() {
			return classNum;
		}
		public void setClassNum(String classNum) {
			this.classNum = classNum;
		}
		@Override
		public String toString() {
			return "Student [姓名=" + name + ", age=" + age + ", score=" + score + ", classNum=" + classNum + "]";
		}
}

