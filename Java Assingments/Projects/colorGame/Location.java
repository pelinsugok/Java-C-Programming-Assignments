package colorGame;

public class Location {
	
	public Location()
	{
		
	}
	
	public double[] mouseLocation() {
		double[] locations = new double[2];
		locations[0] = StdDraw.mouseX();
		locations[1] = StdDraw.mouseY();
		return locations;
	}
	
	public int whichSquare() {
		if ((this.mouseLocation()[0] >= 0) && (this.mouseLocation()[0] <= 0.5)) {
			if ((this.mouseLocation()[1] >= 0) && (this.mouseLocation()[1] <= 0.5)) {
				return 2;
			} else {
				return 0;
			}
		} else {
			if ((this.mouseLocation()[1] >= 0) && (this.mouseLocation()[1] <= 0.5)) {
				return 3;
			} else {
				return 1;
			}
		}
	}
}
