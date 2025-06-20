class Solution {
public:

    int count(int d1, int d2, int times){
        return abs(d1-d2) + times*2;
    }

    int maxDistance(string ss, int k) {
        int n = 0, s = 0, e = 0, w = 0;
        int distance = 0;
        for (char c : ss){
            if (c == 'N') n++;
            if (c == 'S') s++;
            if (c == 'E') e++;
            if (c == 'W') w++;

            int ns = min({n, s, k});
            int ew = min({e, w, k-ns});
            distance = max({
                distance, 
                count(n, s, ns) + count(e, w, ew)
            });
            // int temp = k;
            // temp -= ns;
            // distance += max(n, s) + ns;
            // // ew 
            // distance += max(e, w) + ew;
        }
        // cout << n << " " << s << " "<< e << " " << w << endl;
        return distance;

        // NE NW SE SW 
        // vector<char> dir = {'NE', 'e', 'w', 's'};
        // for (char )
        

        // between the max and min of NS, EW 
        // N/S change to one direction 
        // E/W change to one direction 
        // all to NE if EW
        // int to_north = min(s, k);
        // s -= to_north;
        // n += to_north;
        // k -= to_north;
        // // all to East 
        // int to_east = min(w, k);
        // e += to_east;
        // w -= to_east;
        // cout << n << " " << e << endl;
        // cout << n << " " << s << " "<< e << " " << w << endl;
        // return abs(n-s) + abs(e-w);

        // n e 
        // s w 
        // int helper1 = min(s+w, k);
        // int helper2 = min(n+e, k);
        // int distance = abs(n-s) + abs(e-w);
        // distance = max(distance+helper1, distance+helper2);
        // return distance;
    }
};