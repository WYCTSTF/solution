class Animal {
	int _age;
	char _sex;
	Animal(int age, char sex) { _age = age; _sex = sex; }
	void wish() { System.out.println("wish"); }
	void speech() { System.out.println("Speech"); }
}
class Cat extends Animal {
	Cat(int age, char sex) { super(age, sex); }
	void wish() { System.out.println("Cat can wish"); }
}
class Mouse extends Animal {
	Mouse(int age, char sex) { super(age, sex); }
	void wish() { System.out.println("Mouse can wish"); }
}
public class GG {
	public static void main(String[] args) {
		Cat a = new Cat(12, 'q');
		Mouse b = new Mouse(13, 'g');
		a.wish();
		b.wish();
	}
}