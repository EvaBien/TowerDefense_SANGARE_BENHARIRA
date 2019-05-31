#ifndef DEF_NODE
#define DEF_NODE

#include()
enum TypeNode{
    IN,
    OUT,
    TWIST,
    INTER,
};

class Node{
    private:
    // Attributs
    Case *m_case;
    TypeNode type;
    int successor;
    Node *next;
    int index;
    Map *map;

    public:

    Node(int type, float x, float y); //constructeur
    ~Node();

    //////GETTERS/////
    Case getCase();
    TypeNode getType();
    int getSuccessor();
    Node* getNext();

    //////SETTERS/////
    void setCase (Case *c);
    void setType(TypeNode type);
    void setSuccessor(int successor);
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
