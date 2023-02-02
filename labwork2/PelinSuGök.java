package labwork2;

//Pelin Su Gök/Section-1/202011405

import java.awt.Color;
import java.util.Random;

public class PelinSuGök {
	
  Color[] colors = new Color[5];
  Color[] currentColors = new Color[4];
  double halfLength = 0.5;

  public PelinSuGök() {
      StdDraw.setCanvasSize(500, 500);
      this.colors = new Color[]{Color.PINK, Color.MAGENTA, Color.CYAN, Color.RED, Color.ORANGE};
      // Pick random 4 colors with the method you have written
      for (int i = 0; i < this.currentColors.length; i++) {
          currentColors[i] = this.randomColor();					//Assigns random colors to currentColors array
      }
      // Change the currentColors array accordingly with these colors
      // Set the colors for filling the squares and call the filledSquare method
      //0. location
      StdDraw.setPenColor(currentColors[0]);
      StdDraw.filledSquare(0, 1, halfLength);
      //1.location
      StdDraw.setPenColor(currentColors[1]);
      StdDraw.filledSquare(1, 1, halfLength);
      //2.location
      StdDraw.setPenColor(currentColors[2]);
      StdDraw.filledSquare(0, 0, halfLength);
      //3.location
      StdDraw.setPenColor(currentColors[3]);
      StdDraw.filledSquare(1, 0, halfLength);
  }

  // Main method should exactly be this
  public static void main(String[] args) {
      PelinSuGök r = new PelinSuGök();
      r.play();
  }

  // Randomly chooses and returns a Color from your colors[] array
  public Color randomColor() {
      Random rand = new Random();
      int randomColorIndex = rand.nextInt(colors.length);		//Generates a random number maximum value of colors arrays length
      return colors[randomColorIndex];						//Assigns random number to index of colors array and returned a random number from array 
  }

  // Returns true if all 4 squares have the same color, otherwise false
  
  public boolean match(Color rand1, Color rand2, Color rand3, Color rand4) {			//Checks if all colors matches or not
  		if(currentColors[0].equals(currentColors[1]) && currentColors[1].equals(currentColors[2]) && currentColors[2].equals(currentColors[3]))
  			return true;
  		else
  			return false;
  	}

  // Implements the game mechanism, while all squares do not have the same color lets the
  // user press squares to change their colors.
  // When all the squares have matching colors displays a text that says “You won!”
  public void play() {
      while (match(currentColors[0], currentColors[1], currentColors[2], currentColors[3]) == false) {
          if (StdDraw.isMousePressed()) {	
              double[] mouseLocation = mouseLocation();
              changeColor(whichSquare(mouseLocation));
          }
          StdDraw.pause(50);
      }
      StdDraw.setPenColor(StdDraw.BLACK);					//Prints message in black
      StdDraw.text(0.5, 0.5,"You won!”");					//Prints message middle of the screen
  }

  // Returns a double array which contains x and y coordinates of the mouse location
  public double[] mouseLocation() {
      double[] locations = new double[2];
      locations[0] = StdDraw.mouseX();					//Assigns x coordinate of mouse to first element of the array
      locations[1] = StdDraw.mouseY();					//Assigns y coordinate of mouse to second element of the array
      return locations;									//Returns the array
  }

  // Finds and returns the square which the mouse location resides in
  public int whichSquare(double[] mouseLoc) {
      if ((mouseLoc[0] >= 0) && (mouseLoc[0] <= 0.5)) {
          if ((mouseLoc[1] >= 0) && (mouseLoc[1] <= 0.5)) {
              return 2;									//Bottom-left square
          } else {
              return 0;									//Top-left square
          }
      } else {
          if ((mouseLoc[1] >= 0) && (mouseLoc[1] <= 0.5)) {
              return 3;									//Bottom-right square
          } else {
              return 1;									//Top-right square
          }
      }
  }

  // Takes the square which the user has clicked and changes the color of that square randomly
  public void changeColor(int whichSquare) {
  	
      currentColors[whichSquare] = randomColor();				//Checks which square has clicked and changes the squares color
      StdDraw.setPenColor(currentColors[whichSquare]);
      if (whichSquare == 0) {
          StdDraw.filledSquare(0, 1, halfLength);
      } else if (whichSquare == 1) {
          StdDraw.filledSquare(1, 1, halfLength);
      } else if (whichSquare == 2) {
          StdDraw.filledSquare(0, 0, halfLength);
      } else {
          StdDraw.filledSquare(1, 0, halfLength);
      }
      StdDraw.show();
  }


}