 // daa 2   
//Title :- Write a program to implement Huffman Encoding using a greedy strategy 

#include <iostream> 
#include <queue> 
#include <vector>
#include <unordered_map> 
using namespace std;

struct Node { 
    char ch; 
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
      left = right = nullptr;
      this->ch = ch;
      this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(struct Node* root, string str) { 
    
    if (!root){
    return;
    }

    if (root->ch != '$'){
    cout << root->ch << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");

}

void HuffmanCodes(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    priority_queue<Node*, vector<Node*>, compare> minHeap; 
    
    for (int i = 0; i < size; ++i){
        minHeap.push(new Node(data[i], freq[i])); 
    }
    
    while (minHeap.size() != 1) {
        left = minHeap.top(); minHeap.pop();

        right = minHeap.top(); minHeap.pop();
        top = new Node('$', left->freq + right->freq); top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]); 
    HuffmanCodes(arr, freq, size);
    
    return 0;
}

