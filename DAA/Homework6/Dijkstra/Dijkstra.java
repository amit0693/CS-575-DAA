import java.lang.*;
import java.util.*;
public class Dijkstra
{
    int numNodes = 7;
    String[] letters = {Character.toString('t'),Character.toString('u'),Character.toString('v'),Character.toString('w'),Character.toString('x'),Character.toString('y'),Character.toString('z')};
    int findMinimumDistance(int D[],Set<Integer> visitedNodes)
    {
        int minimum = Integer.MAX_VALUE, min_index=-1;
        int i = 0;
        while(i<numNodes)
        {
            Boolean b = (D[i]<=minimum && !visitedNodes.contains(i)) ? true : false;
            if(b)
            {
                minimum = D[i];
                min_index=i;
            }
            i++;
        }
        return min_index;
    }
    void dijkstra(int adj_matrix[][],int src)
    {
        System.out.println("Source --> " + letters[src]);
        System.out.println();
        Set<Integer> nPrimeNodes = new HashSet<>();
        nPrimeNodes.add(src);
        int distance[] = new int[adj_matrix.length];
        int linkTo[] = new int[adj_matrix.length];

        System.out.print("Step\t\tNodes\t\t");
        for (int i = 0;i<numNodes;i++) {
            if (i == src) continue;

            System.out.print(String.format("%d\t\t", i));
        }
        System.out.println();
        int stepNum = 0;
        for(int i = 0; i<numNodes; i++)
        {
          Boolean bo = adj_matrix[src][i] < Integer.MAX_VALUE ? true : false;
            if (bo) {
                distance[i] = adj_matrix[src][i];
                linkTo[i] = i;
            } else {
                distance[i]=Integer.MAX_VALUE;
            }
        }
        System.out.print(stepNum + "\t\t\t" + letters[src] + "\t\t\t");
        int k = 0;
        while (k<numNodes) {
            if (k == src) k++;
            String nodeDistance = "";
            nodeDistance = (distance[k] == Integer.MAX_VALUE) ? "MAX" : String.valueOf(distance[k]);
            System.out.print(String.format("%5s,%2s", nodeDistance, letters[(linkTo[k])] + "       "));
            k++;
        }
        System.out.println();
        String result = letters[src];
        do {
            int minVertexIndex =findMinimumDistance(distance, nPrimeNodes);
            nPrimeNodes.add(minVertexIndex);
            result += letters[minVertexIndex];
            int l = 0;
            while(l < numNodes) {
              Boolean b = (!nPrimeNodes.contains(l) && adj_matrix[minVertexIndex][l]!=Integer.MAX_VALUE) ? true : false;
                if (b) {
                    Boolean boo = (distance[l] > distance[minVertexIndex]+adj_matrix[minVertexIndex][l]) ? true : false;
                    if (boo) {
                        distance[l] = distance[minVertexIndex]+adj_matrix[minVertexIndex][l];
                        linkTo[l] = minVertexIndex;
                    }
                }
                l++;
            }
            stepNum++;
            System.out.print(stepNum + "\t\t\t" + result + "\t\t\t");
            for (int i = 0;i<numNodes;i++) {
                if (i == src) continue;
                String nodeDistance = "";
                nodeDistance = (distance[i] == Integer.MAX_VALUE) ? "MAX" : String.valueOf(distance[i]);
                System.out.print(String.format("%5s,%2s", nodeDistance, letters[(linkTo[i])] + "       "));
            }
            System.out.println();

        } while (nPrimeNodes.size() != numNodes);
    }
    public static void main(String [] args)
    {
        int adj_matrix[][]=new int[][]{
                { 0, 2, 4, Integer.MAX_VALUE, Integer.MAX_VALUE, 7, Integer.MAX_VALUE},
                { 2, 0, 3, 3,Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE},
                { 4, 3, 0, 4, 3, 8, Integer.MAX_VALUE},
                { Integer.MAX_VALUE, 3, 4, 0, 6, Integer.MAX_VALUE, Integer.MAX_VALUE},
                { Integer.MAX_VALUE, Integer.MAX_VALUE, 3, 6, 0, 6, 8},
                { 7, Integer.MAX_VALUE, 8, Integer.MAX_VALUE, 6, 0, 12},
                { Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 8, 12, 0} };
        Dijkstra d = new Dijkstra();
        System.out.println("\n**********Initial Adjacency Matrix**********n");
        for(int i = 0; i<7; i++)
        {
          for(int j=0;j<7;j++)
          {
            if(adj_matrix[i][j] == Integer.MAX_VALUE)
            {
              System.out.printf("%d\t\t",999);
            }
            else
            {
              System.out.printf("%d\t",adj_matrix[i][j]);
            }
          }
          System.out.println();
        }
        System.out.println();
        d.dijkstra(adj_matrix,0);
    }
}
