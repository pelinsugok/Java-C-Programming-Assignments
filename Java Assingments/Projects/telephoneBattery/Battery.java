package telephoneBattery;

public class Battery {
    private int level;

    public Battery() {
        this.level = 100;
    }

    public Battery(Battery battery) {
        this.level = battery.level;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        if (level >= 0 && level <= 100) {
            this.level = level;
        }else{
            this.level = 0;
        	//System.out.println("Level must be 100 at most, and 0 at least.");
        }
    }
}
