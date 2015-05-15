import java.util.*;

import static java.util.Collections.sort;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class myDqeue {
    public void test(){
        DumpContainer<Deque<Integer>> dc = new DumpContainer<>();
        Deque<Integer> dq = new ArrayDeque<Integer>();
        //init with value (no faster way??....)
        //add
        for(int i=0;i<10;i++) dq.add(i);
        for(int i=10;i<20;i++) dq.addFirst(i);
        dc.dump("After add", dq);
        //remove
        dq.removeIf((a)->a<10);
        dc.dump("After remove a<10", dq);
        dq.removeFirst();
        dq.removeLast();
        dc.dump("After remove head and tail", dq);
    }
}
