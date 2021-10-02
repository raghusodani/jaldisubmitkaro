import java.util.*;

public class InsertionSort{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int n = sc.nextInt();
        int ar[] = new int[n];
        System.out.println("Enter the array : ");
        for(int i=0;i<ar.length;i++){
            ar[i]=sc.nextInt();
        }
        for(int i=1; i<ar.length; i++){  
            int temp = ar[i];  
            int j= i-1;  
            while(j>=0 && temp <= ar[j]){  
                ar[j+1] = ar[j];   
                j = j-1;  
            }  
            ar[j+1] = temp;  
        }
        for(int i=0;i<ar.length;i++){
            System.out.printf(ar[i]+" ");
        }  
    }
}