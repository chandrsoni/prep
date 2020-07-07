
    double distancesquare(vector<int>& p1, vector<int>& p2) {
        return pow((double)p2[0]-p1[0], 2) + pow((double)(p2[1] - p1[1]), 2);
    }
    bool areValidDistances(double distances[3]) {
        sort(distances, distances + 3);
        return distances [0] == distances[1] && distances[2] == 2 * distances[1];
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double distances[3];
        distances[0] = distancesquare(p1, p2);
        distances[1] = distancesquare(p1, p3);
        distances[2] = distancesquare(p1, p4);
        if(!areValidDistances(distances)) return false;
        distances[0] = distancesquare(p2, p1);
        distances[1] = distancesquare(p2, p3);
        distances[2] = distancesquare(p2, p4);
        if(!areValidDistances(distances)) return false;
        distances[0] = distancesquare(p3, p1);
        distances[1] = distancesquare(p3, p2);
        distances[2] = distancesquare(p3, p4);
        if(!areValidDistances(distances)) return false;
        distances[0] = distancesquare(p1, p4);
        distances[1] = distancesquare(p2, p4);
        distances[2] = distancesquare(p3, p4);
        return areValidDistances(distances);
    }

int main () {
    vector<int> p1(2);
    vector<int> p2(2);
    vector<int> p3(2);
    vector<int> p4(2);
    cin >> p1[0] >> p1[1];
    cin >> p2[0] >> p2[1];
    cin >> p3[0] >> p3[1];
    cin >> p4[0] >> p4[1];
    cout << validSquare(p1, p2, p3, p4) << endl;
    cout << "hello world" << endl;
}