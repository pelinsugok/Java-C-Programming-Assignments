package foodChain;

//Pelin Su G�k
//202011405
//Section-1

public abstract class Animal {
	
	protected boolean vegetarian;
	protected String eats;
	protected int noOfLegs;
	protected String color;
	
	public Animal()
	{
		vegetarian = true;
		eats = "plants";
		noOfLegs = 4;
		color = "black";
	}
	
	public Animal(boolean vegetarian, String eats, int noOfLegs, String color)
	{
		this.vegetarian = vegetarian;
		this.eats = eats;
		this.noOfLegs = noOfLegs;
		this.color = color;
	}
	
	public boolean isVegetarian() {
		return vegetarian;
	}

	public void setVegetarian(boolean vegetarian) {
		this.vegetarian = vegetarian;
	}

	public String getEats() {
		return eats;
	}

	public void setEats(String eats) {
		this.eats = eats;
	}

	public int getNoOfLegs() {
		return noOfLegs;
	}

	public void setNoOfLegs(int noOfLegs) {
		this.noOfLegs = noOfLegs;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	abstract void printInfo();
	
	abstract void makeSound();
	
	public static void main(String[] args) {

		Koala koala = new Koala(true, "plants", 4, "brown", true);
		koala.printInfo();
		koala.makeSound();
	}

}
