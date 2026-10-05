class MedianFinder {
public:
    priority_queue<int> leftMax; //Left max heap
    priority_queue<int, vector<int>, greater<int>> rightMin; //Right min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMax.empty() || num < leftMax.top()){ //num left max heap ke top se bhi chota hai toh left me push hoga
            leftMax.push(num);
        }
        else{
            rightMin.push(num);
        }

        //Always maintain left max heap one size greater or equal to one of right min heap for finding median for even and odd why that and one size more when odd size then we can directly return leftMax.top()
        if(abs((int)leftMax.size() - (int)rightMin.size()) > 1){ //1 se jayde size nahi ho sakta leftMax ka rightMin se
            rightMin.push(leftMax.top());
            leftMax.pop();
        }
        else if(leftMax.size() < rightMin.size()){
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if(leftMax.size() == rightMin.size()){ //Even length ke case me median
            return (double)(leftMax.top() + rightMin.top()) / 2;
        }
        else{
            return leftMax.top(); //Odd length ke case me median
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */