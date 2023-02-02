package foodChain;

public class Bird extends Animal implements InFoodChain{
	
	protected boolean endangered;
	protected String species;
	
	public Bird()
	{
		super();
		endangered = false;
		species = "canary";
	}
	
	public Bird(boolean vegetarian, String eats, int noOfLegs, String color, boolean endangered, String species)
	{
		super(vegetarian, eats, noOfLegs, color);
		this.endangered = endangered;
		this.species = species;
	}

	public boolean isEndangered() {
		return endangered;
	}

	public void setEndangered(boolean endangered) {
		this.endangered = endangered;
	}

	public String getSpecies() {
		return species;
	}

	public void setSpecies(String species) {
		this.species = species;
	}

	void makeSound() {
		System.out.println("I make chirp chirp sounds.");
	}

	void printInfo() {
		System.out.println("I am " + (endangered ? "endangered." : "not endangered."));
		System.out.println("My species is " + species + ".");
	}

	public String dietType() {
		String dietType = "Birds are herbivores.";
		return dietType;
	}

	public void huntsDown() {	
		System.out.println("Birds hunts down insects");
	}

	public void huntedBy() {
		System.out.println("Birds are hunted by cats, or other birds");
		
	}

	public String climate() {
		String climate = "Cool places.";
		return climate;
	}

	public String habitat() {
		String habitat = "Deserts and mountains.";
		return habitat;
	}

	public int lifeExpectancy() {
		return 30;
	}
	
	

}
