class LRUCache {
public:
    // Node structure for doubly linked list
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node);
            addToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* existing = cache[key];
            removeNode(existing);
            delete existing;
            cache.erase(key);
        }

        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addToFront(newNode);
        cache[key] = newNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */