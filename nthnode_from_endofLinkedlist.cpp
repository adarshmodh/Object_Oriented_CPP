#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}



/*
 * Complete the 'find_nth_element' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER nthElement
 *  2. INTEGER_SINGLY_LINKED_LIST head
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

int find_nth_element(int nthElement, SinglyLinkedListNode* head) {
    /*
    Using 2 pointer approach, fast pointer moves ahead till n elements, then both move at the same speed till the fast reaches null. 
    The slow pointer will point to the nth element from the end. 
    */

    SinglyLinkedListNode* slow = head; 
    SinglyLinkedListNode* fast = head; 
    
    int output = -1;
    
    if (head!=NULL){
        int count = 0;
        while(count < nthElement){
            fast = fast->next;
            count++;
        }

        while(fast->next!= NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        output = slow->data;
    }
    
    return output;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nthElement_temp;
    getline(cin, nthElement_temp);

    int nthElement = stoi(ltrim(rtrim(nthElement_temp)));

    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    int result = find_nth_element(nthElement, head->head);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
