using namespace std;
#include "node.cpp"
#include "data.cpp"
#include <vector>

template<typename T>
class BinarySearchTree {
private:
   Node<T>* root;
   int numberOfElements;
   int height;

public:

    BinarySearchTree(T* value) {
        root = new Node<T>(value);
        numberOfElements = 1;
        height = 1;

    }

    ~BinarySearchTree() {
        desctructHelp(root);
    }

    int getnumberOfElements() {
        return numberOfElements;
    }

    void desctructHelp(Node<T>* temp) {
        if (temp) {
            desctructHelp(temp->get_left());
            desctructHelp(temp->get_right());
            delete temp;
        }
    }

    void insertElement(T* data) {
        if (root == nullptr) {
            root = new Node<T>(data);
            return;
        }
        insertTraverse(data, root);
        numberOfElements++;

    }

    void insertTraverse(T* data, Node<T>* node) {
        if (node->get_data()->get_value() > data->get_value()) {
            if (node->get_left() == nullptr) {
                node->set_left(new Node<T>(data));
            }
            insertTraverse(data, node->get_left());
        }
        if (node->get_data()->get_value() < data->get_value()) {
            if (node->get_right() == nullptr) {
                node->set_right(new Node<T>(data));
            }
            insertTraverse(data, node->get_right());
        }
    }

    bool elementExists(T* value) {
        vector<T*> inorder;
        inorderTraversal(root, inorder);
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i]->get_value() == value->get_value()) {
                return true;
            }
        }
        return false;
    }


    void deleteElement(T* data) {
        bool exists = elementExists(data);
        if (exists) {
            root = deleteElementHelper(root, data);
            numberOfElements--;
            return;
        }

        cout << "Number does not exist" << endl;
    }

    Node<T>* deleteElementHelper(Node<T>* node, T* data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (data->get_value() < node->get_data()->get_value()) {
            node->set_left(deleteElementHelper(node->get_left(), data));
        }
        else if (data->get_value() > node->get_data()->get_value()) {
            node->set_right(deleteElementHelper(node->get_right(), data));
        }
        else {
            if (node->get_left() == nullptr && node->get_right() == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->get_left() == nullptr) {
                Node<T>* temp = node->get_right();
                delete node;
                return temp;
            }
            else if (node->get_right() == nullptr) {
                Node<T>* temp = node->get_left();
                delete node;
                return temp;
            }
            else {
                Node<T>* maxNode = findMax(node->get_left());
                node->set_data(maxNode->get_data());
                node->set_left(deleteElementHelper(node->get_left(), maxNode->get_data()));
            }

        }

        return node;
    }

    Node<T>* findMax(Node<T>* node) {
        while (node->get_right() != nullptr) {
            node = node->get_right();
        }
        return node;
    }


    void print() {
        preordertraversal(root);
        cout << endl;
    }

    void preordertraversal(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        if (node != root) {
            cout << ", ";
        }
        node->print();

        preordertraversal(node->get_left());
        preordertraversal(node->get_right());
    }

    void findKthElement(int k) {
        vector<T*> inorder;
        inorderTraversal(root, inorder);
        if (k >= 1 && k - 1 < inorder.size()) {
            inorder[k - 1]->print();
            cout << endl;
        } else {
           cout << "Number does not exist" << endl;
        }

    }

    void inorderTraversal(Node<T>* node, vector<T*> &vect) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->get_left(), vect);
        vect.push_back(node->get_data());
        inorderTraversal(node->get_right(), vect);
    }

    void findSmallest() {
       T* minValue = leftValue(root);
       minValue->print();
       cout << endl;
    }

    T* leftValue(Node<T>* node) {
        if (node->get_left() == nullptr) {
            return node->get_data();
        }
        return leftValue(node->get_left());
    }

    void findBiggest() {
        T* maxValue = rightValue(root);
        maxValue->print();
        cout << endl;
    }

    T* rightValue(Node<T>* node) {
        if (node->get_right() == nullptr) {
            return node->get_data();
        }
        return rightValue(node->get_right());
    }

    void sortAscending() {
        vector<T*> inorder;
        inorderTraversal(root, inorder);
        inorder[0]->print();
        for (int i = 1; i < inorder.size(); i++) {
            cout << ", ";
            inorder[i]->print();

        }
        cout << endl;
    }

    void sortDescending() {
        vector<T*> inorder;
        inorderTraversal(root, inorder);
        inorder[inorder.size() - 1]->print();
        for (int i = inorder.size() - 2; i >= 0; i--) {
            cout << ", ";
            inorder[i]->print();

        }
        cout << endl;
    }

    void set_root(Node<T>* root) {
        this->root = root;
    }
    void set_numelements(int elements) {
        numberOfElements = elements;
    }
    void set_height(int height) {
        this->root = height;
    }

    Node<T>* get_root() {
        return root;
    }
    int get_numelements() {
        return numberOfElements;
    }
    int get_height() {
        return height;
    }

};