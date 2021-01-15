//Khushi Shah
public class name {
	public static void main (String[]args) {
		
		linkedList k = new linkedList (null, null, "front", "K");
		linkedList h = new linkedList (k, null, "middle", "h");
		linkedList u = new linkedList(h, null, "middle", "u");
		linkedList s = new linkedList (u, null, "middle", "s");
		linkedList h2 = new linkedList (s, null, "middle", "h");
		linkedList i = new linkedList (h2, null, "end", "i");
		
		k.setNext(h);
		h.setNext(u);
		u.setNext(s);
		s.setNext(h2);
		h2.setNext(i);
		
		k.printName();
	}
}
