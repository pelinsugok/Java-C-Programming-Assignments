package soccer;

//Pelin Su G�k/Section-1/202011405
import java.util.ArrayList;
import java.util.List;

public class Team {

	public Team() {
	}

	List<String> playerList = new ArrayList<String>();
	String color;
	int currentMatchPoint;
	String teamName;

	public void addPlayer(String playerName) {
		for (int i = 0; i < this.playerList.size(); i++) {
			if (this.playerList.get(i).equals(playerName)) { // For checking if we had a player with the same name.
				System.out.println("This player already exist."); // If it does it outputs a warning but still adds	the player.													// player.
				break;
			}
		}
		this.playerList.add(playerName);				//Adds player to player list.
	}

	public void deletePlayer(String playerName) {
		boolean exist = false;
		for (int i = 0; i < this.playerList.size(); i++) {
			if (playerName.equals(this.playerList.get(i))) { // For checking if we had a player with the same name.
				this.playerList.remove(i); // It removes the player if player exist.
				exist = true;
				break;
			}
		}
		if (!exist) {
			System.out.println("This player does not exist."); // Outputs a warning if the player does not exist.
		}
	}

	public void displayTeamInfo() {							//Outputs teams name color and players.
		System.out.println("Team name: " + this.teamName);
		System.out.println("Team color: " + this.color);
		for (int i = 0; i < this.playerList.size(); i++) {
			System.out.println(i + "-" + this.playerList.get(i));
		}
	}

	public void displayTeamShortInfo() { // Outputs only teams name and color. Shorter version of displayTeamInfo.
		System.out.println("Team name: " + this.teamName + "," + "Team color: " + this.color);
	}
	
	public boolean isAPlayer(String playerName) {
		for (int i = 0; i < playerList.size(); i++) {
			if (playerName.equals(this.playerList.get(i))) { // Check if inputted player is in the player list or not.
				return true;
			}
		}
		return false;
	}

}
