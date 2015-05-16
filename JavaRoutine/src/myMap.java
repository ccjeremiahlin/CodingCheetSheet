import java.util.*;

/**
 * Created by Jeremiah on 3/14/15.
 */
public class myMap {
    public void test(){
        TreeMap<Integer, String> idName = new TreeMap<>((a,b)->-a.compareTo(b));
        //add
        for(int i=0;i<10;i++){
            int randNumer = new Random().nextInt(10);
            String oldName = idName.put(randNumer, Character.toString((char) ('a' + randNumer)));
            if(oldName!=null) System.out.println(oldName + " with id: " + i + " is replaced");
        }
        String oldName = idName.put(1, "One");
        if(oldName!=null) System.out.println(oldName+" with id: "+1+" is replaced");

        //loop
        dumpMap("After initialized :", idName);
        //find (key or value) and retrieve
        for(int i=0;i<20;i+=5){
            String name = idName.get(i);
            if(name!=null)System.out.println("Get name of id: "+i+" "+ name);
        }
        //remove
        idName.remove(1);
        dumpMap("After remove index 1: ", idName);
        //headMap(to Key), tailMap(from Key)
        dumpMap("To Key", idName.headMap(5));
        dumpMap("From Key", idName.tailMap(2));
        dumpMap("Sub Map", idName.subMap(5,1));

        //firstKey, lastKey

        //KeySet
        DumpContainer<Set<Integer>> dcKey = new DumpContainer<>();
        dcKey.dump("Key Sets:", idName.keySet());
        //Value Collections
        DumpContainer<Collection<String>> dcValues = new DumpContainer<>();
        dcValues.dump("Value Sets:", idName.values());
/*
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
*/
    }
    public void dumpMap(String msg, Map<?,?> map){
        System.out.println(msg);
        for(Map.Entry<?,?> entry: map.entrySet()){
            System.out.print("Key: "+entry.getKey()+" Value: "+entry.getValue()+" ");
        }
        System.out.println();
    }
}
