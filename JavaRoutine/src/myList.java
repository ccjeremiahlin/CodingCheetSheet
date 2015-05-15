import java.util.LinkedList;
import java.util.List;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class myList {
    public void test(){
        List<Integer> theList = new LinkedList<Integer>();
        for(int i=0;i<10;i++){
            theList.add(i);
        }
        System.out.println("Before Remove");
        for(int i : theList){
            System.out.print(i+" ");
        }
        System.out.println();
        System.out.println("After Remove");
        theList.removeIf((a)->a<3);
        for(int i : theList){
            System.out.print(i+" ");
        }
        System.out.println("contains 2? "+theList.contains(2)+" index of 5: "+theList.indexOf(5));

    }
}
