import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


 class Node implements Comparator<Node> {
    public int idx, cost;
    public Node () {}
    public Node(int _idx, int _cost) {
        idx = _idx;
        cost = _cost;
    }

    @Override
    public int compare(Node n1, Node n2) {
       if(n1.cost > n2.cost) {
           return 1;
       }
       if(n1.cost < n2.cost) {
           return -1;
       }
       return 0;
    }
}
public class Paytolls {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int S = sc.nextInt(), E = sc.nextInt();

        int m = sc.nextInt();
        ArrayList<Node>[] graph = new ArrayList[N + 5];
        for(int i = 0; i < N; i++) {
            graph[i] = new ArrayList<Node>();
        }
        for(int i =0 ; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            a--;
            b--;
            graph[a].add(new Node(b, c));
            graph[b].add(new Node(a, c));
        }
        int[] dist = new int[N];
        boolean[] visited = new boolean[N];
        for(int i = 0; i < N; i++) {
            dist[i] = (int) 2e9;
            visited[i] = false;
        }
        S--;
        E--;
        dist[S] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>(N, new Node());
        pq.add(new Node(S, 0));
        while(!pq.isEmpty()) {
            Node c = pq.remove();

            if(visited[c.idx]) continue;
//            System.out.println(c.idx + 1 + " " + c.cost);
            visited[c.idx] = true;

            for(int i = 0; i < graph[c.idx].size(); i++) {
                int neigh = graph[c.idx].get(i).idx;
                int cost = graph[c.idx].get(i).cost;

                if(!visited[neigh] && cost + c.cost < dist[neigh]) {
                    dist[neigh] = cost + c.cost;
                    pq.add(new Node(neigh, dist[neigh]));
                }
            }
        }
        System.out.println(dist[E]);

    }
}
