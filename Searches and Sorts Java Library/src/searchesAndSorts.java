//Khushi Shah
import java.util.*;
public class searchesAndSorts {
	public static void main (String[]args) {
		int [] test = {14, 3, 67, 2, 8, 90, 54};
		//insert whichever method you want to test
		for (int n = 0; n < test.length; n++) { // prints the array
			System.out.print(test[n] + " ");
		}
	}
	public static int linearSearch (int [] arr, int n) {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == n)
				return i;
		}
		return 0;
	}
	public static int binarySearch (int [] arr, int n, int l, int r) {
		if (r >= 1) {
			int mid = l + (r-1)/2;
			if (arr[mid] < n)
				return binarySearch (arr, n, mid+1, r);
			else if (arr[mid] == n)
				return mid;
			else if (arr[mid] > n)
				return binarySearch (arr, n, l, mid - 1);
		}
		return 0;
	}
	public static void selectionSort (int [] arr) {
		for (int i = 0; i < arr.length-1; i++) {
			int min = i;
			for (int j = i+1; j < arr.length; j++) {
				if (arr[j] < arr[min])
					min = j;
			}
			int t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
	}
	public static void mergeSort1 (int [] arr, int start, int end) {
		if (start < end) {
			int mid = (start+end)/2;
			mergeSort1(arr, start, mid); //split into 1
			mergeSort1(arr, mid+1, end); //split into 2
			mergeSort2(arr, start, mid, end); // merge when the end is reached
		}
	}
	public static void mergeSort2 (int [] arr, int start, int mid, int end) {
		//temporarily split into 2
		int [] left = new int [mid-start+1]; 
		int [] right = new int [end-mid];
		for (int i = 0; i < mid-start+1; i++) 
	        left[i] = arr[start + i]; 
	    for (int j = 0; j < end-mid; j++) 
	        right[j] = arr[mid + 1+ j]; 
	    //sort
	    int l = 0; //for the left side 
	    int r = 0; // for the right side
	    int index = start;
	    while (l < mid-start+1 && r < end-mid) {
	    	if (left[l] <= right[r]) {
	    		arr[index] = left[l]; 
	    		l++;
	    	}
	    	else {
	    		arr[index] = right[r];
	    		r++;
	    	}
	    	index++;
	    }
	    //left overs
	    while (l < mid-start+1){
	    	arr[index] = left[l];
	    	index++;
	    	l++;
	    }
	    while (r < end-mid) {
	    	arr[index] = right[r];
	    	index++;
	    	r++;
	    }
	}
}