import java.util.*;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class mySet {
    public void test(){
        //init hash set
        Set<Integer> s = new HashSet<>();
        //add
        for(int i=0;i<10;i++) s.add(new Random().nextInt(100));
        //iterate
        DumpContainer<Set<Integer>> dc = new DumpContainer<>();
        dc.dump("Hash Set: ", s);
        //init tree set with reverse order
        TreeSet<Integer> trees = new TreeSet<>((a,b)->b.compareTo(a));
        trees.addAll(s);
        dc.dump("Tree Set: ", trees);
        //first, last
        trees.remove(trees.first());
        trees.remove(trees.last());
        dc.dump("Tree Set after remove head and tail: ", trees);
        //subSet
        dc.dump("Sub Set: ", trees.subSet(90, 10));
        //headSet
        dc.dump("Head Set:", trees.headSet(3));
        //tailSet
        dc.dump("Tail Set:", trees.tailSet(50));
/*
        Set<Integer> s = new HashSet<Integer>();
        for(int i=0;i<10;i++){
            s.add(i);
        }
        System.out.println("Whole Set");
        for(int i: s){
            System.out.print(i+" ");
        }
        TreeSet<Integer> treeSet = new TreeSet<>(s);
        System.out.println("\nHead Subset");
        treeSet.headSet(treeSet.size()/2).stream().forEach((a)->System.out.print(a+" "));
        System.out.println("\nTail Subset");
        treeSet.tailSet(treeSet.size()/2).stream().forEach((a)->System.out.print(a+" "));

        System.out.println("Contains 3? "+s.contains(3));
*/
    }
}
