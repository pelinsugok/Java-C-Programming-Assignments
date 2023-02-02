package soccer;

//Pelin Su G�k/Section-1/202011405
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Soccer {
	public Soccer() {

	}

	static Scanner scan = new Scanner(System.in);
	List<Team> teamList = new ArrayList<Team>();
	int[] startDate = new int[3];
	int[] endDate = new int[3];
	int currentWeek;
	Team currentChampion = new Team();

	public void addSeasonInfo(int[] startDate, int[] endDate, int currentWeek) {
		this.startDate = startDate;
		this.endDate = endDate;
		this.currentWeek = currentWeek;
	}

	public void addTeam(Team team) {
		if (this.isTeamExist(team.teamName) == -1) {
			this.teamList.add(team); // Adds inputted team to team list.
		} else {
			System.out.println("The team already exist."); // Outputs a warning in case of creating new teams with same names.
		}
	}

	public void deleteTeam(String teamName) {
		int index = this.isTeamExist(teamName); // A method checks is the team exists or not and return an integer.
		if (index != -1) {
			this.teamList.remove(index); // Removes the team from the team list.
		} else {
			System.out.println("The team does not exist."); // Outputs a warning if the team does not exist.
		}
	}

	public Team findChampion() {
		Team champion = null;	
		if (this.teamList.size() > 0) {
			champion = this.teamList.get(0);
			for (int i = 1; i < this.teamList.size(); i++) {
				if (champion.currentMatchPoint < this.teamList.get(i).currentMatchPoint) { // Finds which team has the maximum value of currentMatchPoint.
					champion = this.teamList.get(i);				//Gets the index of the champion team from the team list.
				}
			}
		}
		return champion;
	}

	public void displayAllTeams() {
		if (this.teamList.size() == 0) { // If team does not exist, outputs EMPTY.
			System.out.println("-EMPTY-");
		} else {
			System.out.println(this.startDate[0] + "." + this.startDate[1] + "." + this.startDate[2] + "- "
					+ this.endDate[0] + "." + this.endDate[1] + "." + this.endDate[2] + ", " + this.currentWeek + ", "
					+ this.currentChampion.teamName);
			for (int i = 0; i < this.teamList.size(); i++) { // Outputs teams, their dates, names and colors.
				System.out.println(this.teamList.get(i).teamName + ", " + this.teamList.get(i).color);
			}
		}
	}

	public void findPlayer(String playerName) {
		boolean isExist = false; // Checks if there is a player has the same name as inputted name.
		for (int i = 0; i < this.teamList.size(); i++) {
			if (this.teamList.get(i).isAPlayer(playerName)) { // If isAPlayer method returns true, it means there is a player with the same name as input.
				this.teamList.get(i).displayTeamShortInfo(); // Displays teams which the inputted player plays in and their colors.
				isExist = true;
			}
		}
		if (!isExist) {
			System.out.println("The player does not exist."); // Outputs a warning if the player does not exist.
		}
	}

	public int isTeamExist(String teamName) { // This method is for checking if inputted team exists or not.
		for (int i = 0; i < this.teamList.size(); i++) {
			if (teamName.equals(this.teamList.get(i).teamName)) {
				return i; // Returns index of the teamList which inputted team is in.
			}
		}
		return -1; // If team does not exists returns -1.
	}

	public int operationInt() {						//Checks if the input is integer or not. 
		int operation = -1;	
		if (this.scan.hasNextInt()) {
			operation = this.scan.nextInt();
		} else {
			this.scan = new Scanner(System.in);
		}
		return operation;							//Returns -1 if input is not integer.
	}

	public static void main(String[] args) {
		Soccer soccer = new Soccer();

		while (true) { // An infinite loop
			System.out.println("1. Add information about the current season"); // Menu declaration
			System.out.println("2. Add a team");
			System.out.println("3. Remove a team");
			System.out.println("4. Add a player to the team");
			System.out.println("5. Remove a player from the team");
			System.out.println("6. Display all registered teams");
			System.out.println("7. Display detailed information about a particular team");
			System.out.println("8. Find which team(s) a player is playing for");
			System.out.println("9. Find current champion");
			System.out.println("10.Find out if a player is playing for a specific team");
			System.out.println("0. EXIT!");
			System.out.print("   choose one of them ->");
			int input = soccer.operationInt();

			if ((input > 10 || input < 0)) {			//Checks the input is invalid or not.
				System.out.println("Sorry, couldn't understand you!");
			}
			// 0. EXIT!
			if (input == 0) {
				System.out.println("Goodbye!");
				break; // Breaks out of loop if user chooses to exit.
			}
			// 1. Add information about the current season
			if (input == 1) {
				int[] sDate = new int[3];
				int[] eDate = new int[3];
				int cWeek;
				int scanInt;
				System.out.print("Enter start day: ");
				scanInt = soccer.operationInt();
				while (scanInt > 31 || scanInt < 0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter start day: ");
					scanInt = soccer.operationInt();
				}
				sDate[0] = scanInt;
				System.out.print("Enter start month: ");
				scanInt = soccer.operationInt();
				while (scanInt > 12 || scanInt < 0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter start month: ");
					scanInt = soccer.operationInt();
				}
				sDate[1] = scanInt;
				System.out.print("Enter start year: ");
				scanInt = soccer.operationInt();
				while (scanInt < 0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter start year: ");
					scanInt = soccer.operationInt();
				}
				sDate[2] = scanInt;
				System.out.print("Enter end day: ");
				scanInt = soccer.operationInt();
				while (scanInt > 31 || scanInt <0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter end day: ");
					scanInt = soccer.operationInt();
				}
				eDate[0] = scanInt;
				System.out.print("Enter end month: ");
				scanInt = soccer.operationInt();
				while (scanInt > 12 || scanInt < 0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter end month: ");
					scanInt = soccer.operationInt();
				}
				eDate[1] = scanInt;
				System.out.print("Enter end year: ");
				scanInt = soccer.operationInt();
				while (scanInt < 0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter end year: ");
					scanInt = soccer.operationInt();
				}
				eDate[2] = scanInt;
				System.out.print("Enter current week: ");
				scanInt = soccer.operationInt();
				while (scanInt < 0) {
					System.out.println("Sorry, couldn't understand you!");
					System.out.print("Enter current week: ");
					scanInt = soccer.operationInt();
				}
				cWeek = soccer.operationInt();
				soccer.addSeasonInfo(sDate, eDate, cWeek);
			}
			// 2. Add a team
			if (input == 2) {
				Team team = new Team();
				System.out.print("Enter team name: ");
				team.teamName = scan.next();
				System.out.print("Enter team color: ");
				team.color = scan.next();
				System.out.print("Enter team match point: ");
				team.currentMatchPoint = scan.nextInt();
				soccer.addTeam(team);
			}
			// 3. Remove a team
			if (input == 3) {
				System.out.print("Enter team name: ");
				soccer.deleteTeam(scan.next());
			}
			// 4. Add a player to the team
			if (input == 4) {
				System.out.print("Enter the team name: ");
				String teamName = scan.next();
				int indexTeam = soccer.isTeamExist(teamName);
				if (indexTeam != -1) {
					while (true) {
						System.out.println("-----Team Name: " + soccer.teamList.get(indexTeam).teamName);
						System.out.println("-----41. add player");
						System.out.println("-----42. exit");
						System.out.print("-----   choose one of them ->");
						int input4SubMenu = soccer.operationInt();
						if ((input4SubMenu > 42 || input4SubMenu < 41)) {
							System.out.println("Sorry, couldn't understand you!");
						}
						if (input4SubMenu == 41) {
							System.out.print("Enter the player: ");
							soccer.teamList.get(indexTeam).addPlayer(scan.next());
						}
						if (input4SubMenu == 42) {
							break;
						}
					}
				} else {
					System.out.println("The team does not exist.");
				}
			}
			// 5. Remove a player from the team
			if (input == 5) {
				System.out.print("Enter team name: ");
				int index = soccer.isTeamExist(scan.next()); // Checks if the inputted team is exists or not.
				if (index != -1) {
					while (true) {
						System.out.println("-----51. remove player");
						System.out.println("-----52. exit");
						System.out.print("-----   choose one of them ->"); // Asks user to either choose to continue or go back to the main menu.
						int input5SubMenu = soccer.operationInt();
						if ((input5SubMenu > 52 || input5SubMenu < 51)) {
							System.out.println("Sorry, couldn't understand you!");
						}
						if (input5SubMenu == 51) { // If user chooses to continue
							System.out.print("Enter player name: ");
							soccer.teamList.get(index).deletePlayer(scan.next());
						}
						if (input5SubMenu == 52) { // Back to the main menu.
							break;
						}
					}
				} else {
					System.out.println("The team does not exist."); // If the inputted team does not exist outputs a warning.
				}
			}
			// 6. Display all registered teams
			if (input == 6) {
				soccer.displayAllTeams();

			}
			// 7. Display detailed information about a particular team
			if (input == 7) {
				System.out.print("Enter team name: ");
				int index = soccer.isTeamExist(scan.next());
				if (index != -1) { // Checks if the inputted team is exists or not.
					soccer.teamList.get(index).displayTeamInfo();
				} else {
					System.out.println("The team does not exist."); // If the inputted team does not exist outputs a warning.
				}
			}
			// 8. Find which team(s) a player is playing for
			if (input == 8) {
				System.out.print("Enter player name: ");
				soccer.findPlayer(scan.next());
			}
			// 9. Find current champion
			if (input == 9) {
				Team champion = soccer.findChampion();
				if (champion != null) {
					System.out.println("The Champion Team is " + champion.teamName + " !!!!!!");
				} else { // If there's no team findChampion method will return null
					System.out.println("-EMPTY-"); // If the findChampion method returns null it means there are no teams, it's empty.
				}
			}
			// 10.Find out if a player is playing for a specific team
			if (input == 10) {
				System.out.print("Enter team name: ");
				int index = soccer.isTeamExist(scan.next());
				if (index != -1) { // Checks if the inputted team is exists or not.
					System.out.print("Enter player name: ");
					if (soccer.teamList.get(index).isAPlayer(scan.next())) {// Checks if the inputted player is a player for inputted team.
						System.out.println("The player plays for this team");
					} else {
						System.out.println("The player does not plays for this team.");
					}
				} else {
					System.out.println("The team does not exist."); // If the inputted team does not exist outputs a  warning.
				}
			}
		}
	}
}
