public class unique_xor {
        public static void main(String[] args) {
            int arr[] = {1,2,3,4,1,2,3,4};
            int ans = 0;
            for(int i=0;i<arr.length;i++){
                ans = ans^arr[i];
                System.out.println(ans);
            }
            System.out.println(ans);
        }   
}
