// Silver 2 Solution - Jan 2021
// Link to Contest - http://www.usaco.org/index.php?page=viewproblem2&cpid=1087

import java.io.*;
import java.util.*;

public class File_Reading {

public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer token = new StringTokenizer(reader.readLine());
			int num = Integer.parseInt(token.nextToken());
			int count = Integer.parseInt(token.nextToken());
			token = new StringTokenizer(reader.readLine());
			String str = token.nextToken();
			ArrayList<Integer> leftSide = sol(str);
			StringBuilder input1 = new StringBuilder();
			input1.append(str);
			input1.reverse();
			ArrayList<Integer> rightSide = sol(input1.toString());
			Collections.reverse(rightSide);
			for (int i = 0; i < count; i++) {
				token = new StringTokenizer(reader.readLine());
				int leftParam = Integer.parseInt(token.nextToken()), rightParam = Integer.parseInt(token.nextToken());
				if (leftParam == 1 && rightParam == num) {
					System.out.println("0");
				} else if (leftParam == 1) {
					System.out.println(rightSide.get(rightParam));
				} else if (rightParam == num) {
					System.out.println(leftSide.get(leftParam - 2));
				} else {
					System.out.println(leftSide.get(leftParam - 2) + rightSide.get(rightParam));
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static ArrayList<Integer> sol(String str) {
		ArrayList<Integer> sol = new ArrayList<Integer>();
		for (int i = 0; i < str.length(); i++) {
			sol.add(0);
		}
		boolean[] distinct = new boolean[26];
		Arrays.fill(distinct, true);
		sol.set(0, 1);
		distinct[str.charAt(0) - 'A'] = false;
		for (int i = 1; i < str.length(); i++) {
			sol.set(i, sol.get(i - 1));
			if (str.charAt(i) < str.charAt(i - 1)) {
				int c = str.charAt(i) - 'A' + 1;
				for (; c < distinct.length; c++) {
					distinct[c] = true;
				}
			}

			if (distinct[str.charAt(i) - 'A']) {
				sol.set(i, sol.get(i) + 1);
			}

			distinct[str.charAt(i) - 'A'] = false;
		}
		return sol;
	}
}
