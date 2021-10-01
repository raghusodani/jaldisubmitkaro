class Median{
    public static void main(String args[]){
        int matrix[][] = {{1,3,5},{2,6,9},{3,6,9}};
        int r=3,c=3,i=0,j=0;
        int t = (r*c+1)/2;
        while(t-- != 0){
            System.out.println(i + " " +j);  
            if(i == r-1){
                i=0;
                j++;
                continue;
            }
            if(j<c-1){
                if(matrix[1][j] <= matrix[0][j+1])
                    i++;
                else
                    j++;
            }
            else
                i++;  
        }
        System.out.println(i + " " + j);
    }
}