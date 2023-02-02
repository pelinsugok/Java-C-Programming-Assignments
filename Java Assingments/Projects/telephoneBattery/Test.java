package telephoneBattery;

//Do not define package
///////////////////////////
//DO NOT modify Test class
//or your question will not be evaluated!
public class Test {
	public static void main(String[] args) {
		Phone p = new Phone();
		System.out.println(p.getBattery().getLevel());
		p.use(15);
		System.out.println(p.getBattery().getLevel());
		p.use(30);
		System.out.println(p.getBattery().getLevel());
		Phone p2 = new Phone(p);
		p.use(40);
		System.out.println(p.getBattery().getLevel());
		p.use(20);
		System.out.println(p.getBattery().getLevel());
		p2.use(10);
		System.out.println(p2.getBattery().getLevel());
		p2.use(60);
		System.out.println(p2.getBattery().getLevel());
	}
}
///////////////////////////
