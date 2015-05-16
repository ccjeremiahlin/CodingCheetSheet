import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class myList {
    public void test(){
        List<Integer> theList = new LinkedList<Integer>();
        //add
        for(int i=0;i<10;i++)theList.add(new Random().nextInt(100));
        DumpContainer<List<Integer>> dc = new DumpContainer<>();
        dc.dump("After random generated: ", theList);
        //remove
        //remove index
        Integer index3 = theList.remove(3);
        dc.dump("After remove index 3", theList);
        //remove object
        boolean index5Exist = theList.remove(theList.get(5));
        dc.dump("After remove index 5", theList);
        //sort
        theList.sort(Integer::compareTo);
        dc.dump("After sorted (Natural Order)", theList);
        theList.sort((a,b)->-a.compareTo(b));
        dc.dump("After sorted (Reversed Order)", theList);
        //contains
        assert(theList.contains(theList.get(0)));
        //indexOf (find)
        assert(theList.indexOf(theList.get(1))==1);
        //lastIndexOf (find)
        //sublist
        dc.dump("Sublist from 2~5: ", theList.subList(2, 5));
    }
}
