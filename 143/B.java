import java.util.*;
import java.math.*;

public class B {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();
    boolean neg = s.charAt(0) == '-';
    if (neg) {
      s = s.substring(1);
    }

    String[] t;
    if (s.indexOf('.') == -1) {
      t = new String[2];
      t[0] = s;
      t[1] = "00";
    } else {
      t = s.split("\\.");
      t[1] = t[1] + "00";
    }

    if (neg) {
      System.out.print("(");
    }
    System.out.print("$");

    int m = t[0].length() % 3;
    System.out.print(t[0].charAt(0));
    for (int i = 1; i < t[0].length(); i++) {
      if (i % 3 == m) {
        System.out.print(",");
      }
      System.out.print(t[0].charAt(i));
    }

    System.out.print(".");
    System.out.print(t[1].substring(0, 2));
    if (neg) {
      System.out.print(")");
    }
    System.out.println("");
  }
}
