
public class point {
	
	private double x; 
	private double y;
	
	//default
	public point () {
		x = 0;
		y = 0;
	}
	
	//custom
	public point (double a, double b) {
		x = a;
		y = b;
	}
	
	//getters
	public double getx () {
		return x;
	}
	public double gety () {
		return y;
	}
	//setters
	public void setX (double a) {
		x = a;
	} 
	public void setY (double a) {
		y = a;
	}
	public boolean compare (point a) {
		int x1 = (int) (x+0.5);
		int y1 = (int) (y+0.5);
		int x2 = (int) (a.getx() + 0.5);
		int y2 = (int) (a.gety() + 0.5);
		
		if ((x1==x2) && (y1 == y2)) {
			return true;
		}
		return false;
	}
	public point getRounded () {
		int x1 = (int) (x+0.5);
		int y1 = (int) (y+0.5);
		
		point x = new point (x1, y1);
		return x;
	}
	public String toString () {
		return "(" + x + ", " + y + ")";
	}
}
