import java.util.*;

public class A {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();
    int[] map = new int[26];
    for (int i = 0; i < 26; i++) {
      map[i] = 0;
    }
    for (int i = 0; i < s.length(); i++) {
      map[s.charAt(i) - 'a'] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      cnt += map[i];
    }

    //System.out.println(cnt);
    if (cnt % 2 == 0) {
      System.out.println("CHAT WITH HER!");
    } else {
      System.out.println("IGNORE HIM!");
    }
  }
}
