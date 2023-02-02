package characters;//Pelin Su G�k---202011405---Section1

public class Character {
	
	//Properties of characters.Character class
	protected String name;													
	protected int age;
	protected int lifeSpan;
	protected String habitat;
	
	//Default constructor
	public Character() {													
		name = "characters.Character";
		age = 86;
		lifeSpan = 180;
		habitat = "swamps";
	}
	
	//Overloaded constructor
	public Character(String name, int age, int lifeSpan, String habitat)	
	{
		this.name = name;
		this.age = age;
		this.lifeSpan = lifeSpan;
		this.habitat = habitat;
	}

	//Getters and setters for properties of character class
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public int getLifeSpan() {
		return lifeSpan;
	}

	public void setLifeSpan(int lifeSpan) {
		this.lifeSpan = lifeSpan;
	}

	public String getHabitat() {
		return habitat;
	}

	public void setHabitat(String habitat) {
		this.habitat = habitat;
	}
	
	//Prints out the characters name, age, life span and habitat.
	public void printInfo() {
		System.out.println("This character is a/an " + name + " its current age is " + age + ". " + name + "s have a lifespan of " + lifeSpan + " years. They usually live in " + habitat + ".");
	}
	
	public void quote()
	{
		System.out.println("I am a magical/fictional creature.");
	}
	
	public static void main(String[] args) {

		Dragons dragons = new Dragons("Dragon", 150, 220, "warm areas", 3, true);
		dragons.printInfo();
		dragons.quote();
		
		System.out.println(" ");
		Elves elves = new Elves("Elf", 235, 300, "forest", true, "pointed ears");
		elves.printInfo();
		elves.quote();
		
		System.out.println(" ");
		Vampires vampires = new Vampires("Vampire", 965, 4000, "forest", true, "sun");
		vampires.printInfo();
		vampires.quote();
	}
}
