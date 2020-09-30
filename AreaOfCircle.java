

import java.util.*;
import java.io.*;

public class AreaOfCircle {
    public static void main(String[] args){
        Scanner sc = new ffScanner(System.in);
        System.out.println("Enter the radius of the circle : ");
        int r = sc.nextInt();
        double area = 3.14*r*r;
        double circumference = 2*(3.14)*(r);
//nahiii yrrr
        System.out.printf("The area and circumference of the circle will be : %.2f & %.2f",area,circumference);

    }
}
