package foodChain;

//Pelin Su G�k
//202011405
//Section-1

public class Koala extends Animal implements InFoodChain {
	
	private boolean endangered;
	
	public Koala() {
		super();
		endangered = true;
	}
	
	public Koala(boolean vegetarian, String eats, int noOfLegs, String color, boolean endangered)
	{
		super(vegetarian, eats, noOfLegs, color);
		this.endangered = endangered;
	}
	
	public boolean isEndangered() {
		return endangered;
	}

	public void setEndangered(boolean endangered) {
		this.endangered = endangered;
	}
	
	void makeSound() {
		System.out.println("I make squeak noises.");
	}
	
	void printInfo() {
		System.out.println("I am a koala.");
		System.out.println("I am " + (vegetarian ? "a vegetarian. " : "not a vegetarian. "));
		System.out.println("I eat " + eats + ".");
		System.out.println("I have " + noOfLegs + " legs.");
		System.out.println("My color is " + color + ".");
		System.out.println("I am " + (endangered ? "endangered." : "not endangered"));
		
		System.out.println(this.dietType());
		this.huntsDown();
		this.huntedBy();
		System.out.println(this.climate());
		System.out.println(this.habitat());
		int lifeSpan = this.lifeExpectancy();
		System.out.println("Koalas live " + lifeSpan + " years on average.");
	}
	
	public String dietType() {
		String dietType = "Koalas are herbivorous.";
		return dietType;
	}
	
	public void huntsDown() {
		System.out.println("Koalas hunts down leafs.");
	}
	
	public void huntedBy() {
		System.out.println("Koalas are hunted by eagles.");
	}
	
	public String climate() {
		String climate = "Koalas lives in hot places.";
		return climate;
	}
	
	public String habitat() {
		String habitat = "Koalas lives in forest.";
		return habitat;
	}
	
	public int lifeExpectancy() {
		return 15;
	}

}
