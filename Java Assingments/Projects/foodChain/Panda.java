package foodChain;

public class Panda extends Animal implements InFoodChain {
	
	private boolean endangered;
	
	public Panda()
	{
		super();
		endangered = true;
	}
	
	public Panda(boolean vegetarian, String eats, int noOfLegs, String color, boolean endangered)
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
		System.out.println("I make panda sounds.");
	}

	void printInfo() {
		System.out.println("I am " + (endangered ? "endangered." : "not endangered."));		
	}
	
	public String dietType() {
		String dietType = "Pandas are herbivores.";
		return dietType;
	}
	
	public void huntsDown() {
		System.out.println("Pandas hunts down bamboo.");
	}
	
	public void huntedBy() {
		System.out.println("Pandas are hunted by snow leopards.");
	}
	
	public String climate() {
		String climate = "Cool places.";
		return climate;
	}
	
	public String habitat() {
		String habitat = "Forest.";
		return habitat;
	}
	
	public int lifeExpectancy() {
		return 20;
	}

}
