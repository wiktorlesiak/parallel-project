import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.*;
import java.util.concurrent.TimeUnit;

import javax.swing.*;

@SuppressWarnings("serial")
public class Zombie_Infection_Display extends JPanel{
	
	static JFrame frame = new JFrame("Zombie Infection Display");
	public static int totalCells = 0;//variable to hold total amount of cells													
	public static int sroot = 0;//variable to hold the square root of the total amount of cells
	@SuppressWarnings("rawtypes")
	public static ArrayList world = new ArrayList();//list to hold the world read from the file
	private static BufferedImage canvas;//to allow per pixel display
	public static int iterationNum = 0;//for readFromFile to know which file to read
	public static int totalIteration = 79;//to know when to stop the loop
	public static int humanCount = 0;
	
	public static void main(String[] args) throws Exception {
		getWorldSize();//does one read of the first iteration file to allow the GUI to be set to the correct size
		for(int i = 0; i <= totalIteration; i++) {
		buildGUI();//uses information from getWorldSize() to create the GUI
		readFromFile();//reads file and stores into array list
		printGUI();//changes each pixel colour to represent the world
		System.out.println("Iteration: "+iterationNum);
		System.out.println("Human Count: "+humanCount);
		System.out.println("");
		System.out.println("");
		frame.getContentPane().repaint();//refresh canvas
		iterationNum++;//continue to next iteration file
		humanCount = 0;//reset human count
		world.clear();//clear arrayList world
		TimeUnit.MILLISECONDS.sleep(250);//wait 250 milliseconds between displays
		}
	}

	@SuppressWarnings({ "resource", "unused" })
	public static void getWorldSize() throws Exception {
		FileReader fr = new FileReader("C:\\Users\\gerry\\Desktop\\Parallel_2018\\Zombie_Infection\\world_iterations\\"+ iterationNum +".text");
		int i;

		while ((i=fr.read()) != -1) {
			totalCells ++;//counts up every cell from the file
		}
		sroot = (int) Math.sqrt(totalCells);//calculate the square root to allow the gui to be set to the correct size
		
		System.out.println("Total Cells: "+totalCells);
		System.out.println("Square root of "+totalCells+": "+sroot);
	}
	
	public static void buildGUI() {
		
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setBackground(Color.black);
		frame.setPreferredSize(new Dimension(sroot+18,sroot+47));//uses the sroot to set the correct size of the jframe (the additional numbers are to correct the size)
		frame.add(new Zombie_Infection_Display());
		frame.setLocationRelativeTo(null);
		frame.pack();
		frame.setVisible(true);
		
		
	}

	@SuppressWarnings({ "unchecked", "resource" })
	public static void readFromFile() throws Exception{
		FileReader fr = new FileReader("C:\\Users\\gerry\\Desktop\\Parallel_2018\\Zombie_Infection\\world_iterations\\"+ iterationNum +".text");
		int i;
		
		while ((i=fr.read()) != -1) {
			//the minus 48 is to account for the reader reading the ascii value instead of the character itself
			world.add(i-48);
		}
	}
	
	public void paintComponent(Graphics g) {// calls the UI paint method
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;
		g2.drawImage(canvas, null, null);
		repaint();
	}
	
	private static void printGUI() {
		canvas = new BufferedImage(sroot,sroot, BufferedImage.TYPE_INT_ARGB);
		int green = Color.green.getRGB();
		int red = Color.red.getRGB();
		int black = Color.black.getRGB();
		int blue = Color.blue.getRGB();
		int yellow = Color.yellow.getRGB();
		int white = Color.white.getRGB();
		int i;
		int x = 0;
		int y = 0;
		
		for(i=0;i<totalCells;i++) {//goes through the list changing the pixels colours to represent the world correctly
			int cell = (int) world.get(i);
			if(x == sroot) {//if the x value reaches the value of sroot it will move down to the next line
				x = 0;
				y++;
			}
			if(cell == 0) {//if cell equals 0 the pixel is set to black
				canvas.setRGB(x,y,red);
				x++;
			}else if(cell == 1) {//if cell equals 1 the pixel is set to green
				canvas.setRGB(x,y,green);
				humanCount++;
				x++;
			}else if(cell == 2) {//if cell equals 2 the pixel is set to green
				canvas.setRGB(x,y,black);
				x++;
			}else if(cell == 3){//if cell equals a different number the pixel is set to red
				canvas.setRGB(x,y,black);
				x++;
			}else {//if cell equals a different number the pixel is set to red
				canvas.setRGB(x,y,yellow);
				x++;
			}
			
		}
	}
	
}
