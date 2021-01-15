import java.util.*;

public class circle {
	
	double r;
	double x;
	double y;
	double exs, ex, eys, ey, c;
	
	public circle (double a, double b, double c) {
		r = a;
		x = b; 
		y = c;
	}
	
	public void standardize () {
		exs = 1; eys = 1;
		ex = 0-x-x; ey = 0-y-y;
		c = (x*x)+(y*y)-(r*r);
	}
	
	public double getEXS () {return exs;}
	public double getEYS () {return eys;}
	public double getEX () {return ex;}
	public double getEY () {return ey;}
	public double getC () {return c;}
	
	public void solve (circle a, ArrayList <point> points) {
		
		double sx = -(ex-a.ex) / (ey-a.ey);
		double sc = -(c-a.c) / (ey-a.ey);
		
		double a1 = 1+(sx*sx);
		double b1 = ex + (2*sx*sc) + (ey*sx);
		double c1 = (sc*sc)+(ey*sc) +c;
		
		//System.out.println(a1);
		//System.out.println(b1);
		//System.out.println(c1);
		
		double insquare = (b1*b1)-(4*a1*c1);
		
		double top1 = -b1 + Math.sqrt(insquare);
		double x1 = top1/(2*a1);
		points.add(new point());
		points.get(points.size()-1).setX(x1);
		points.get(points.size()-1).setY((sx*x1) + sc);
		
		double top2 = -b1 - Math.sqrt(insquare);
		double x2 = top2/(2*a1);
		points.add(new point());
		points.get(points.size()-1).setX(x2);
		points.get(points.size()-1).setY((sx*x2) + sc);
		
	}
	
	public String toString () {
		return "Centre: " + x + ", "+ y + "\nRadius: " + r;
	}
}
