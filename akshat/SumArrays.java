package arrays;

import java.util.Scanner;

public class SumArrays {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of rows and columns");
		int rows = sc.nextInt();
		int cols = sc.nextInt();
		
		int arr1[][] = new int[rows][cols];
		int arr2[][] = new int[rows][cols];
		
		System.out.println("Enter the elements of the first array");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
				arr1[i][j] = sc.nextInt();
		}
		System.out.println("Enter the elements of the second array");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
				arr2[i][j] = sc.nextInt();
		}
		int arr3[][] = new int[rows][cols];
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
				arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
		System.out.println("The resulting array is:");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
				System.out.print(arr3[i][j] + " ");
			System.out.println();
		}
		

	}

}
