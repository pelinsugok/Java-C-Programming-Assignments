package foodChain;

public class Penguin extends Bird implements InFoodChain{

	private String type;
	
	public Penguin()
	{
		vegetarian = false;
		eats = "fish";
		noOfLegs = 2;
		color = "blue & white";
		endangered = true;
		species = "penguin";
		type = "little blue";
		
	}
	
	public Penguin(boolean vegetarian, String eats, int noOfLegs, String color, boolean endangered, String species, String type)
	{
		this.vegetarian = vegetarian;
		this.eats = eats;
		this.noOfLegs = noOfLegs;
		this.color = color;
		this.endangered = endangered;
		this.species = species;
		this.type = type;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	void makeSound() {
		System.out.println("I make gak gak sounds.");
	}

	void printInfo() {
		super.printInfo();
		System.out.println("My type is " + type + ".");
	}
	
	
}
