package characters;//Pelin Su G�k---202011405---Section1

public class Vampires extends Character {

	//characters.Vampires distinct properties
	private boolean fast;
	private String weakness;	
	
	//Default constructor	
	public Vampires() {
		super();
		this.fast = true;
		this.weakness = "garlic and sun";
	}

	//Overloaded constructor	
	public Vampires(String name, int age, int lifeSpan, String habitat, boolean fast, String weakness)
	{
		super(name, age, lifeSpan, habitat);
		this.fast = fast;
		this.weakness = weakness;
	}

	//Getters and setters for vampires properties	
	public boolean isFast() {
		return fast;
	}

	public void setFast(boolean fast) {
		this.fast = fast;
	}

	public String getWeakness() {
		return weakness;
	}

	public void setWeakness(String weakness) {
		this.weakness = weakness;
	}

	//Overrides printInfo()
	//I added vampires distinct properties	
	public void printInfo() {
		super.printInfo();
		System.out.println("All the vampires are fast but some vampires are faster than others. This vampire is " + (fast ? "faster than other vampires." : "not faster than other vampires.") + " Their weakness is " + weakness + ".");
	}

	//Overrides quotes()
	public void quote() {
		super.quote();
		System.out.println("Like all vampires my biggest weakness is " + weakness + ". I am " + (fast ? "faster than other vampires." : "not faster than other vampires, I'm slower than them."));
	}
		
	}
