import java.util.*;

public class LinearSearch{
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
        int numberToBeSearched = sc.nextInt();
        for(int i=0;i<ar.length;i++)
        {
            if(ar[i] == numberToBeSearched)
            {
                System.out.println("The number is found at position " + (i+1) +".");
                break;
            }
            else if( i == ar.length-1)
            {
                System.out.println("Number not found!");
            }
        }

    }
}