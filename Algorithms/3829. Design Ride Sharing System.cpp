class RideSharingSystem {
private:
    set<int> haveRider;
    queue<int> qRider;
    queue<int> qDriver;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        haveRider.insert(riderId);
        qRider.push(riderId);
    }

    void addDriver(int driverId) {
        qDriver.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        // available riders, lazy check as they might have cancelled 
        while (!qRider.empty() &&
               haveRider.find(qRider.front()) == haveRider.end()) {
            qRider.pop();
        }
        if (qRider.empty() || qDriver.empty())
            return {-1, -1};
        int rider = qRider.front(), driver = qDriver.front();
        qRider.pop(); qDriver.pop(); haveRider.erase(rider);
        return {driver, rider};
    }

    void cancelRider(int riderId) {
        haveRider.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */