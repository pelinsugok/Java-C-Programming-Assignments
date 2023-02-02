package characters;//Pelin Su G�k---202011405---Section1

public class Dragons extends Character {
	
	//characters.Dragons distinct properties
	private int noOfHeads;
	private boolean vegeterian;	
	
	//Default constructor	
	public Dragons() {
		super();
		this.noOfHeads = 2;
		this.vegeterian = false;
	}
	
	//Overloaded constructor	
	public Dragons(String name, int age, int lifeSpan, String habitat, int noOfHeads, boolean vegetarian)
	{
		super(name, age, lifeSpan, habitat);
		this.noOfHeads = noOfHeads;
		this.vegeterian = vegetarian;
	}

	//Getters and setters for dragons properties	
	public int getNoOfHeads() {
		return noOfHeads;
	}

	public void setNoOfHeads(int noOfHeads) {
		this.noOfHeads = noOfHeads;
	}

	public boolean isVegeterian() {
		return vegeterian;
	}

	public void setVegeterian(boolean vegeterian) {
		this.vegeterian = vegeterian;
	}

	//Overrides printInfo
	//I added dragons distinct properties	
	public void printInfo() {
		super.printInfo();
		System.out.println("characters.Dragons usually have more than one head. This dragon has " + noOfHeads + " head(s). Most of the dragons are not vegetarians. This dragon is " + (vegeterian ? "a vegetarian." : "not a vegetarian."));
	}

	//Overrides quotes()	
	public void quote() {
		super.quote();
		System.out.println("I have " + noOfHeads + " head(s). I " + (vegeterian ? "don't eat meat, I eat plants. I'm a vegetarian unlike most of us." : "eat meat, I'm not a vegetarian like most of us."));
	}
	
	
	
	
}
