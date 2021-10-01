package dev;

public class QuickSort {
	
	private int array[];
	private int length;

	public void sort(int[] Arr) {
		
		if (Arr==null||Arr.length == 0) {
			return;
		}
		this.array = Arr;
		length = Arr.length;
		quickSort(0, length - 1);
	}

	private void quickSort(int lowerIndex, int higherIndex) {
		
		int i = lowerIndex;
		int j = higherIndex;
		
		int pivot = array[lowerIndex+(higherIndex-lowerIndex)/2];
		
		while (i <= j) {
			
			while (array[i] < pivot) {
				i++;
			}
			while (array[j] > pivot) {
				j--;
			}
			if (i <= j) {
				exchangeNumbers(i, j);
				
				i++;
				j--;
			}
		}
		
		if (lowerIndex < j)
			quickSort(lowerIndex, j);
		if (i < higherIndex)
			quickSort(i, higherIndex);
	}

	private void exchangeNumbers(int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	
	public static void main(String a[]){
		
		QuickSort sorter = new QuickSort();
	    int[] dev = {24,2,45,20,56,75,2,56,99,53,12};
	    sorter.sort(dev);
	    for(int i=0;i<dev.length;i++){
	    	System.out.print(dev[i]);
	    	System.out.print(" ");
	    }
	}
}
