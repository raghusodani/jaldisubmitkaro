import java.util.*;

public class BinarySearch {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int n = sc.nextInt();
        int ar[] = new int[n];
        System.out.println("Enter the array : ");
        for(int i=0;i<ar.length;i++){
            ar[i]=sc.nextInt();
        } 
        System.out.println("Enter the number to be searched : ");
        int key = sc.nextInt();
        int index=-1;
        int low=0,high=ar.length-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ar[mid] < key) {
                low = mid + 1;
            } else if (ar[mid] > key) {
                high = mid - 1;
            } else if (ar[mid] == key) {
                index = mid;
                break;
            }
    }
    if(index==-1 ){
        System.out.println("Element not found!");
    }
    System.out.println("The number to be searched for is found at index : "+(index+1)+".");
}
        
}  
