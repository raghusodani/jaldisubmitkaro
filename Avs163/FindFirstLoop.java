public class FindFirstLoop {
    static Node head = null;
    static class Node{
        Node next;
        int data;
        Node(int d){
            data = d;
            next = null;
        }
    }
    public void insert(int d){
        Node curr = head;
        Node new_node = new Node(d);
        if(head == null){
            head = new_node;
            return;
        }
        while(curr.next != null)
            curr = curr.next;
        curr.next = new_node;
    }

    public void print(){
        Node curr = head;
        while(curr != null){
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
    }
    public Node detectAndRemoveLoop(){
        Node slow = head;
        Node fast = head;
        while(slow != null && fast.next != null && fast != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                break;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow.next;
            fast = fast.next;
          }
 
        return slow;
    }
    public static void main(String[] args) {
      FindFirstLoop list = new FindFirstLoop();
      list.insert(15);
      list.insert(20);
      list.insert(15);
      list.insert(4);
      list.insert(10);
      list.head.next.next.next.next.next = list.head;
      Node res = list.detectAndRemoveLoop();
      System.out.print(res.data);
    }
}
