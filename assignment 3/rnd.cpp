#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

 std::vector <int> eccentricity  (std::vector <std::vector <int>>&);
 void rnd (std::vector <int> &);

 int main(int argc, char const *argv[]) {

     int edg = 0, ver = 0, u, v;
     std::vector <int> E;

     std::cout << "\n\n\t Enter the number of vertices and edges in the graph :";
     std::cin >> ver >> edg;

     std::vector <std::vector <int>> G (ver, std::vector <int> (0));

     //std::cout << G [0].size () << '\n';

     std::cout << "\n\t Enter the vertex pair between which an edge exists :" << '\n';

     for (int i = 0; i < edg; i++) {
         std::cin >> u >> v;
         u--;
         v--;
         G [u].push_back (v);
         G [v].push_back (u);
     }

     //std::cout << G [2].size () << '\n';

     E = eccentricity (G);
     rnd (E);

     return 0;
 }

 std::vector <int> eccentricity (std::vector <std::vector <int>> &g) {

     int ecc = 0, t = 0, v;
     std::queue <int> q, temp;
     std::vector <int> E (g.size ());

     for (int i = 0; i < g.size (); i++) {

         ecc = 0;
         std::vector <bool> check (g.size (), 0);

         check [i] = 1;
         for (int j = 0; j < g [i].size (); j++) {
             q.push (g [i][j]);
             check [g [i][j]] = 1;
         }

         while (!q.empty ()) {

             temp = q;
             t = temp.size ();

             while (t--) {

                     v = temp.front ();
                     temp.pop ();

                     for (int l = 0; l < g [v].size (); l++) {
                         if (!check [g [v][l]]) {
                             q.push (g [v][l]);
                             check [g [v][l]] = 1;
                         }
                     }

                     q.pop ();
                 }
             ecc++;
         }

         E [i] = ecc;
     }

     return E;
 }

 void rnd (std::vector <int> &e) {

     std::cout << "\n\n\t Radius : " << *std::min_element (e.begin (), e.end ()) << '\n';
     std::cout << "\t Diameter : " << *std::max_element (e.begin (), e.end ()) << '\n';
 }
