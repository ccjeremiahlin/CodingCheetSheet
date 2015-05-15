import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class mySet {
    public void test(){
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

    }
}
