import java.util.*;
public class calculator {
	public static void main (String[]args) {
		System.out.println ("Welcome to the WiFi Proximity Calculator!");
		
		Scanner input = new Scanner (System.in);
		System.out.print ("\nHow many WiFi signals would you like to enter: ");
		int num = input.nextInt(); input.nextLine();
		
		ArrayList <circle> list = new ArrayList <circle> ();
		for (int i = 0; i < num; i++) {
			System.out.println();
			System.out.print("Enter the x coordinate of WiFi beacon " + (i+1) + ": ");
			double x = input.nextDouble(); input.nextLine();
			System.out.print ("Enter the y coordinate of WiFi beacon " + (i+1) + ": ");
			double y = input.nextDouble(); input.nextLine();
			System.out.print ("Enter the range given by WiFi beacon " + (i+1) + ": ");
			double r = input.nextDouble(); input.nextLine();
			list.add(new circle (r, x, y));
			System.out.println();
		}
		
		for (int i = 0; i < num; i++) {
			//System.out.println();
			//System.out.println(list.get(i));
			list.get(i).standardize();
			//System.out.println("x^2 + " + list.get(i).getEX() + "x + y^2 + " +list.get(i).getEY() + "y + " + list.get(i).getC());
			//System.out.println();
		}
		
		ArrayList <point> points = new ArrayList <point> ();
		
		for (int i = 0; i < list.size(); i++) {
			for (int j = i+1; j < list.size(); j++) {
				//System.out.println();
				list.get(i).solve(list.get(j), points);
				//System.out.println();
			}
		}
		
		//Sorting for the final point
		int index = 0;
		for (int i = 0; i < points.size(); i++) {
			point a = points.get(i);
			int counter = 0;
			for (int j = 0; j < points.size(); j++) {
				if (points.get(j).compare(a)){
					counter++;
				}
				if (counter > 1) {
					index = i;
				}
			}
		}
		
		System.out.println("\nLocation:\n" + points.get(index).getRounded());
		
		input.close();
	}
}