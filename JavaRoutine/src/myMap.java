import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class myMap {
    public void test(){
        Map<Integer, String> theMap = new HashMap<Integer, String>();
        for(int i=0;i<10;i++){
            String prev = theMap.put(i, Integer.toString(i));
            if(prev==null){
                System.out.print("Put successfully ");
            }else{
                System.out.print("Duplicated ");
            }
        }
        System.out.println();
        System.out.println("Key/Value MapEntry");
        for(Map.Entry<Integer, String> e: theMap.entrySet()){
            System.out.print(" Key: " + e.getKey());
            System.out.print(" Value: "+e.getValue());
        }
        System.out.println(" Key Set");
        for(Integer key: theMap.keySet()){
            System.out.print(" Key: "+key.toString());
        }
        System.out.println(" Value Set");
        for(String value: theMap.values()){
            System.out.print(" Value: "+value);
        }
        System.out.println("Contains key 10? "+ theMap.containsKey(10));
        System.out.println("Contains value 8? "+ theMap.containsValue("8"));

        TreeMap<Integer, String> treeMap = new TreeMap<>(theMap);
        System.out.println(treeMap.headMap(5).toString());
        System.out.println(treeMap.tailMap(5).toString());
    }
}
