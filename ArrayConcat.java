import java.util.*;

class Solution{
    public static int doUnion(int a[], int n, int b[], int m)
    {
        List<Integer> list = new ArrayList(Arrays.asList(a));
        List<Integer> list1 = new ArrayList(Arrays.asList(b));
        List<Integer> c = new ArrayList<>(list);
        c.addAll(list);
        c.addAll(list1);
        System.out.println(c);
        Set<Integer> s = new HashSet<>(c);
        return s.size();
    }
}

