import java.util.PriorityQueue;
import java.util.Random;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class MyPriorityQueue {
    public void test(){
        //init priority queue with natural order
        PriorityQueue<Integer> pqNatural = new PriorityQueue<>();
        for(int i=0;i<10;i++)pqNatural.add(new Random().nextInt(100));
        DumpContainer<PriorityQueue<Integer>> dc = new DumpContainer<>();
        dc.dump("Natural Order Priority Queue: ", pqNatural);
        //init priority queue with reverse order
        PriorityQueue<Integer> pqReverse = new PriorityQueue<>((a,b)->b.compareTo(a));
        pqReverse.addAll(pqNatural);
        dc.dump("Reverse Order Priority Queue:", pqReverse);
        //iterate? yes.

        //pop all
        while(!pqNatural.isEmpty()) {
            System.out.println(pqNatural.poll());
        }
/*
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->Integer.compare(b,a));
        for(int i=0;i<10;i++){
            pq.offer(Math.abs((new Random()).nextInt(1024)));
        }
        System.out.println("Poping");
        while(pq.size()>0){
            System.out.print(pq.poll()+" ");
        }
*/
    }
}
