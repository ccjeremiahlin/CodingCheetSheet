import java.util.PriorityQueue;
import java.util.Random;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class MyPriorityQueue {
    public void test(){
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->Integer.compare(b,a));
        for(int i=0;i<10;i++){
            pq.offer(Math.abs((new Random()).nextInt(1024)));
        }
        System.out.println("Poping");
        while(pq.size()>0){
            System.out.print(pq.poll()+" ");
        }
    }
}
