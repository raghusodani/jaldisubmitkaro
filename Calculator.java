

import java.util.Scanner;
//
public class Calculator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the first number");
		int a = sc.nextInt();
		
		System.out.println("Enter the second nember");
		int b = sc.nextInt();
		
		System.out.println("Enter the operator");
		sc.nextLine();
		char operation = sc.nextLine().charAt(0);
		
		int result=0;
		switch(operation)
		{
		case'+':
		case'=':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		default:
			System.out.println("Invalid operation");
		}
		System.out.println("The result is " + result);
		
	}

}
