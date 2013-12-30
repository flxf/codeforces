import java.io.*;
import java.util.*;

public class C {
  static class Tree {
    int type;
    Tree left;
    Tree right;
  }

  static int PAIR = 0;
  static int INT = 1;
  static int OPENPAIR = 2;

  static void PRINT(Tree node) {
    if (node.type == PAIR) {
      System.out.print("pair<");
      PRINT(node.left);
      System.out.print(",");
      PRINT(node.right);
      System.out.print(">");
    } else {
      System.out.print("int");
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());

    String[] tokens = in.readLine().split(" ");
    if (tokens.length != n + n - 1) {
      System.out.println("Error occurred");
      return;
    }

    Tree root = null;
    LinkedList<Tree> stk = new LinkedList();
    for (int i = 0; i < tokens.length; i++) {
      //for (int j = 0; j < stk.size(); j++) {
        //System.out.print(stk.get(j).type + " ");
      //}
      //System.out.println();

      Tree node = new Tree();
      if (tokens[i].equals("int")) {
        if (stk.size() == 0) {
          node.type = INT;
          stk.offerLast(node);
        } else if (stk.getLast().type == OPENPAIR) {
          node.type = INT;
          stk.offerLast(node);
        } else {
          if (stk.size() < 2 || stk.get(stk.size() - 2).type != OPENPAIR) {
            //System.out.println("Error occurred:" + stk.get(stk.size() - 2).type);
            System.out.println("Error occurred");
            return;
          }

          node.type = INT;
          stk.offerLast(node);

          while (stk.size() > 2 && stk.get(stk.size() - 2).type != OPENPAIR && stk.get(stk.size() - 3).type == OPENPAIR) {
            Tree r = stk.pollLast();
            Tree l = stk.pollLast();
            Tree cp = stk.pollLast();

            cp.left = l;
            cp.right = r;
            cp.type = PAIR;
            stk.offerLast(cp);
            //System.out.println("HERE");
          }
        }
      } else {
        node.type = OPENPAIR;
        stk.offerLast(node);
      }
    }

    if (stk.size() != 1) { // Probably unnecessary
      System.out.println("Error occurred");
      //System.out.println("Error occurred2");
      return;
    }

    PRINT(stk.getFirst());
    System.out.println();
  }
}
