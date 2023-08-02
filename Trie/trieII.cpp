class Trie{
    class Node {
    public:
        Node *links[26];
        int countEnds= 0;
        int countPrefix= 1;
    };

    Node* root;

    public:
    Trie(){
        root= new Node();
    }

    void insert(string &word){
        Node* temp= root;
        for (char c: word){
            if (!temp->links[c-'a']) temp->links[c-'a']= new Node();
            else temp->links[c-'a']->countPrefix++;
            temp= temp->links[c-'a'];
        }
        temp->countEnds++;
    }

    int countWordsEqualTo(string &word){
        Node* temp= root;
        for (char c: word){
            if (!(temp->links[c-'a']) || temp->countPrefix==0) return 0;
            temp= temp->links[c-'a'];
        }
        return temp->countEnds;
    }

    int countWordsStartingWith(string &word){
        Node* temp= root;
        for (char c: word){
            if (!(temp->links[c-'a']) || temp->countPrefix==0) return 0;
            temp= temp->links[c-'a'];
        }
        return temp->countPrefix;
    }

    void erase(string &word){
        Node* temp= root;
        for (char c: word){
            temp->links[c-'a']->countPrefix--;
            temp= temp->links[c-'a'];
        }
        temp->countEnds--;
    }
};