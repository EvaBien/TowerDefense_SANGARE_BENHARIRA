#ifndef DEF_NODE
#define DEF_NODE


enum NodeType{
    OUT,
    IN,
    INTER,
    TWIST,
};

class Node{
    private:
    // Attributs
    Case m_case;
    TypeNode type;
    int *successors;
    Node *next;

    public:

    Node(); //constructeur
    ~Node();

    //////GETTERS/////
    Case getCase();
    TypeNode getType();
    int* getSuccessors();
    Node* getNext();

    //////SETTERS/////
    void setCase (Case c);
    void setType(TypeNode type);
    void setSuccessors(int *successors);
    void setNext(Node *node);
    //////OTHERS/////
};

class PathNode{

  private:
  int m_lenght;
  Node *head;
  Node *end;

  public :
  PathNode();
  ~PathNode();

  //////GETTERS/////
  int getLenght();
  Node* getHead();
  Node* getEnd();

  //////SETTERS/////
  void setLenght(int lenght);
  void setHead(Node* node);
  void setEnd(Node* node);

  //////OTHERS/////

  void addNode(NodeType type, Case c, int *successors);
  void deleteNode(Node *node);

}


#endif
