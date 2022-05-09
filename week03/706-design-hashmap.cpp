// https://leetcode.com/problems/design-hashmap/

// Time Complexity - O(1)
// Memory Complexity - O(N) 

class MyHashMap {
public:
    int v[1000001];
    MyHashMap() {
       for(long int i = 0; i <= 1000000; i++) {
           v[i] = -1;
       } 
    }
    
    void put(int key, int value) {
        v[key] = value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */