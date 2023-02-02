package colorGame;

import java.awt.Color;

public class Draw {
	
	public Draw(){
		ColorBusiness business = new ColorBusiness();
		StdDraw.setCanvasSize(StaticVariables.canvasWidth, StaticVariables.canvasHeight);
		
		for(int i=0; i<color.length; i++) {
			color[i] = business.randomColor();
		}
	}
	
	Color[] color = new Color[4];
	
	
	public void drawSquare()
	{
		StdDraw.setPenColor(color[0]);
		StdDraw.filledSquare(0, 1, StaticVariables.halfLength);
		// 1.location
		StdDraw.setPenColor(color[1]);
		StdDraw.filledSquare(1, 1, StaticVariables.halfLength);
		// 2.location
		StdDraw.setPenColor(color[2]);
		StdDraw.filledSquare(0, 0, StaticVariables.halfLength);
		// 3.location
		StdDraw.setPenColor(color[3]);
		StdDraw.filledSquare(1, 0, StaticVariables.halfLength);
	}
	
	public boolean match() {
		boolean isMatch = true;
		Color firstColor = this.color[0];
		for (int i = 1; i < this.color.length; i++) {
			if (this.color[i] != firstColor) {
				isMatch = false;
				break;
			}
		}
		return isMatch;
	}
	
	public void writeWin() {
		StdDraw.setPenColor(StdDraw.BLACK);
		StdDraw.text(0.5, 0.5, "You win!�");
	}
	
	
}
