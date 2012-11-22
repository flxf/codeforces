import java.util.*;

public class A {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();
    s = s.replaceAll("WUB", " ");
    s = s.replaceAll("\\s+", " ");
    s = s.trim();
    System.out.println(s);
  }
}
