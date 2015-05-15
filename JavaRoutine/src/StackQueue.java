import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class StackQueue {
    public void test(){
        Stack<Integer> s = new Stack<Integer>();
        for(int i=0;i<10;i++){
            s.push(i);
        }
        System.out.println("Stack dump");
        while(!s.empty()){
            System.out.print(s.pop()+" ");
        }
        System.out.println();

        Queue<Integer> q = new ArrayDeque<Integer>();
        for(int i=0;i<10;i++){
            q.offer(i);
        }
        System.out.println("Queue dump");
        while(!q.isEmpty()){
            System.out.print(q.poll()+" ");
        }
        System.out.println();

    }
}
