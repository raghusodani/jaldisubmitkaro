import java.util.*;

public class SelectionSort {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the size of the array : ");
    int n = sc.nextInt();
    int ar[] = new int[n];
    System.out.println("Enter the array : ");
    for(int i=0;i<ar.length;i++){
        ar[i]=sc.nextInt();
    }
    for(int i=0;i<ar.length-1;i++){
        int min =i;
        for(int j=i+1;j<ar.length;j++){
            if(ar[j]<ar[min]){
                min = j;
            }
        }
        int temp=ar[min];
        ar[min]=ar[i];
        ar[i]=temp;

    }
    System.out.println("The sorted array is as follows : ");
    for(int i=0;i<ar.length;i++){
        System.out.printf(ar[i]+" ");
    }

    }
}
