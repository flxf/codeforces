import java.io.*;
import java.util.*;

public class B {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();

    String protocol = "";
    if (s.startsWith("http")) {
      protocol = "http";
      s = s.substring(4);
    } else {
      protocol = "ftp";
      s = s.substring(3);
    }

    int pos = s.lastIndexOf("ru");
    String ans = protocol + "://" + s.substring(0, pos) + ".ru/" + s.substring(pos + 2);
    if (ans.charAt(ans.length() - 1) == '/') {
      ans = ans.substring(0, ans.length() - 1);
    }
    System.out.println(ans);
  }
}
