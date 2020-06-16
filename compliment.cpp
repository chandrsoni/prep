
int gcd(int a, int b) {
    if ( a <= 0 || b <= 0){return 0;}
    if (a < b) swap(a, b);
    int rem = a%b;
    if(rem == 0) return b;
    return gcd(b, rem);
}

class fraction {
    public:
    int x;
    int y;
    fraction(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    fraction operator+(const fraction& toadd){
        int dividerGcd = gcd(y, toadd.y);
        int myFactor = (y/dividerGcd);
        int toaddFactor = (toadd.y/dividerGcd);
        int divider =  myFactor * toaddFactor * dividerGcd;
        int divident = myFactor * toadd.x + toaddFactor * x;
        return fraction(divident, divider);
    }
    
    fraction operator-(const fraction& toSubstract) {
        int dividerGcd = gcd(y, toSubstract.y);
        int myFactor = (y/dividerGcd);
        int toSubstractFactor = (toSubstract.y/dividerGcd);
        int divider =  myFactor * toSubstractFactor * dividerGcd;
        int divident = toSubstractFactor * x - myFactor * toSubstract.x;
        return fraction(divident, divider);
    }
    
    bool operator== (const fraction& toCompare) {
        bool result = (x == toCompare.x && y == toCompare.y) || (((float)toCompare.x/x) == ((float)toCompare.y/y));
        cout <<"compare " << x << ", " << y << ", " << toCompare.x << ", " << toCompare.y << ", " << result << endl;
        return result;
    }
    
    bool operator< (const fraction& toCompare) {
        if(operator==(toCompare)) return false;
        return ((float)x/y) < ((float)toCompare.x/toCompare.y);
    }
    
    bool operator>(const fraction& toCompare) {
        if(operator==(toCompare)) return false;
        return ((float)x/y) > ((float)toCompare.x/toCompare.y);
    }
};

int hasFraction(vector<fraction>& fractions, int startIndex, fraction toFind) {
    cout << "begin " << startIndex << ", " << toFind.x << ", " << toFind.y << endl;
    if(toFind.x <= 0 || toFind.y <= 0) return 0;
    if(startIndex >= fractions.size()) return 0;
    int hasFractionInclude = toFind == fractions[startIndex] ? 1 : hasFraction(fractions, startIndex + 1, toFind - fractions[startIndex]);
    int hasFractionExclude = hasFraction(fractions, startIndex + 1, toFind);
    cout << "end " << startIndex << ", " << hasFractionExclude <<", " << hasFractionInclude << ", " << toFind.x << ", " << toFind.y << endl;
    return hasFractionExclude + hasFractionInclude;
}


int main () {
    int n, input;
    cin >> n;
    vector<int> x,y;
    for(int i = 0; i < n; i++) {
        cin >> input;
        x.push_back(input);
    }
    for(int i = 0; i < n; i++) {
        cin >> input;
        y.push_back(input);
    }
    
    vector<fraction> fractions;
    for(int i = 0; i < n; i++) {
        fractions.push_back(fraction(x[i], y[i]));
    }
    cout << hasFraction(fractions, 0, fraction(1,1)) << endl;
    cout << "hello world!" << endl;
}