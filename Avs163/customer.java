import java.util.*;
class Customer{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        System.out.println(runCustomerSimulation(n,s));
    }
    public static int runCustomerSimulation(int n, String s){
        HashSet<Character> hash = new HashSet<>();
        for(char ch : s.toCharArray()){
            if(hash.contains(ch))
                n++;
            else{
                hash.add(ch);
                n--;
            }    
        }
        return n;
    }
}