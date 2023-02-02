package labwork2;

import java.awt.Color;
import java.util.Random;

public class ColorBusiness {

	public ColorBusiness() {

	}
	
	Color[] colorList = new Color[] { Color.PINK, Color.BLUE, Color.GREEN, Color.RED, Color.ORANGE , Color.BLACK, Color.CYAN, Color.DARK_GRAY};

	public Color randomColor() {
		Random rand = new Random();
		int randomColorIndex = rand.nextInt(colorList.length); 
		return this.colorList[randomColorIndex]; 		
	}

	
	public void changeColor(Color[] color) {
		Location location = new Location();
		color[location.whichSquare()] = this.randomColor();
		StdDraw.setPenColor(color[location.whichSquare()]);
		if (location.whichSquare() == 0) {
			StdDraw.filledSquare(0, 1, StaticVariables.halfLength);
		} else if (location.whichSquare() == 1) {
			StdDraw.filledSquare(1, 1, StaticVariables.halfLength);
		} else if (location.whichSquare() == 2) {
			StdDraw.filledSquare(0, 0, StaticVariables.halfLength);
		} else {
			StdDraw.filledSquare(1, 0, StaticVariables.halfLength);
		}
		StdDraw.show();
	}

}
