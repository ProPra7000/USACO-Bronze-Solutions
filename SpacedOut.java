//Silver 3 Solution - Jan 2021
//Link to Problem - http://www.usaco.org/index.php?page=viewproblem2&cpid=1088

import java.io.*;
import java.util.*;
public class USACO {
	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer token = new StringTokenizer(reader.readLine());
			int num = Integer.parseInt(token.nextToken());
			ArrayList<ArrayList<Integer>> photoMatrix = new ArrayList<>();
			for(int i = 0; i < num; i++)
			{
				photoMatrix.add(new ArrayList<Integer>());
				for(int j = 0; j < num; j++)
				{
					photoMatrix.get(i).add(0);
				}
			}
			
			for(int i = 0; i < num; i++)
			{
				token = new StringTokenizer(reader.readLine());
				for(int j = 0; j < num; j++)
				{
					int pValue = Integer.parseInt(token.nextToken());
					photoMatrix.get(i).set(j, pValue);
				}
			}
		    
		    System.out.println(sol(photoMatrix, num));

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	static long sol(ArrayList<ArrayList<Integer>> photoMatrix, int num) {
		long horizontalAnswer = 0;
		for(int i = 0; i < num; i++)
		{
			long sumOfOdds = 0, sumOfEvens = 0;
			for(int j = 0; j < num; j++)
			{
				if(j % 2 == 0)
				{
					sumOfEvens += photoMatrix.get(i).get(j);
				} else
				{
					sumOfOdds += photoMatrix.get(i).get(j);
				}
			}
			horizontalAnswer += Math.max(sumOfOdds, sumOfEvens);
		}
		
		long verticalAnswer = 0;
	    for (int i = 0; i < num; i++) {
	        long sumOfOdds = 0, sumOfEvens = 0;
	        for (int j = 0; j < num; ++j) {
	            if (j % 2 == 0) {
	                sumOfEvens += photoMatrix.get(j).get(i);
	            } else {
	                sumOfOdds += photoMatrix.get(j).get(i);
	            }
	        }
	        verticalAnswer += Math.max(sumOfOdds, sumOfEvens);
	    }
	    return Math.max(verticalAnswer, horizontalAnswer);
	}
}
