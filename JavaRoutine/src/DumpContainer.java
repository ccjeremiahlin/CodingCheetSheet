import java.util.Collection;

/**
 * Created by Jeremiah on 5/15/15.
 */
public class DumpContainer<E extends Collection<? extends Object>> {
    void dump(E c) {
        System.out.println(c.getClass().toString() + " : ");
        for(Object o : c){
            System.out.print(o+" ");
        }
        System.out.println();
    }
    void dump(String s, E c){
        System.out.print(s+" ");
        this.dump(c);
    }
}
