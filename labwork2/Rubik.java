package labwork2;

public class Rubik {
	Draw draw = new Draw();
	// Color[] colors = new Color[5];
	//Color[] currentColors = new Color[4];
	ColorBusiness business = new ColorBusiness();

	public Rubik() {
//		StdDraw.setCanvasSize(500, 500);
		// this.colors = new Color[] { Color.PINK, Color.BLUE, Color.GREEN, Color.RED,
		// Color.ORANGE };

		// Pick random 4 colors with the method you have written
//		for (int i = 0; i < this.currentColors.length; i++) {
//			currentColors[i] = this.business.randomColor();
//		}
		// Change the currentColors array accordingly with these colors
		// Set the colors for filling the squares and call the filledSquare method
		// 0. location
		
		
		this.draw.drawSquare();
		
//		StdDraw.setPenColor(currentColors[0]);
//		StdDraw.filledSquare(0, 1, this.business.halfLength);
//		// 1.location
//		StdDraw.setPenColor(currentColors[1]);
//		StdDraw.filledSquare(1, 1, this.business.halfLength);
//		// 2.location
//		StdDraw.setPenColor(currentColors[2]);
//		StdDraw.filledSquare(0, 0, this.business.halfLength);
//		// 3.location
//		StdDraw.setPenColor(currentColors[3]);
//		StdDraw.filledSquare(1, 0, this.business.halfLength);
	}
	

	// Main method should exactly be this
	public static void main(String[] args) {
		Rubik r = new Rubik();
		r.play();
	}

	// Randomly chooses and returns a Color from your colors[] array
//	public Color randomColor() {
//		Random rand = new Random();
//		int randomColorIndex = rand.nextInt(colors.length); // I generated a random number maximum value of colors
//															// arrays length
//		return colors[randomColorIndex]; // I assigned random number to index of colors array and returned a random
//											// number from array
//	}

	// Returns true if all 4 squares have the same color, otherwise false

//	public boolean match() {
//		boolean isMatch = true;
//		Color firstColor = this.currentColors[0];
//		for (int i = 1; i < this.currentColors.length; i++) {
//			if (this.currentColors[i] != firstColor) {
//				isMatch = false;
//				break;
//			}
//		}
//		return isMatch;
//	}

	// Implements the game mechanism, while all squares do not have the same color
	// lets the
	// user press squares to change their colors.
	// When all the squares have matching colors displays a text that says “You
	// won!”
	public void play() {
		while (!this.draw.match()) {
			if (StdDraw.isMousePressed()) {
			//	double[] mouseLocation = location.mouseLocation();
			//	this.business.changeColor(this.draw.color, location.whichSquare(mouseLocation));
			//	this.business.changeColor(this.draw.color, location.whichSquare());
				this.business.changeColor(this.draw.color);

//				Color firstColor = this.currentColors[2];
//				boolean conti = false;
//				for (int i = 1; i < this.currentColors.length; i++) {
//					if (this.currentColors[i] != firstColor) {
//						conti = true;
//						break;
//					}
//				}
//				if (!conti) {
//					break;
//				}
			}
			StdDraw.pause(150);
		}
//		StdDraw.setPenColor(StdDraw.BLACK);
//		StdDraw.text(0.5, 0.5, "You win!”");
		
		this.draw.writeWin();
	}

	// Returns a double array which contains x and y coordinates of the mouse
	// location
//	public double[] mouseLocation() {
//		double[] locations = new double[2];
//		locations[0] = StdDraw.mouseX();
//		locations[1] = StdDraw.mouseY();
//		return locations;
//	}

	// Finds and returns the square which the mouse location resides in
//	public int whichSquare(double[] mouseLoc) {
//		if ((mouseLoc[0] >= 0) && (mouseLoc[0] <= 0.5)) {
//			if ((mouseLoc[1] >= 0) && (mouseLoc[1] <= 0.5)) {
//				return 2;
//			} else {
//				return 0;
//			}
//		} else {
//			if ((mouseLoc[1] >= 0) && (mouseLoc[1] <= 0.5)) {
//				return 3;
//			} else {
//				return 1;
//			}
//		}
//	}

	// Takes the square which the user has clicked and changes the color of that
	// square randomly
//	public void changeColor(int whichSquare) {
//		currentColors[whichSquare] = this.business.randomColor();
//		StdDraw.setPenColor(currentColors[whichSquare]);
//		if (whichSquare == 0) {
//			StdDraw.filledSquare(0, 1, halfLength);
//		} else if (whichSquare == 1) {
//			StdDraw.filledSquare(1, 1, halfLength);
//		} else if (whichSquare == 2) {
//			StdDraw.filledSquare(0, 0, halfLength);
//		} else {
//			StdDraw.filledSquare(1, 0, halfLength);
//		}
//		StdDraw.show();
//	}

}