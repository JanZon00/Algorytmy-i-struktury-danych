import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

//do przechowywania par wspolrzednych
class Pair
{
    public static <T, U> Map<T, U> of(T first, U second) {
        return Collections.singletonMap(first, second);
    }
}

public class MazeGenerator extends JPanel{

	public static <T, U> Map.Entry<T, U> of(T first, U second) {
        return new AbstractMap.SimpleEntry<>(first, second);
    }

	int UNIT_SIZE;
	int SCREEN_WIDTH = 1;
	int SCREEN_HEIGHT = 1;
	Set<Map<Integer, Integer>> maze = new HashSet<Map<Integer, Integer>>();
	Set<Map<Integer, Integer>> neighbouringCells = new HashSet<Map<Integer, Integer>>();

	private void work() {
		
			Scanner scan = new Scanner(System.in);
			System.out.println("Podaj szerokosc (jednostka wynosi 20px dlatego preferowane rozmiary to na przyklad 100, 440, 600 ,800 etc...) : ");
			SCREEN_WIDTH = scan.nextInt();
			System.out.println("Podaj wysokosc (jednostka wynosi 20px dlatego preferowane rozmiary to na przyklad 100, 440, 600 ,800 etc...) : ");
			SCREEN_HEIGHT = scan.nextInt();
			UNIT_SIZE = 20;
			scan.close();
			if(SCREEN_HEIGHT % 20 != 0 || SCREEN_WIDTH % 20 != 0){
				System.out.println("Bledne dane");
				System.exit(0);
			}	

		JFrame jf = new JFrame();
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.add(this, BorderLayout.CENTER);
		jf.setResizable(false);
		jf.setSize(SCREEN_WIDTH + 60, SCREEN_HEIGHT + 80);
		this.setBackground(Color.black);
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		drawMaze(g);
	}

	public void drawMaze(Graphics g) {
		
		
		g.setColor(Color.white);
		int x = 0, y = 0;
		//rysowanie pionowych scian
		for(int i = 0; i <SCREEN_WIDTH/UNIT_SIZE; i++){
			y = 0;
			for(int j = 0; j <SCREEN_HEIGHT/UNIT_SIZE; j++){
				g.fillRect(x + UNIT_SIZE, y + UNIT_SIZE, 4, UNIT_SIZE);
				y += UNIT_SIZE;
			}
			g.fillRect(x + UNIT_SIZE, SCREEN_WIDTH + UNIT_SIZE, UNIT_SIZE + 4, 4);
			x += UNIT_SIZE;
		}
		x = 0;
		//rysowanie poziomych scian
		for(int i = 0; i <SCREEN_WIDTH/UNIT_SIZE; i++){
			y = 0;
			for(int j = 0; j <SCREEN_HEIGHT/UNIT_SIZE; j++){
				g.fillRect(x + UNIT_SIZE, y + UNIT_SIZE, UNIT_SIZE, 4);
				if(i == SCREEN_HEIGHT/UNIT_SIZE - 1){
					g.fillRect(SCREEN_WIDTH + UNIT_SIZE, y + UNIT_SIZE, 4, UNIT_SIZE + 4);
				}
				y += UNIT_SIZE;
			}
			x += UNIT_SIZE;
		}

		//losowanie wspolrzednych poczotkowych labiryntu
		Random rand = new Random(); 
		int randomCell_x = SCREEN_WIDTH/20;
		int randomCell_y = rand.nextInt(SCREEN_HEIGHT/20);
		maze.add(Pair.of(randomCell_x, randomCell_y));
		g.setColor(Color.black);
		g.fillRect((randomCell_x)*UNIT_SIZE + UNIT_SIZE, (randomCell_y)*UNIT_SIZE +  UNIT_SIZE, 4, UNIT_SIZE - 4);

		//algorytm Prima
		while(maze.size() != SCREEN_HEIGHT/20 * SCREEN_WIDTH/20){	
			//Dodawanie sasiadujacych scian do zbioru zawierajacego pary wspolrzednych scian
			if(randomCell_x - 1 > 0)
				neighbouringCells.add(Pair.of(randomCell_x - 1, randomCell_y));
			if(randomCell_x + 1 <= (SCREEN_WIDTH)/20)	
				neighbouringCells.add(Pair.of(randomCell_x + 1, randomCell_y));
			if(randomCell_y - 1 > 0)
				neighbouringCells.add(Pair.of(randomCell_x, randomCell_y - 1));
			if(randomCell_y + 1 <= (SCREEN_HEIGHT)/20)	
				neighbouringCells.add(Pair.of(randomCell_x, randomCell_y + 1));
			
			//losowanie sciany do usuniecia
			Map<Integer, Integer> targetmap = new HashMap<>();
			Random rand_wall = new Random();
			ArrayList<Map<Integer, Integer>> targetList = new ArrayList<>(neighbouringCells);
			targetmap = targetList.get(rand_wall.nextInt(targetList.size()));

			//tworze liste w ktorej przechowam wspolrzedne tej wylosowanej sciany
			ArrayList<Integer> list = new ArrayList();
			list.addAll(targetmap.keySet());
			list.addAll(targetmap.values());
			
			int poz_x = list.get(0);
			int poz_y = list.get(1);
			if(!maze.contains(Pair.of(poz_x, poz_y))){		//jesli w secie sciana wciaz istnieje to usuwamy
				if(randomCell_x == poz_x && poz_y != SCREEN_HEIGHT/20){
					g.fillRect((poz_x - 1)*UNIT_SIZE + 4 + UNIT_SIZE, (poz_y + 1)*UNIT_SIZE, UNIT_SIZE - 4, 4);
				}
				else if(poz_x != SCREEN_WIDTH/20){
					g.fillRect((poz_x)*UNIT_SIZE + UNIT_SIZE, (poz_y)*UNIT_SIZE + 4, 4, UNIT_SIZE - 4);
				}
			}
			//dodajemy do setu maze sciane ktora usunelismy zeby juz jej nie brac pod uwage
			maze.add(Pair.of(poz_x, poz_y));
			neighbouringCells.clear();
			randomCell_x = poz_x;		//zmienamy wspolrzedne poczatkowe na te ktore naleza do sciany ktora wylosowalismy
			randomCell_y = poz_y;
		}	  
	}
	public static void main(String[] argv) {
		MazeGenerator g = new MazeGenerator();
		g.work();
	}
}