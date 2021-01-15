
int main () {
    string a, b;
    cin >> a >> b;
    int result = a.size() + b.size();
    for(int i = 0; i < min(a.size(), b.size());i++) {
        if(a[i] != b[i]){
            break;
        }
        else {
            result-=2;
        }
    }
    cout <<  result << endl;
}