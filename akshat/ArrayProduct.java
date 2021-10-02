package arrays;

import java.util.Scanner;

public class ArrayProduct {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the dimensions of the first array");
		int rows1 = sc.nextInt();
		int cols1 = sc.nextInt();
		System.out.println("Enter the dimensions of the second array");
		int rows2 = sc.nextInt();
		int cols2 = sc.nextInt();
		
		int a[][] = new int[rows1][cols1];
		int b[][] = new int[rows2][cols2];
		System.out.println("Enter the values of the first array");
		 for(int i=0;i<rows1;i++)
		 {
			 for(int j=0;j<cols1;j++)
				 a[i][j] = sc.nextInt();
		 }
		 System.out.println("Enter the values of the second array");
		 for(int i=0;i<rows2;i++)
		 {
			 for(int j=0;j<cols2;j++)
				 b[i][j] = sc.nextInt();
		 }
		 int c[][] = new int[rows1][cols2];
		 for(int i=0;i<rows1;i++)
		 {
			 for(int j=0;j<cols2;j++)
			 {
				 for(int k=0;k<cols1;k++)
					 c[i][j] += a[i][k]*b[k][j];
			 }
		 }
		 System.out.println("The resulting array is:");
		 for(int i=0;i<rows1;i++)
		 {
			 for(int j=0;j<cols2;j++)
				 System.out.print(c[i][j] + " ");
			 System.out.println();
		 }

	}

}
