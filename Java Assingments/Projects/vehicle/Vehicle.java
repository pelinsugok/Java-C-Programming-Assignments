package vehicle;

public abstract class Vehicle {
    abstract int getWeight();

    abstract String getType();

    static int getTotalWeight(Vehicle[] array) {
        int totalWeigh = 0;
        for (Vehicle vehicle : array) {
            totalWeigh += vehicle.getWeight();
        }
        return totalWeigh;
    }
}