package vehicle;

//Do not define package
///////////////////////////
//DO NOT modify Test class
//or your question will not be evaluated!
public class Test {
	public static void main(String[] args) {
		Vehicle[] arr = new Vehicle[5];
		arr[0] = new Car();
		arr[1] = new Truck();
		arr[2] = new Truck();
		arr[3] = new Car();
		arr[4] = new Truck();
		System.out.println(arr[0].getType());
		System.out.println(arr[0].getWeight());
		System.out.println(arr[1].getType());
		System.out.println(arr[1].getWeight());
		System.out.println(Vehicle.getTotalWeight(arr));
	}
}
///////////////////////////
