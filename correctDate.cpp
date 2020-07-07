bool isValidDay(int month, int day) {
    switch(month) {
        case 1:
            return day <= 31;
        case 2:
            return day <= 28;
        case 3:
            return day <= 31;
        case 4:
            return day <= 30;
        case 5:
            return day <= 31;
        case 6:
            return day <= 30;
        case 7:
            return day <= 31;
        case 8:
            return day <= 31;
        case 9:
            return day <= 30;
        case 10:
            return day <= 31;
        case 11:
            return day <= 30;
        case 12:
            return day <= 31;
    }
    return false;
}

int main() {
    int inputs[3];
    cin >> inputs[0] >> inputs[1] >> inputs[2];
    sort(inputs, inputs + 3);
    cout << inputs[0] << ", " << inputs[1] << ", " << inputs[2] << endl;
    cout << ((inputs[0] <= 12 && inputs[0] > 0) && (isValidDay(inputs[0],inputs[1])) && (inputs[2] >= 0)) << endl;
    std::cout << "Hello World!\n";
}