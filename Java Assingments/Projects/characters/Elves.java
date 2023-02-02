package characters;//Pelin Su G�k---202011405---Section1

public class Elves extends Character {

	//characters.Elves distinct properties
	private boolean canUseMagic;								
	private String physicalAppearance;	
	
	//Default constructor
	public Elves() {											
		super();
		canUseMagic = true;
		physicalAppearance = "pointed ears";
	}
	
	//Overloaded constructor
	public Elves(String name, int age, int lifeSpan, String habitat, boolean canUseMagic, String physicalAppearance)
	{
		super(name, age, lifeSpan, habitat);
		this.canUseMagic = canUseMagic;
		this.physicalAppearance = physicalAppearance;
	}

	//Getters and setters for elves properties
	public boolean isCanUseMagic() {
		return canUseMagic;
	}

	public void setCanUseMagic(boolean canUseMagic) {
		this.canUseMagic = canUseMagic;
	}

	public String getPhysicalAppearance() {
		return physicalAppearance;
	}

	public void setPhysicalAppearance(String physicalAppearance) {
		this.physicalAppearance = physicalAppearance;
	}

	//Overrides printInfo
	//I added elves distinct properties
	public void printInfo() {
		super.printInfo();
		System.out.println("Most elves can use magic. This elf " + (canUseMagic ? "can use magic." : "cannot use magic.") + " characters.Elves have " + physicalAppearance + ".");
	}

	//Overrides quotes()	
	public void quote() {
		super.quote();
		System.out.println("Like most elves I " + (canUseMagic ? "can use magic. " : "cannot use magic. ") + "You can identify me by looking at my " + physicalAppearance + ".");
	}
	
	
}

