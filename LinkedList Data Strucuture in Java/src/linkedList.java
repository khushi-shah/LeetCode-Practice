//Khushi Shah
public class linkedList {
	
	private linkedList before;
	private linkedList after;
	private String status;
	private String value;
	
	public linkedList (linkedList a, linkedList b, String c, String d) {
		before = a;
		after = b;
		status = c;
		value = d;
	}
	
	public void setNext (linkedList a) {
		after = a;
	}
	
	public void setBefore (linkedList b) {
		before = b;
	}
	
	public linkedList getNext () {
		return after;
	}
	
	public linkedList getBefore () {
		return before;
	}
	
	public void printName () {
		if (status.equals("end")) {
			System.out.print(value);
		}
		else {
			System.out.print(value);
			after.printName();
		}
	}
}
