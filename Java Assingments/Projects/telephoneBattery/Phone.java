package telephoneBattery;

public class Phone {
    private Battery battery;

    public Phone() {
        this.battery = new Battery();
    }

    public Phone(Phone phone) {
        this.battery = phone.battery;
        
    }

    public Battery getBattery() {
        return battery;
    }

    public void use(int level) {
        this.battery.setLevel(this.battery.getLevel() - level);
    }
}