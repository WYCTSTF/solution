import java.util.*;

public class setTrial {
	public static void main(String[] args) {
		HashSet<Integer> Sets=new HashSet<Integer>();
		int[] ary1 = new int[]{1,1,4,5,1,4,1,9,1,9,8,1,0};
		// for (int it : ary) { System.out.println(it); }
		for (int it:ary1) {
			Sets.add(it);
		}
		Integer ary2[] = new Integer[Sets.size()];
		Sets.toArray(ary2);
		for (var it : ary2) {
			System.out.printf("%d ", it);
		}
	}
}
