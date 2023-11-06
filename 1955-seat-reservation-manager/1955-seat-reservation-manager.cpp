class SeatManager {
public:
    // time: O(nlogn)
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) unreserved_seats.push(i);
    }
    
    // time: O(logn)
    int reserve() {
        if (unreserved_seats.empty()) return NULL;
        int seat = unreserved_seats.top();
        unreserved_seats.pop();
        return seat;
    }
    
    // time: O(logn)
    void unreserve(int seatNumber) {
        unreserved_seats.push(seatNumber);
    }
private:
    // space: O(n)
    priority_queue<int, vector<int>, greater<int>> unreserved_seats;
};