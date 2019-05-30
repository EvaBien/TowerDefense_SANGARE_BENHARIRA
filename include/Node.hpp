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
    float m_x;
    float m_y;
    TypeNode type;
    int *successors;
    Node *next;

    public:

    Node(); //constructeur
    ~Node();

    //////GETTERS/////
    float getX();
    float getY();
    TypeNode getType();
    int* getSuccessors();
    Node* getNext();

    //////SETTERS/////
    void setX(float x);
    void setY(float y);
    void setType(TypeNode type);
    void setSuccessors(*int successors);
    void setNext(*Node node);
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

  void addNode(NodeType type, float x, float y, int *successors);
  void deleteNode(Node *node);

}


#endif
