//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    
    LRUCache(int cap) {
        capacity = cap;
    }

    
    int get(int key) {
        
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        
        auto it = cache[key];
        dll.splice(dll.begin(), dll, it);

        return it->second; // Return the value
    }

   
    void put(int key, int value) {
        
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            it->second = value; 
            dll.splice(dll.begin(), dll, it);
            return;
        }

       
        if (dll.size() == capacity) {
            auto lru = dll.back();
            cache.erase(lru.first); 
            dll.pop_back();
        }

        
        dll.emplace_front(key, value);
        cache[key] = dll.begin(); 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends