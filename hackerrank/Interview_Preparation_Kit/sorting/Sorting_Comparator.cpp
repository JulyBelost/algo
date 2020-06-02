//https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if(a.score != b.score) {
            return a.score > b.score ? 1 : -1;
        } else if (a.name != b.name) {
            return a.name < b.name ? 1 : -1;
        } else {
            return 0;
        }
    }
};
