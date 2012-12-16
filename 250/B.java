import java.util.*;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();

    for (int i = 0; i < n; i++) {
      String ans = "";
      String s = in.next();
      if (s.startsWith("::")) {
        s = s.replace("::", "A:");
      } else if (s.endsWith("::")) {
        s = s.replace("::", ":A");
      } else if (s.indexOf("::") != -1) {
        s = s.replace("::", ":A:");
      }

      String[] tokens = s.split(":");
      //System.out.println(tokens.length);
      for (int j = 0; j < tokens.length; j++) {
        if (tokens[j].equals("A")) {
          for (int k = 0; k < 8 - tokens.length + 1; k++) {
            ans += "0000:";
            //System.out.print("0000:");
          }
          continue;
        }

        if (tokens[j].length() == 4) {
          ans += tokens[j] + ":";
          //System.out.print(tokens[j] + ":");
        } else if (tokens[j].length() > 0) {
          for (int k = 0; k < 4 - tokens[j].length(); k++) {
            ans += "0";
            //System.out.print("0");
          }
          ans += tokens[j] + ":";
          //System.out.print(tokens[j] + ":");
        }
      }

      System.out.println(ans.substring(0, ans.length() - 1));
      //System.out.println();
    }
  }
}
