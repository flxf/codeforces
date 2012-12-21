import java.io.*;
import java.util.*;

public class A {
  public static void main(String [] args) throws Exception {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();

    System.out.println(s.replaceAll("\\s*+,", ", ").replaceAll("\\s*+\\.", ". ").replaceAll("\\s*+\\!", "! ").replaceAll("\\s*+\\?", "? ").replaceAll("\\s++", " ").trim());
  }
}
